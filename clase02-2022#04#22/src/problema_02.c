/*
 * Desarrollar un programa que permita determinar si un número 
 * es positivo o negativo.
 * 
 */

/*
 * Recordar que si se cambia el codigo fuente se tiene que volver a compilar
 */

#include <stdio.h>

int main (void) {

    int numero;  

    numero = -100;

    // lo que esta entre parentesis es la 'condicion') que se evalua
    // si es verdadera o falsa
    if (numero > 0){
         printf("El resultado %d es positivo.\n", numero);
    }
    else {
        printf("El resultado %d es negativo.\n", numero);
    }

    // y si tenemos en cuenta el caso especial del 0
    // varias formas de resolver, intenten otras....
    // ...
    numero = 0;
    if (numero == 0) {
         printf("El resultado %d es cero.\n", numero);
    } 
    else if (numero > 0){
         printf("El resultado %d es positivo.\n", numero);
    }
    else {
        printf("El resultado %d es negativo.\n", numero);
    }

    return 0;
}