#include <stdio.h>
#include <string.h>     // strlen

/*
 * scanf / printf
 */

int main(void){

    char nombre[20];
    
    printf("Ingrese su nombre: ");
    
    // no hace falfa & al nombre de la cadena ¿porque?
    // cuando finaliza la lectura scanf? whitespace
    // https://www.tutorialspoint.com/c_standard_library/c_function_isspace.htm
    scanf("%s", nombre);
    
    // %s para imprimir como 'cadena'
    printf("Su nombre es %s.\n", nombre);
    
    return 0;


}