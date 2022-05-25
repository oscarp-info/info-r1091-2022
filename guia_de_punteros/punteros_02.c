#include <stdio.h>

int main()
{
    char a = 'a';
    int b = 300;

    printf("\nEl valor de a[char]='%c'\t, la direccion(a)=%p, tamano(a)=%ld byte", a, &a, sizeof(a));
    printf("\nEl valor de b[int ]=%d\t, la direccion(b)=%p, tamano(b)=%ld bytes", b, &b, sizeof(b));
    printf("\n\n");

    return 0;
}
