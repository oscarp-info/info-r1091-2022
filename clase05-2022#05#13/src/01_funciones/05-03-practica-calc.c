/*
 * Escribir las funciones necesarias para implementar una calculadora
 * suma +
 * resta -
 * multiplicacion *
 * division /
 */

#include<stdio.h>

#define SUMA                0
#define RESTA               1
#define MULTIPLICACION      2
#define DIVISION            3

#define OK                  0
#define ERROR               -1


// prototipos de funciones
float suma (float, float);
float resta (float, float);
float multiplicacion (float, float);
float division (float, float);
float calculadora (float, float, char);

/*
 * valores de retorno:
 *  devuelve 0 si esta todo bien
 *  devuelve -1 en caso de error (ejemplo division por cero)
 * 
 * argumentos:
 *  primer numero
 *  segundo numero
 *  variable donde guardar el resultado
 *  operacion ( sumar, restar, multiplicar o dividir )
 *  
 */
int calculadora_v2 (float,float, float*, char);


int main (void){
    
    float resultado;
    float a,b;
    char operacion;
    int todook = OK;
    
    a=15.5;
    b=0;
    operacion = DIVISION; 
    
    //resultado = calculadora (a,b,operacion);
    todook = calculadora_v2(a,b,  &resultado ,operacion);
    
    if (todook == OK)
    {
       printf ("la operacion dio %.2f\n",resultado);
    }
    else
    {
        printf("no se puede dividir por 0 capo\n");
    }
    
    return 0;
}


float suma (float a, float b)
{
   return (a+b); 
}

float resta (float a, float b)
{
   return (a-b); 
}

float multiplicacion (float a, float b)
{
   return (a*b); 
}


float division (float a, float b)
{
   
    float resultado;
    
    if (b == 0)
    {
        resultado = 0;
    }
    
    else
    {
        resultado =a/b;
    }
    
    return resultado; 
}



float calculadora (float a, float b, char operador)
{
    float resultado;
   
    if (operador == SUMA)
   {
        resultado = suma (a,b);
   }   

      if (operador == RESTA)
   {
        resultado = resta (a,b);
   }   

   if (operador == MULTIPLICACION)
   {
        resultado = multiplicacion (a,b);
   }   
   
   if (operador == DIVISION)
   {
        resultado = division (a,b);
   }   

    return resultado;
        
}



int calculadora_v2 (float a,float b, float* resultado , char operador)
{
    
    int todook=OK;
    
    if (b!=0)
    {
            *resultado= calculadora (a,b,operador);
    
    }
    else
        if (operador != DIVISION)
        {
            *resultado= calculadora (a,b,operador);            
        }
        else
        {
            todook= ERROR;
        }
    
    return todook;
    
}
