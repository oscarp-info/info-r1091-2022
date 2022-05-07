/*
 * Hacer un programa que calcule la suma de 'X' numeros
 * Los numeros deberan ingresarse por teclado
 * Se debera utilizar o for/while/do while 
 * Finalizar cuando se ingrese el valor 0
 * Si el usuario ingresa numeros negativos, continuar pero no considerarlos para la suma del total
 * 
 */

#include <stdio.h>

// valor de salida del "loop", cuando lo ingresa el usuario
#define FLAG    0

int main(){
    double numero;
    double suma_total = 0;
    int i;
   
    for(;;){
    
        printf("Ingrese un numero: ");
        scanf("%lf",&numero);

        if ( numero == FLAG){
            break;
        }
        if ( numero < 0){
            continue;
        }

        suma_total = suma_total + numero;
    }
    
    printf("La suma total es = %.2lf",suma_total);

    return 0;
}