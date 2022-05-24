/*
 * Le suma +2 a Dos Numeros con una funcion x referencia
 * Nota: mas adelante veremos como elimnar los Warningscuando imprimimos direcciones con %d
 */

#include <stdio.h>

// prototipo
void SumaDos(int *, int *);

int main(void)
{
    int a;
    int b;
    
    a = 10;
    b = 5;

    printf("main():: El valor de a=%d y su direccion es &a=%d\n", a, &a);
    printf("main():: El valor de b=%d y su direccion es &b=%d\n", b, &b);

    SumaDos(&a, &b);

    printf("main():: El valor de a=%d y su direccion es &a=%d\n", a, &a);
    printf("main():: El valor de b=%d y su direccion es &b=%d\n", b, &b);

    return 0;

}

void SumaDos(int *x, int *y){
    // int * es la declaracion de un puntero a entero (variable que guarda una direccion)
	
	printf("SumaDos():: El valor de x=%d, su direccion es &x=%d y el contenido apuntado es *x=%d\n", x, &x, *x);
	printf("SumaDos():: El valor de y=%d, su direccion es &y=%d y el contenido apuntado es *y=%d\n", y, &y, *y);

    // En *x '*' es el operador indireccion ( valor apuntado por...) 
    *x = *x + 2;
    
    // En *x '*' es el operador indireccion ( valor apuntado por...)
    *y = *y + 2;

	printf("SumaDos():: El valor de x=%d, su direccion es &x=%d y el contenido apuntado es *x=%d\n", x, &x, *x);
	printf("SumaDos():: El valor de y=%d, su direccion es &y=%d y el contenido apuntado es *y=%d\n", y, &y, *y);


}
 
