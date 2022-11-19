#include "sock-lib.h"

int main ()
{
	int sockfd; /* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */
	int sockdup; 

	if ((sockfd = Open_conection (&my_addr)) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}

	while(1)
	{
		sockdup = Aceptar_pedidos (sockfd);
// Aca se pone un fork () y se lo convierte en un server concurrente
// En tal caso, lo que sigue es el child process
// El padre vuelve a Aceptar_pedidos
		if (write (sockdup, message , sizeof (message)) == -1)
		{
			perror("Error escribiendo mensaje en socket");
			exit (1);
		}
		close(sockdup);
	}
	exit(0);
}
