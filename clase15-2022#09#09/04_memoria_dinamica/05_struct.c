// estructuras y memoria dinamica

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define STR_NAME_LEN    20 

struct st_data {
    int id;
    char name[STR_NAME_LEN];
    int age;
};

typedef struct st_data ST_DATA;


int main(void){
  
    ST_DATA people = { 1, "Carlos", 33 };

    ST_DATA *p;

    p = (ST_DATA *)malloc(sizeof(ST_DATA));
    if (p == NULL){
        printf("cannot allocate memory\n");
        return -1;
    }

    // asigno valor (copia)
    *p = people;
    
    // otra forma
    p->id = 1;
    strcpy(p->name, "Carlos");
    p->age = 33;

    //muestro el contenido de la estructura
    printf("Listado del contendo de la estructura:\n");
    printf("id: %d\n", p->id);
    printf("name: %s\n", p->name);
    printf("age: %d\n", p->age);
  
    // libero la memoria
    free(p);

    return 0;
}

