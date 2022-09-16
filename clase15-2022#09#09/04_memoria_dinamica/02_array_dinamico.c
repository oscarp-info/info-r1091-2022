#include <stdio.h>
#include <stdlib.h> //malloc

#define ARR_SIZE    10

void array_init_int ( int *, int value, int size);
void array_list_int ( int *, int size);


int main(){

    // array estatico
    int array_int[ARR_SIZE];

    array_init_int(array_int, 3, ARR_SIZE);
    array_list_int(array_int, ARR_SIZE);

    // array dinamico
    int *p = NULL;
    p = (int *)malloc(sizeof(int)*ARR_SIZE);
    if ( p == NULL){
        printf("Error en malloc\n");
        exit(-1);
    }
    array_init_int(p, 5, ARR_SIZE);
    array_list_int(p, ARR_SIZE);
    
    // liberar memoria
    free(p);

}


void array_init_int ( int *arr, int arr_value, int arr_size){

    int i=0;

    for (i=0; i<arr_size;i++){
        arr[i] = arr_value;
    }
    
}

void array_list_int ( int *arr, int arr_size){

    int i=0;

    for (i=0; i<arr_size;i++){
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    
}

