// estructuras y typedef

#include <stdio.h>
#include <string.h>

#define STR_NAME_LEN    20 

// declaracion de una estructura: plantilla
// no consume "memoria"
struct st_data {
    // fields o members
    int id;
    char name[STR_NAME_LEN];
    int age;
    float height;
    float weight;     
};

// "nuevo" tipo de dato
// en general se utiliza mayusculas
typedef struct st_data ST_DATA;

int main(void){

    //declaracion de una variable de un tipo de estructura
    //zona continua de memoria para todos sus miembros
    //struct st_data people;
    ST_DATA people;

    //que tamaño tiene? => 4 + 20 + 4 + 4 + 4 = 36 
    printf("El tamaño de la estructura st_data es %zu bytes\n", sizeof(struct st_data));
    
    //como accedo a los miembros de la estructura?
    people.id = 1;
    strcpy(people.name, "Juan");
    people.age = 46;
    people.height = 1.73;
    people.weight = 70;    

    //muestro el contenido de la estructura
    printf("Listado del contendo de la estructura:\n");
    printf("id: %d\n", people.id);
    printf("name: %s\n", people.name);
    printf("age: %d\n", people.age);
    printf("height: %f\n", people.height);
    printf("weight: %f\n", people.weight);

    return 0;
}
