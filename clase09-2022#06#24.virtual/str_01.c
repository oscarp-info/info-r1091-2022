#include <stdio.h>

int main(void){

    // string en "C"
    // es un array de caracteres con el ultimo elemento con el valor '\0' (null character)
    
    // declaracion de un string: array de caracteres
    char cad[20];	

    // declaracion e inicializacion de un string
    char cad[] = {'h','o','l', 'a', '\0'};
    
    // declaracion e inicializacion de un string
    char cad[20] = "hola";
    
    // El '\0' se agrega auto y el tamaño del array se calcula en tiempo de compilacion
    char cad[] = "hola";			
}