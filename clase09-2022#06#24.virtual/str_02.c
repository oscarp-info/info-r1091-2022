#include <stdio.h>
#include <string.h>     // strlen

/*
 * $ man strlen
 */

int main(void){

    // declaracion e inicializacion de un string
    char cad[20] = "hola";
    
    // tamaño del array vs tamaño del string
    printf("El tamaño del array es: %ld", sizeof(cad));
    printf("El tamaño del string es: %ld", strlen(cad));


}