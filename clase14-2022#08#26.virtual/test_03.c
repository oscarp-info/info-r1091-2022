
// estructuras

#include <stdio.h>
#include <string.h>

// modelo de datos o tipo de variable o plantilla
struct st_persona
{
    // campos o miembros de la estructura
    char nombre[32]; // 32 bytes
    int edad;        // 4 bytes
    char genero;     // 1 bytes
    //  seguir definiendo campos...
};

struct st_persona_dos
{
    // campos o miembros de la estructura
    char nombre[32]; // 32 bytes
    int edad;        // 4 bytes
    char genero;     // 1 bytes
    //  seguir definiendo campos...
};

// alias
typedef struct st_persona ST_PERSONA;
typedef struct st_persona_dos ST_PERSONA_DOS;

ST_PERSONA init_st_persona(char *nombre, int edad, char genero);
void show_st_persona(ST_PERSONA p);

int compare_st_persona(ST_PERSONA p1, ST_PERSONA p2);
//  0 en el caso que sean iguales
// -1 en el caso que sean diferentes

// sumar +1 años campo edad
void cumple_persona(ST_PERSONA *);

void cumple_persona_2(int *p);

int main(void)
{
    ST_PERSONA persona; // 40
    ST_PERSONA *p;      // 8

    persona = init_st_persona("Juan", 18, 'M');
    p = &persona;

    // operador punto '.'
    // persona.edad = 18;
    // printf("edad=%d\n", persona.edad);

    // operador flecha
    // persona.edad = 18;
    // p->edad = 20;

    cumple_persona(&persona); // puntero a str ST.....
    printf("edad=%d\n", persona.edad);

    cumple_persona(&persona.edad); // puntero a int

    // show_st_persona(p);

    return 0;
}

ST_PERSONA init_st_persona(char *nombre, int edad, char genero)
{
    ST_PERSONA aux;

    aux.edad = edad;
    aux.genero = genero;
    strcpy(aux.nombre, nombre);

    return aux;
}

void show_st_persona(ST_PERSONA p)
{
    printf("nombre: %s\n", p.nombre);
    printf("edad: %d\n", p.edad);
    printf("genero: %c\n", p.genero);
}

void cumple_persona(ST_PERSONA *p)
{
    p->edad = p->edad + 1;
}

void cumple_persona(int *p)
{
    *p = *p + 1;
}