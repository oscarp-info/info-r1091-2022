/*
 * Hacer un programa que calcule la suma de 3 numeros
 * Los numeros deberan ingresarse por teclado
 * 
 */

#include <stdio.h>

int main(){
    double numero_a, numero_b, numero_c;
    double suma_total;

    printf("Ingrese un numero: ");
    scanf("%lf",&numero_a);

    printf("Ingrese un numero: ");
    scanf("%lf",&numero_b);
    
    printf("Ingrese un numero: ");
    scanf("%lf",&numero_c);

    // operador SUMA
    suma_total = numero_a + numero_b + numero_c;

    printf("La suma total es = %.2lf",suma_total);
    
    return 0;
}