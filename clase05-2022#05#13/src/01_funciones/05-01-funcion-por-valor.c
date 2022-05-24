/*
 * Calcula la Suma de Dos Numeros con una funcion por valor
 * 
 */
#include <stdio.h>

// prototipo
int SumaDos(int, int);

int main(void)
{
    int a;
    int b;
    int sum;

    a = 10;
    b = 5;

    sum = SumaDos(a, b);

    printf("La suma de a+b es: %d\n", sum);

    return 0;

}

int SumaDos(int x, int y){
    int z;

    z = x + y;

    return z;
}
