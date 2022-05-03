/*
 * Errores tipos de nombres de variables
 * compilar: gcc 02-01.2-variables-int-errores.c -Wall 
 * 
 */
#include <stdio.h>

int main(void)
{
    // diferentes tipos de errores
    // los nombres de variables solo pueden empezar por letras y _ 
    // despues pueden tener numeros
    // para tener en cuenta que C es case sensitive (diferencia mayusculas de minusculas)   
    // no pueden ser palabras reservadas

    // el nombre de una variable no puede empesar con numeros
    int 1peso;
    
    // return es una palabra reservada
    int return;
   
  
    return 0;

} 