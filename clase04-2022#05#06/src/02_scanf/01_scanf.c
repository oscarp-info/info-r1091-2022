/*
 * int scanf(const char *restrict format, ...);
 *  Ingreso por stdin(teclado), con formato y con eco por pantalla
 *  El ingreso finaliza con ENTER
 *  Devuelve la cantidad de "items" leidos correctamente o -1 en caso de error
 *
 *
 *  Preguntas:
 *      que suceda si no antemos el & al nombre de la variable dentro de scanf?
 *      que sucede si ingreso valores que no sean numeros?
 *      que significa '...'  en la definicion o prototipo de la funciona scanf?
 * 
 *      --- realizar "pruebas" de este codigo para poder responder las preguntas ---
 */


#include <stdio.h>

int main(){

    int entero;
    int resultado;

    printf("Ingrese un valor entero: ");
    resultado = scanf("%d", &entero);
    printf("\n");
    printf("El valor ingresado es: %d\n", entero);
    printf("El valor de retorno de scanf es: %d", resultado);


    return 0;
}
