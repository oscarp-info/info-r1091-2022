
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

// alias
typedef struct st_persona ST_PERSONA;

int main(void)
{

    int i;
    // struct persona p;
    ST_PERSONA p;

    int edad;

    // como accedo a los miembros?
    // operador: PUNTO "."
    p.edad = 48;               // entero
    p.genero = 'M';            // char
    strcpy(p.nombre, "oscar"); // string

    printf("nombre: %s\n", p.nombre);
    printf("edad: %d\n", p.edad);
    printf("genero: %c\n", p.genero);

    printf("sizeof = %d\n", sizeof(struct st_persona)); // 40
    printf("sizeof = %d\n", sizeof(p));                 // 40
    printf("sizeof = %d\n", sizeof(ST_PERSONA));        // 40

    edad = p.edad;

    return 0;
}