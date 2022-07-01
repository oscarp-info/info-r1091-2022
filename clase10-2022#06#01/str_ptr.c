#include <stdio.h>

/*
 * declaracion de puntero a string con asignacion
 * son dos variables, el puntero y el string
 * tener en cuenta que el string es "read only"
 * */


int main(void){

    char *str = "Hola Mundo";

    printf("dir str = %p\n", &str);
    printf("dir Hola Mundo o contenido de str = %p\n", str);


    return 0;
}