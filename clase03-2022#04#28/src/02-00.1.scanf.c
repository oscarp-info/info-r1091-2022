#include <stdio.h>
#include <stdlib.h>


int main (void) {

	int numero;

	printf("ingrese el numero a verificar\n");
	scanf("%d", &numero);

	if (numero == 0)
	{
		printf("el numero es igual a 0");
		exit (0);
	}

	if (numero >=0)
	{
		printf ("el numero es positivo\n");
	}
	
	else
	{
		printf ("el numero es negativo\n");
	}
	
	return 0;
}
