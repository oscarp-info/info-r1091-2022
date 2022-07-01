#include <stdio.h>
#include <string.h>     // strlen

/*
 * string y punters
 *
 */


int main(void){

    char str[] = "Hola Mundo";
    
    printf("%c\n", *str);

    printf("%c\n", *(str+3));

    printf("%s\n", str+3);

    // ERROR
    //printf("%s\n", *(str+3));

    return 0;

}


