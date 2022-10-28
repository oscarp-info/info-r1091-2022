/*

Escribir un programa que calcule el bit de paridad de un byte entero que asegure
la paridad de los bits de toda la informacion de los bytes precedentes
Ej>
Se tiene 0110 0000, 0010 0000 y 1000 0110, el byte de paridad seria:  1100 0110

*/

#include <stdio.h>


unsigned char paridad (unsigned char * array, int tam)
{
	int i,j,cant;
	unsigned char resultado = 0,mask;
	for (j=0;j<8;j++)
	{
		cant =0;
		mask = 0x01 << j;
		for (i=0;i<tam;i++)
		{
			if (array [i] & mask)
				cant++;
		}
		if (cant %2)
			resultado = resultado | mask;
	}
	return resultado;
}

int main (void)
{
	unsigned char array [3] = {0x90,0xF0,0x87};
	printf ("el byte de paridad es: %X\n",paridad(array,3));



	return 0;
}
