// estructuras anidadas y memoria dinamica

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
    ST_HEALTH *health;
};

typedef struct st_data ST_DATA;


int main(void){
  
    ST_DATA *people;

    people = (ST_DATA *)malloc(sizeof(ST_DATA));
    if (people == NULL){
        printf("cannot allocate memory\n");
        return -1;
    }

    people->health = (ST_HEALTH*)malloc(sizeof(ST_HEALTH));
    if (people->health == NULL){
        printf("cannot allocate memory\n");
        return -1;
    }

    // populate struct
    people->id = 1;
    strcpy(people->name, "Santi");
    people->age = 10;
    people->health->height = 1.36;
    people->health->weight = 39.5;
    
    //show struct
    printf("Listado del contendo de la estructura:\n");
    printf("id: %d\n", people->id);
    printf("name: %s\n", people->name);
    printf("age: %d\n", people->age);
    printf("height: %f\n", people->health->height);
    printf("weight: %f\n", people->health->weight);
    
     
    // libero la memoria, cuidado con el orden!
    free(people->health);
    free(people);

    return 0;
}

