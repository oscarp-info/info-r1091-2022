/*
 * La función "swap" recibe dos parámetros e intercambia 
 * el valor del uno por el otro
 * 
 * void swap (int*, int*):
 *  
 */

#include<stdio.h>


void swap (int*, int*);


int main (void){
    
    int a = 10;
    int b = 20;
    
    printf("a vale: %d. b vale: %d.\n",a,b);
    
    swap (&a,&b);
    
    printf("a vale: %d. b vale: %d.\n",a,b);
    
    return 0;
}


void swap (int* ap, int* bp)
{
    int aux;

    aux = *ap;
    *ap = *bp;
    *bp = aux;
}
