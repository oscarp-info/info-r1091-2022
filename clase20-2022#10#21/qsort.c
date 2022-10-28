#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define TAM 2000
#define MAX 100000
#define BASE 0

/*

ejecutar con time adelante
time ./qsort
time ./burbuja

comparar resultados


*/

int comparar (int*,int*);
void swap (int*,int*);


int main (void)
{
	
	int array [TAM];
	int i,j;
	srand (getpid());
	for (i=0;i<TAM;i++)
		array [i]= rand () % MAX + BASE;

	printf ("\n\n");
	//muestro el array
	for (i=0;i<TAM;i++)
		printf("%d ", array [i]);

	//ordeno
	/* BURBUJA
	for (i=0;i<(TAM-1);i++)
		for (j=i;j<TAM;j++)
			if(comparar (&array [i],&array[j]))
				swap (&array [i] , &array [j]);
	
	
	*/
	
	//QSORT
	qsort (array,TAM,sizeof(int),comparar);
	



	printf ("\n\n");
	//muestro el array
	for (i=0;i<TAM;i++)
		printf("%d ", array [i]);












	return 0;
}
void swap (int *a, int*b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int comparar (int *a,int *b)
{
	return *a<*b;
}
