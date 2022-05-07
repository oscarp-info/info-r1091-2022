/*
 * Leer un caracter del teclado
 * como char y como int
 * Luego imprimir con %c y %d
 * 
 */


/*
 * Prototipos de funciones predefinidas
 */
#include <stdio.h>

/*
 * Prototipos de funciones definidas por el usuario
 */
void vaciar_buffer_teclado(void);

int main(){

    char char_letra;
    int  int_letra;

    printf("Ingrese la primer letra de su nombre: ");
    scanf ("%c", &char_letra);

    vaciar_buffer_teclado();

    printf("Ingrese la primer letra de su nombre: ");
    scanf ("%c", &int_letra);

    printf("La primer letra ingresa es %c\n", char_letra);
    printf("La primer letra ingresa es %c\n", int_letra);


    return 0;
}

void vaciar_buffer_teclado(void){
    while(getchar()!='\n');
}