#include <stdio.h>

int main()
{

    char a;   // definicion de una variable tipo char
    int b;    // definicion de una variable tipo entero
    char *pa; // definicion de un puntero a char
    int *pb;  // definicion de un puntero a int

    printf("\nEl valor de a='%c'\t\t,la direccion(a) =%p, tamano(a) =%d byte", a, &a, sizeof(a));
    printf("\nEl valor de b=%d\t\t,la direccion(b) =%p, tamano(b) =%d bytes", b, &b, sizeof(b));
    printf("\nEl valor de pa=%p\t,la direccion(pa)=%p, tamano(pa)=%d bytes", pa, &pa, sizeof(pa));
    printf("\nEl valor de pb=%p\t,la direccion(pb)=%p, tamano(pb)=%d bytes\n", pb, &pb, sizeof(pb));

    return 0;
}
