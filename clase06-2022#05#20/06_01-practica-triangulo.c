/*
 * Escriba una funcion que determine si 3 valores correspondientes a largos 
 * de segmentos se corresponden a un triangulo.
 * Las condiciones necesarias para que una terna de valores sea un triangulo 
 * son las siguientes:
 *      lado1 + lado2 > lado3 
 *      lado3 + lado2 > lado1
 *      lado3 + lado1 > lado2 
 *
 * prototipo de la función a implementar:
 *  int es_triangulo (int,int,int)
 *
 * Generar un main para probar el programa donde se llame a la funcion 
 * es_triangulo y se imprima el mensaje correspondiente al usuario.
 */


#include<stdio.h>

#define VERDADERO   1
#define FALSO       0

/*
 * documentar el prototipo de la función...
 * ...
 */
int es_triangulo (int,int,int);


int main (void)
{
    int lado1=40;
    int lado2=5;
    int lado3=6;
    int resultado;
    
    resultado = es_triangulo(lado1,lado2,lado3);
    
    if (resultado == VERDADERO)
    {
        printf("los valores se corresponden con un triangulo\n");
    }
    else
    {
        printf("los valores NO se corresponden con un triangulo\n");
    }
    
    return 0;    
    
}


int es_triangulo (int lado1 ,int lado2 ,int lado3) {
    
    int resultado =FALSO;
    
    if( (lado1 + lado2) > lado3)
    {
        if (lado2 + lado3 > lado1)
        {
            if (lado1 + lado3 > lado2)
            {
                resultado = VERDADERO;
            }
        }
    }
    
    return resultado;
}
