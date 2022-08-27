// operaciones con estructuras 
//      comparacion

#include <stdio.h>
#include <string.h>

#define STR_NAME_LEN    20 

struct st_data {
    int id;
    char name[STR_NAME_LEN];
    int age;
    float height;
    float weight;     
};

typedef struct st_data ST_DATA;

// init struct
ST_DATA init_st_data ( int id, char* name, int age, float h, float w);

// show struct
void show_st_data (ST_DATA);

int compare_st_data( ST_DATA, ST_DATA);

int main(void){

    ST_DATA persona_1;
    ST_DATA persona_2;
    ST_DATA persona_3;
    

    persona_1 = init_st_data(1, "Juan", 46, 1.73, 70);
    persona_2 = persona_1;
    persona_3 = init_st_data(2, "Pedro", 18, 1.80, 75);

    if (compare_st_data( persona_1, persona_2) == 0)
        printf("persona_1 es igual a persona_2\n");
    else 
        printf("persona_1 es distinta a persona_2\n");

    if (compare_st_data( persona_1, persona_3) == 0)
        printf("persona_1 es igual a persona_3\n");
    else
        printf("persona_1 es distinta a persona_3\n");

  
    return 0;
}

ST_DATA init_st_data ( int id, char* name, int age, float h, float w){
    ST_DATA st_data_aux;

    st_data_aux.id = id;
    strcpy(st_data_aux.name, name);
    st_data_aux.age = age;
    st_data_aux.height = h;
    st_data_aux.weight = w;   

    return st_data_aux;

}

void show_st_data (ST_DATA people){
    
    //muestro el contenido de la estructura
    printf("Listado del contendo de la estructura:\n");
    printf("id: %d\n", people.id);
    printf("name: %s\n", people.name);
    printf("age: %d\n", people.age);
    printf("height: %f\n", people.height);
    printf("weight: %f\n", people.weight);

}

int compare_st_data( ST_DATA st1, ST_DATA st2){

    if ( st1.id != st2.id )
        return 1;

    if ( st1.age != st2.age )
        return 1;

    if ( strcmp(st1.name, st2.name) != 0 )
        return 1;

    if ( st1.height != st2.height )
        return 1;

    if ( st1.weight != st2.weight )
        return 1;

    return 0;
}
