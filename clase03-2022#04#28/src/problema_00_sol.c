/*
 * Desarrollar programa que permita calcular la edad aprox. 
 * De una persona. Para ello es necesario conocer el año actual en curso, 
 * junto con el año de nacimiento de dicha persona y restarlos. 
 * Considere validar que el año de nacimiento esté entre 1900 y 2017, 
 * mientras que el año actual se entiende que es 2022. 
 * Al terminar imprima el resultado obtenido
 * 
 */
 
 
 
 #include <stdio.h>
 
 int main (void)
 {
 	int anio = 2022;
 	int nacimiento;
 	int edad=0;
 	
	printf("ingrese el anio de nacimiento\n");
 	scanf ("%d",&nacimiento);
 	if (nacimiento > 1900)
 	{
 		if (nacimiento <2017)
 		{
 			edad = anio - nacimiento; 		
 		}
 	}
 	
 	if (edad)
 	{
 		printf("la edad es %d\n",edad);
 	} 
 	else
 	{
 		printf("el anio ingresado no es valido\n");
 	}
 	
 	return 0;
 }
