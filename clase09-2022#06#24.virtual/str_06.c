#include <stdio.h>
#include <string.h>     // strlen

void print_str(char *);

int main(void){

    int i;

    char cad[20] = "Hola Mundo";

    print_str(cad);
    
    return 0;

}


void print_str(char *ptr){
    puts(ptr);
}
