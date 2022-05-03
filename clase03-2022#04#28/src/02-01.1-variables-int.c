#include <stdio.h>

int main(void)
{
    // diferentes maneras de declarar e inicializar variables    
    int a;
    int b;
    int c;
 
    // no le asinamos ningun valor y para ver con el printf que valores tienen
    // por default, ver lo Warnings del compilador 
    int x,y;

    // declaracion e inicializacion al mismo tiempo
    int edad = 18;

    // declaracion e inicializacion al mismo tiempo de dos varibles juntas
    int peso_inicial = 70, peso_actual = 68;

    // asignacion de un valor
    a = 100;
    b = 10;
    c = 1;
  
    // imprimo las variables
    printf("Variables int:\n\n");
    printf("a=%d b=%d c=%d\n", a,b,c);
    printf("x=%d y=%d (variables sin inicializar)\n", x,y);
    printf("edad=%d\n", edad);
    printf("peso_inicial=%d peso_actual=%d\n", peso_inicial,peso_actual);
    printf("\n\n");

    return 0;

} 