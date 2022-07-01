#include <stdio.h>
#include <string.h>     // strlen

/*
 * my_strlen
 *
 */

int my_strlen (const char *s1);

int main(void){

    char str[] = "Hola Mundo";
    
  
    return 0;

}


int my_strlen (const char *s1){
    int i=0;
	while (s1[i] != 0)
		i++;
	
    return i;
}


