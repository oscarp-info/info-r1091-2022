/*
 * Hacer un programa que calcule la suma de 3 numeros
 * Los numeros deberan ingresarse por teclado
 * Se debera utilizar o for/while/do while 
 */

#include <stdio.h>

#define MAX 3

int main(){
    double numero;
    double suma_total = 0;
    int i;
   
    for(i=0; i < MAX; ++i){
    
        printf("Ingrese un numero: ");
        scanf("%lf",&numero);

        suma_total = suma_total + numero;
    }
    
    printf("La suma total es = %.2lf",suma_total);

    return 0;
}