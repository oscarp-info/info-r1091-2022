/*
 * Desarrollar un programa que permita sumar dos números ingresados por 
 * teclado y muestre su resultado por pantalla
 *
 */

/*
 * para compilar, desde el directorio donde se encuentra nuestro archivo
 * de codigo fuente
 *  $ gcc problema_01.c
 * si no hay errores de compilacion, se genera el archivo ejecutable 'a.out'
 *  ### revisar con el comando ls -lrta los permisos de a.out (de ejecucion 'x')
 *
 * si quiero definir el nomre del archivo ejecutable (de salida)
 * $ gcc problema_01.c -o my_app
 * 
 */


#include <stdio.h>

int main (void) {

    // esto es un comentario de una linea

    /*
    Esto es un comentario multi-linea
    */

    // declaracion de variables (nombre y tipo)
    // todas las variables se tienen que declarar al principio de la funcion (convencion)
    // toda "sentencia" finaliza en ';' (punto y coma)
    // nombre de las variables (existen reglas para los nombres de las varianles!)
    int n1;  // int es del tipo entero (permite almacen numeros)
    int n2;
    int resultado;

    // otra forma de declarar mas de una variable en una misma linea
    // int n1, n2; 

    // cual es el valor incial de n1 y n2?
    // donde 'viven las variables'? primer acercamiento a "scope o alcance..."

    n1 = 10;    // el igual '=' es el operador de asignacion
    n1 = 5;     // el igual '=' es el operador de asignacion

    resultado = n1 + n2;   

    // donde esta el codigo de printf? primer acercmiento a librerias (libc en este caso)
    // que es stdio.h? porque es necesario incluir, primer acercamiento a funciones, achivos
    //      de cabecera y librerias...
    // que es %d?
    // man printf (ayuda)
    printf("El resultado es %d\n", resultado);

    return 0;
}