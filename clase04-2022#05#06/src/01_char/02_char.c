#include <stdio.h>

/*
 * Preguntas:
 *  que sucede cuando asignamos 300 a un char? 
 *  el compilador emite algun Warning? Compilar con -Wall
 *  Justifique el valor que toma la variable despues de asigar a char el valor 300
 */

int main(){

    char letra_01 = 'a';

    // Tamaño de una variable tipo char
    // operador sizeof()
    // es de 1 byte (8 bits), con lo cual los rangos son:
    // -128 a 127 
    // 0 a 255
    printf("El tamanio de un char es %u byte\n", sizeof(letra_01));

    // rango de un char
    // 300d = 100101100b
    // el bit mas significtivo se pierde porque supera el tamanio
    // entonces el valor finalmente almacenado es 
    // 00101100b = 44d
    letra_01 = 300;
    printf("El valor de la variable como ASCII es '%c'\n", letra_01);
    printf("El valor de la variable como entero es '%d'\n", letra_01);
    

    return 0;
}
