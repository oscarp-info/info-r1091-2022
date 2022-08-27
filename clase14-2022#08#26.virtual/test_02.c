
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

int main(void)
{
    // struct persona p;
    ST_PERSONA p;
    ST_PERSONA q;
    int r;

    p = init_st_persona("Juan", 18, 'M');
    show_st_persona(p);
    q = p;
    show_st_persona(q);

    r = compare_st_persona(q, p);
    if (r == 0)
    {
        printf("Iguales");
    }
    else
    {
        printf("distintas");
    }

    p = init_st_persona("Juan", 22, 'M');
    r = compare_st_persona(q, p);
    if (r == 0)
    {
        printf("Iguales");
    }
    else
    {
        printf("distintas");
    }

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