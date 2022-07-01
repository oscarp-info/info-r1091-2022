#include <stdio.h>
#include <string.h>     // strlen


int main(void){

    int i;

    char cad[20] = "Hola Mundo";

    for (i=0; i<strlen(cad); i++){
        printf("cad[%d] = '%c'\n", i, cad[i]);
    }
    printf("\n");
    
    for (i=0; cad[i] !='\0'; i++){
        printf("cad[%d] = '%c'\n", i, cad[i]);
    }
    printf("\n");

    i = 0;
    while(cad[i] != 0 ){
        printf("cad[%d] = '%c'\n", i, cad[i]);
        i++;
    }
    printf("\n");


    return 0;

}

