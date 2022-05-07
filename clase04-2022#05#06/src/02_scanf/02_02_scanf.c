#include <stdio.h>

/*
 * Realizar pruebas ingresando valores de una manera que no esta esperada y ver 
 * que sucede
 *  --- Tener en cuenta que scanf al encontrar un error, termina en ese punto ---
 *  --- con lo cual los valores en las variables no son confiables en ese caso de error ---
 */

int main(){

    int edad;
    float peso;
    int resultado;

    printf("Ingrese su edad y su peso [edad-peso]: ");
    
    // espera que se ingrese con el siguiente formato 46-64.5 
    // es decir los valor separados por '-'
    resultado = scanf("%d-%f", &edad, &peso);
 
    printf("\n");
    printf("Su edad es: %d y su peso es %f\n", edad, peso);
    printf("El valor de retorno de scanf es: %d", resultado);

   
    return 0;
}
