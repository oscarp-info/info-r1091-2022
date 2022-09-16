// estructuras anidadas

#include <stdio.h>
#include <string.h>

#define STR_NAME_LEN    20 

struct health {
        float height;
        float weight;
};

typedef struct health ST_HEALTH;

struct st_data {
    int id;
    char name[STR_NAME_LEN];
    int age;
    ST_HEALTH health;
};

typedef struct st_data ST_DATA;


int main(void){
  
    ST_DATA people = { 1, "Carlos", 33, { 1.75, 80 } };

    //muestro el contenido de la estructura
    printf("Listado del contendo de la estructura:\n");
    printf("id: %d\n", people.id);
    printf("name: %s\n", people.name);
    printf("age: %d\n", people.age);
    // muestro miembros de estructuras anidadas
    printf("height: %f\n", people.health.height);
    printf("weight: %f\n", people.health.weight);

    return 0;
}

