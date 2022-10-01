#include <stdio.h>

/*
 * a) leer y escribir una estructura PERSONA en un archivo
 * b) leer y escribir un array de estructuras PERSONA en un archivo
 * c) leer y escribir un array de punteros a estructuras PERSONA. El array con memoria dinamica
 * d) hacer un menu con las siguientes opciones: 1) cargar, 2) buscar por nombre, 3) buscar por id. cuando el programa inicia carga la informacion desde el archivo
 * e) modificar el programa anterior para que la base de datos este ordena siempre por id. cuando se carque un nuevo elemento se inserte ordenado 
 * f) modificar la funciona de buscar por id para que sea eficiente con la premisa que la base de datos esta ordenada ( fseek )
 * g) implementar funcionar que modifica un registro por id
 */

// la estructura no tiene campos dinamicos
struct persona {
    int id; // unico y consecutivo!
    char nombre[STR_NAME_LEN];
    int edad;
    float altura;
    float peso;
};


typedef struct persona PERSONA;

int main(){

    PERSONA p = { "Juan", 12, 1.40, 40};
    PERSONA q;

    escribir( p, fp);
    leer(fp, 1);
    imprimir( q );

    return 0;

}

