/*
 * Tabla ASCII:
 * 	Numeros		48...57
 * 	Mayusculas 	65...90
 * 	Minusculas 	97...122
 */
#include <stdio.h>


int main(void){

	int i;

	int start = 65;
	int end = 90;
	
	printf("Despliega la tabla de codigo ascii\n");
	printf("Decimal       Caracter");
	
	for ( i = start; i <= end ; i ++){
   		printf("\n%d     -      %c",i,i);
 	}

	return 0;
}
