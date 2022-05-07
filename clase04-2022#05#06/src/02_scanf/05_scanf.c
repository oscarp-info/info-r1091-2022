/*
 * Leer con formato
 * 
 * Tener en cuenta que la flexibilidad del scanf tiene en contraposicion
 * la facilidad de cometer errores
 * 
 */


/*
 * Prototipos de funciones predefinidas
 */
#include <stdio.h>

/*
 * Prototipos de funciones definidas por el usuario
 */

int main(){

    unsigned int dia, mes, anio;
    float temperatura;

    // TEMP 23-04-2021 20.3     ==> OK
    // TEMP 23-04/2021 20.3     ==> ERROR
    // hacer un copy & paste en la terminal
    // el primer parametro del scanf define como espera recibir el texto ingresado por teclado
    scanf("TEMP %u-%u-%u %f", &dia, &mes, &anio, &temperatura);
    printf("El dia %u-%u-%u se registro una temperatura de %f grados Celcius\n", dia, mes, anio, temperatura);
    
    return 0;
}

