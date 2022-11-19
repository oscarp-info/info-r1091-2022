/** \file sock-lib.c
 * \brief Contiene las funciones simplificadas de manejo de sockets para usar en Informática I
 * \author Alejandro Furfaro
 * \date 2018.09.10
 */

#include "sock-lib.h"

/**
 * \fn int conectar (int argc, char * argv[])  
 * \brief Única función del lado cliente, que crea un socket y conecta a un server que le llega como argumento.
 * \details Se crea un socket y luego se invoca a la función connect para iniciar conexión con el nodo remoto en el 
 * cual debe estar ejecutando un programa servidor escuchando conexiones por el mismo port al ue inicia la conexión.
 * La dirección o nombre de host al que conectar se recibe en el primer elemento del arreglo de strings que recibe como segundo argumento.
 * El port puede venir como cadena ASCIIZ en el segundo elemento del arreglo de strings que recibe como segundo argumento. Si no recibe 
 * un número de port utilizará el port 3490 definido en el header
 * \arg[in] argc contiene la cantidad de elementos del arreglo de punteros a char del segundo argumento
 * \arg[in] argv es un arreglo de punteros a char. El primer elemento es obligatorio y es el nombre o ip del host. El segundo es opcional 
 * y es el número de port.
 * return Devuelve un entero con el file descriptor de socket
 * \author Alejandro Furfaro
 * \date 2018.09.10
 */
int conectar (int argc, char * argv[])
{

	int	sockfd;
	struct hostent *he;	/* Se utiliza para convertir el nombre del host a su dirección IP */
	struct sockaddr_in their_addr;  /* dirección del server donde se conectará */

	/* Convertimos el nombre del host a su dirección IP */
	if ((he = gethostbyname ((const char *) argv[1])) == NULL)
	{
		herror("Error en Nombre de Host");
		exit(1);
	}
 
/* Creamos el socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error en creación de socket");
		exit(1);
	}

/* Establecemos their_addr con la direccion del server */
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = (argc == 2)? htons(PORT):htons(atoi(argv[2]));
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

/* Intentamos conectarnos con el servidor */
	if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Error tratando de conectar al server");
		exit(1);
	}
	return sockfd;
}

/**
 * \fn int Open_conection ( struct sockaddr_in * my_addr)  
 * \brief Primer función del lado server, que crea un socket lo enlaza con un número de port que es el definido en el header de la 
 * biblioteca, el  3490, y define cuntos buffers de conexiones armacenará durante la aceptación de al conexión, y pasa a escuchar.
 * \details Se crea un socket y luego se invoca a la función bind para indicarle al SIstema Operativo por que port escuchará conexiones.
 * Utilizará la ip default invocando a una macro definida en la biblioteca de sockets del sistema operativo. A posteriori se pondrá a escuchar 
 * conexiones por el port declarado al Sistema Operativo, definiendo previamente la cantidad de pedidos de conexión remotos que buffereará 
 * mientras eventualmente esté iniciando el intercambio con el cliente que pide inicio de una conexión 
 * \arg[in] puntero a estrictura sockaddr_in que completará antes de invocar a bind () con el número de port y la ip por la que escuchará 
 * conexiones a través del sockeet.
 * return Devuelve un entero con el file descriptor de socket
 * \author Alejandro Furfaro
 * \date 2018.09.10
 */

int Open_conection ( struct sockaddr_in * my_addr)
{
	int	sockaux;	/*socket auxiliar*/
	int	aux; 		/*variable auxiliar*/

	/*Crea un socket y verifica si hubo algún error*/
	if ((sockaux = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{
		fprintf(stderr, "Error en función socket. Código de error %s\n", strerror(sockaux));
		return -1;
	}

/* Asignamos valores a la estructura my_addr */

	my_addr->sin_family = AF_INET;		/*familia de sockets INET para UNIX*/
	my_addr->sin_port = htons(PORT);	/*convierte el entero formato PC a
						entero formato network*/
	my_addr->sin_addr.s_addr = INADDR_ANY;	/* automaticamente usa la IP local */
	bzero(&(my_addr->sin_zero), 8);		/* rellena con ceros el resto de la
						 estructura */

	/* Con la estructura sockaddr_in completa, se declara en el Sistema que este proceso escuchará pedidos por la IP y el port definidos*/
	if ( (aux = bind (sockaux, (struct sockaddr *) my_addr, sizeof(struct sockaddr))) == -1)
	{
		fprintf(stderr, "Error en función bind. Código de error %s\n", strerror(aux));
		return -1;
	}
	/* Habilitamos el socket para recibir conexiones, con una cola de conexiones en espera que tendrá como máximo el tamaño especificado en BACKLOG*/
	if ((aux = listen (sockaux, BACKLOG)) == -1)
	{
		fprintf(stderr, "Error en función listen. Código de error %s\n", strerror(aux));
		return -1;
        }
	return sockaux;
}

/**
 * int Aceptar_pedidos (int sockfd)  
 * \brief Una vez recibido el pedido de conexión, esta función establece la conexión con el extremo remoto.
 * \details Cuando se recibe el pedido de conexión desde el extremo remoto al que se espera en segundo plano mediante la función listen (), 
 * se recibe de dicha función el avviso para llamar a accept (). Ests función tiene  por objeto completar la conexión. Durante ese lapso se 
 * ejecuta con el cliente reomoto un intercambio de paquetes de control que permiten establecer la conexión de manera confiable y segura.
 * El procecso estará en estado Sleeped hasta que termine esta actividad. Al terminar la función devolverá un  duplicado del socket para 
 * ser utilizado en el intercambio de información con el extremo remoto, mientras si se lo desea, al mismmo tiempo se vuelva a escuchar 
 * pedidos de conexión por el socket original.   
 * \arg[in] sockeet originalmente creado por el que se recibió el pedido de conexión.
 * return Devuelve un entero con el file descriptor de socket duplicado para intercambio de datos
 * \author Alejandro Furfaro
 * \date 2018.09.10
 */

int Aceptar_pedidos (int sockfd)
{
	int newfd; 	/* Por este socket duplicado del inicial se transaccionará*/
        struct sockaddr_in their_addr;  /* Contendra la direccion IP y número de puerto del cliente */
	unsigned int sin_size = sizeof(struct sockaddr_in);

	/*Se espera por conexiones ,*/
	if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
	{
		fprintf(stderr, "Error en función accept. Código de error %s\n", strerror(newfd));
		return -1;
	}
	else
	{
		printf  ("server:  conexión desde:  %s\n", inet_ntoa(their_addr.sin_addr));
		return newfd;
	}
}
