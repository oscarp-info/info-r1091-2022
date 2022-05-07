#include <stdio.h>

int main(){

    int n = 10;
    int cont = 0;
    int err = 0;
    int a = 0;

    /*
     * Se incrementa cont solo si n es mayor a 7.
     * Al no existir una instrucción en caso de condición falsa, la misma se omite.
     * Al ser solo una sentencia, no se requieren los {}.
     */
    if ( n>7 )
        cont++;

    /*
     * Se incrementa cont solo si n es mayor a 7.
     * Caso contrario se pone cont a cero e incrementa err.
     * Como en caso de la condición falsa, se deben ejecutar 
     * más de una instrucción se requieren los {}.
     */
    if ( n>7 )
        cont++;
    else {
        cont=0;
        err++;
    }

    /*
    * if anidados – un condicional dentro de otro.
    * El primer if requiere los {} ya posee dos instrucciones, 
    * el incremento de cont y el if.
    * La sentencia err=0; se ejecutará solo sí (n>7) y luego (cont>10).
    */
    if ( n>7 ) {
        cont++;
        if ( cont>10 )
            err=0;
    }

    /*
     * Entonces, ¿a que if está asociado el else?
     * Si bien no es necesario, es recomendable incluir los {} para 
     * facilitar la lectura del código.
     * Nótese que la identación no modifica el código.
     * ¿Como sería el código si quisiéramos que la asociación fuese distinta?
     */
    a=3;
    if ( n>7 ) {
        if ( cont>10 )
            a=0;
        else
            a=5;
    }
    printf ("%d",a);


}

