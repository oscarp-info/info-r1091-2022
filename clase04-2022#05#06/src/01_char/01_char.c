#include <stdio.h>

/*
 * Preguntas:
 *  que sucede cuando asignamos un caracter a una variable char? que dato se guarda en la variable?
 *  quien realiza esa conversion?
 * 
 * Ref:
 * https://elcodigoascii.com.ar/
 *
 * 
 */

int main(){

    char letra_01 = 'a';
    char letra_02 = 97;
    int dif = 0;

    // Comparamos los dos caracteres para saber si son iguales
    // utilizamos el "operador arimetico RESTA -"
	dif = letra_01 - letra_02;
    printf("La diferencia es %d\n", dif);


    return 0;
}
