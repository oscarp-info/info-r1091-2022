#include <stdio.h>
#include <stdlib.h>

// resumen:
// funciones de memoria dinamica
// solicitar:   malloc(), verificar el resultado que no sea NULL, tener en cuenta el cast
// liberar:     free()
// heap:        zona de memoria
// prototipo:   stdlib.h


#define ARR_MAX 5

#define OK       1
#define ERROR   -1

void array_init( int *, int value, int size);
void array_list(int *, int size);
int array_create( int **arr, int size);


int main(){

    int r;
    int *pi=NULL;

    r = array_create( &pi, 10);
    if ( r == ERROR){
        printf("Error en array_create\n");
        exit(-1);
    }

    array_list(pi, 10);
    array_init(pi, 1, 10);
    array_list(pi, 10);
    
    // liberar memoria
    free(pi);

    return 0;


}


void array_init( int *arr, int value, int arr_size){
    int i=0;

    for (i=0;i<arr_size;i++)
        arr[i] = value;
    
}

void array_list(int *arr, int arr_size){
    int i=0;

    for (i=0;i<arr_size;i++)
        printf("arr[%d]=%d\n", i, arr[i]);

}


int array_create( int **arr, int arr_size){

    // concepto de puntero a puntero  

    *arr = (int *)malloc(sizeof(int)*arr_size);
    if ( *arr == NULL){
        printf("Error malloc\n");
        return ERROR;
    }
    return OK;

}
