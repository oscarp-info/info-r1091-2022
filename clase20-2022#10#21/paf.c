#include <stdio.h>

int (*calculadora) (int,int);

int suma (int,int);
int cociente (int,int);
int producto (int,int);
int resta (int,int);


int main (void)
{

	int a = 10, b = 2, resultado;
	calculadora = suma;
	resultado = calculadora (a,b);	
	printf ("\nla suma es: %d\n",resultado);


	calculadora = resta;
	resultado = calculadora (a,b);	
	printf ("\nla resta es: %d\n",resultado);

	calculadora = cociente;
	resultado = calculadora (a,b);	
	printf ("\nel cociente es: %d\n",resultado);

	calculadora = producto;
	resultado = calculadora (a,b);	
	printf ("\nel producto es: %d\n",resultado);





return 0;
}



