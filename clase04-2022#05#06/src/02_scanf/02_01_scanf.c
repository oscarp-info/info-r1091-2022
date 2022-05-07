#include <stdio.h>

int main(){

    int edad;
    float peso;
    int resultado;

    printf("Ingrese su edad y su peso [edad peso]: ");
    resultado = scanf("%d %f", &edad, &peso);
    printf("\n");
    
    // Imprime en el orden correcto
    printf("Su edad es: %d y su peso es %f\n", edad, peso);
    printf("El valor de retorno de scanf es: %d", resultado);

    printf("\n");
    
     // Imprime en el orden incorrecto, revisar Warnings del proceso de compilacion
    printf("Su edad es: %d y su peso es %f\n", peso, edad);
    printf("El valor de retorno de scanf es: %d", resultado);


    return 0;
}
