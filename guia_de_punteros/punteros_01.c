#include <stdio.h>

int main(void)
{
    int entero;
    char caracter;
    float real;

    entero = 8;
    caracter = 'A';
    real = 2.55;

    printf("La variable entero es igual a %d y ocupa %lld bytes en memoria\n", entero, sizeof(entero));
    printf("La variable caracter es igual a %c y ocupa %lld byte en memoria\n", caracter, sizeof(caracter));
    printf("La variable real es igual a %f y ocupa %lld bytes en memoria\n", real, sizeof(real));

    return 0;
}