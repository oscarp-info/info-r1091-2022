// array de estructuras
//  declarar e inicializar conjuntamente
//  acceso a los elementos del array ( que son estructuras )

#include <stdio.h>
#include <string.h>

#define STR_NAME_LEN    20 
#define ARR_ST_LEN      3 

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
void show_st_data_ptr (ST_DATA*);

int compare_st_data( ST_DATA, ST_DATA);

// string to uppercase
void str_to_upper(char* string);


int main(void){

    ST_DATA arr_personas[ARR_ST_LEN] = {
        {1, "Juan",  20, 1.50, 50},
        {2, "Pedro", 21, 1.60, 60},
        {3, "Carlos",22, 1.70, 70}
    };

    int i=0;

    for (i=0;i<ARR_ST_LEN;i++){
        //podemos utilizar cualquiera de las dos funciones
        //por valor o referencia
        
        //show_st_data(arr_personas[i]);
        show_st_data_ptr(&arr_personas[i]);
    }


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


void show_st_data_ptr (ST_DATA* people){
    
    //muestro el contenido de la estructura
    printf("Listado del contendo de la estructura:\n");
    printf("id: %d\n", people->id);
    printf("name: %s\n", people->name);
    printf("age: %d\n", people->age);
    printf("height: %f\n", people->height);
    printf("weight: %f\n", people->weight);

}
