// punteros a estructuras y funciones
// pasar un miembro como referencia, funcion que convierte a mayusculas

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

// string to uppercase
void str_to_upper(char* string);


int main(void){

    ST_DATA persona_1, persona_2;
    struct st_data *p1;
    ST_DATA *p2;

    persona_1 = init_st_data(1, "Juan", 46, 1.73, 70);
    persona_2 = init_st_data(1, "pedro", 36, 1.4, 10);

    p1 = &persona_1;
    p2 = &persona_2;

    //forma 1
    str_to_upper(persona_1.name);
    
    //forma 2
    str_to_upper(p2->name);
    

    // notacion "flecha"
    printf("Listado(1) del contendo de la estructura accediendo como puntero:\n");
    printf("id: %d\n", p1->id);
    printf("name: %s\n", p1->name);
    printf("age: %d\n", p1->age);
    printf("height: %f\n", p1->height);
    printf("weight: %f\n", p1->weight);

    // acceso a un miembro con "flecha" y asignarle un valor
    p1->id = 2;


    // notacion "puntero"
    printf("Listado(2) del contendo de la estructura accediendo como puntero:\n");
    printf("id: %d\n", (*p2).id);
    printf("name: %s\n", (*p2).name);
    printf("age: %d\n", (*p2).age);
    printf("height: %f\n", (*p2).height);
    printf("weight: %f\n", (*p2).weight);




 
  
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

void str_to_upper(char* string)
{
    const char OFFSET = 'a' - 'A';
    while (*string)
    {
        *string = (*string >= 'a' && *string <= 'z') ? *string -= OFFSET : *string;
        string++;
    }
}


