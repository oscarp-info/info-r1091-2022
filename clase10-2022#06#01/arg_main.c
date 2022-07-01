#include <stdio.h>

/*
 * agrv es un array de punteros
 *  los punteros apuntan a un string read-write
 * argc es un entero
 * 
 * */

int main (int argc, char *argv[]){
    int i;
    
    printf ("Cantidad de argumentos pasados: %d\n",argc);
    
    // notacion array
    for (i= 0; i < argc; i++){
        printf ("El argumento %d vale: %s\n",i, argv[i]);
    }

    // notacion puntero. cuanto se desplaza argv + i ?
    for (i= 0; i < argc; i++){
        printf ("El argumento %d vale: %s\n",i, *(argv+i));
    }

    return 0;   
}