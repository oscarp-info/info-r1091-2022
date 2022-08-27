// funciones con estructuras: 
//      por valor
//      retorno de una estructura
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


int main(void){

    ST_DATA people;

    people = init_st_data(2, "Juan", 46, 1.73, 70);

    show_st_data( people);

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