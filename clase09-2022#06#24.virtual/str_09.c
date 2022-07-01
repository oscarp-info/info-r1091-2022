#include <stdio.h>
#include <string.h>     // strlen

/*
 *  Desarrollar una funciona con el siguiente prototipo:
 *      void str_upper_case(char *);
 *
 */
void str_upper_case_v1(char *);
void str_upper_case_v2(char *);

int main(void){
	char str_v1[100] = "Bienvenidos a Info v1";
    char str_v2[100] = "Bienvenidos a Info v2";

    str_upper_case_v1 (str_v1);
    puts(str_v1);
    str_upper_case_v2 (str_v2);
    puts(str_v2);

   
    return 0;
}


void str_upper_case_v1(char *s){
    while ( *s != 0){
        if ( *s >= 97 && *s<= 122){
            *s = *s -32;
        }
        s++;
    }
}

void str_upper_case_v2(char *s){
    
    int i = 0;

    while ( *(s+i) != 0){
        if ( *(s+i) >= 97 && *(s+i)<= 122){
            *(s+i) = *(s+i) -32;
        }
        i++;
    }
}





