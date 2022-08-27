/*
 * Estructura:
 * Es una coleccion de variables de diverso tipo agrupadas bajo
 * una misma entidad y bajo un nombre para un manejo mas
 * conveniente.
 * Permiten agrupar una cantidad de datos
 * considerable de modo de manejar el conjunto como una
 * entidad unica, y a la vez, de ser necesario, poder manejar cada
 * dato por separado tambien.
 */
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

int main(void){

    //declaracion de una variable de un tipo de estructura
    // como cuando se declara cualquier variable de tipo simple, se reserva memoria
    //zona continua de memoria para todos sus miembros
    struct st_data people;

    //que tamaño tiene? => 4 + 20 + 4 + 4 + 4 = 36 
    printf("El tamaño de la estructura st_data es %zu bytes\n", sizeof(struct st_data));
    
    //como accedo a los miembros de la estructura?
    //se utiliza el operador .
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
