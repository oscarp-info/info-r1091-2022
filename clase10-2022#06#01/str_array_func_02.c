#include <stdio.h>
#include <string.h>

#define ARR_SIZE    3
#define STR_LEN     20

void arr_str_to_print(char **p, int);

int main(void){
    // ojo que los string son read-only "ro"
    char *arr_1[ARR_SIZE] = {
        "Juan",
        "Carlos",
        "Pedro"
    };

    char *arr_4[] = {
        "Juan 4",
        "Carlos 4",
        "Pedro 4"
    };


    arr_str_to_print(arr_1, ARR_SIZE);
    arr_str_to_print(arr_4, ARR_SIZE);

    return 0;
}

void arr_str_to_print(char **ptr, int size){
    int i=0;
    
    for(i=0;i<size;i++){
        printf("string [%d] : %s\n",i,ptr[i]);
    }

}

