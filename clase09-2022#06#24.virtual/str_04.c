#include <stdio.h>
#include <string.h>     // strlen

/*
 * fgets / puts
 */


/*
 * stdin
 * https://www.tutorialspoint.com/cprogramming/c_input_output.htm
 *  Integer value   Name
 *      0        Standard input (stdin)         teclado      
 *      1        Standard output (stdout)       pantalla
 *      2        Standard error (stderr)        pantalla
 */


int main(void){

    char nombre[20];
    
    printf("Ingrese su nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    puts(nombre);
    
    return 0;

}