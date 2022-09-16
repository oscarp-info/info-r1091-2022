#include <stdio.h>
#include <stdlib.h> //malloc


int main(){

    // variable simple, imprimo el valor
     int x;
    x = 10;
    printf("El valor de x es %d\n", x);

    // imprimo el valor con punteros
    int *px;
    px = &x;
    printf("El valor de x es %d\n", *px);

    // creo una variable en tiempo de ejecucion
    int *py;
    py = (int *)malloc(sizeof(int));
    if ( py == NULL){
        printf("Error en malloc\n");
        exit(-1);
    }

    *py = 90;
    printf("El valor apuntado por py es %d\n", *py);

    // liberar la memoria
    free(py);

    return 0;

}