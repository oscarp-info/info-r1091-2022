/*
 * Desarrollar programa que permita pedir por pantalla el costo neto de un producto, 
 * calcule el iva (21% * neto) y luego determine el total (neto + iva). 
 * Valide que el costo neto sea mayor o igual que $10.000. 
 * Imprima todos los valores
 *
 */
 
 
 #include <stdio.h>
 
 int main (void)
 {
 	int neto;
 	float iva;
 	float total;
 	
 	printf("ingrese el monto neto\n");
 	scanf("%d",&neto);
 	
 	if(neto >= 10000)
 	{
 		iva = neto * 0.21;
 		total = neto + iva;
 		printf(" neto:%d\n iva:%.2f\n total:%.2f\n",neto,iva,total);
 	}
 	else
 	{
 		printf("el monto ingresado no es suficiente\n");
 	}
 
 	return 0;
 }
