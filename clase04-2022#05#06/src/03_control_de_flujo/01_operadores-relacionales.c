#include <stdio.h>

int main(){

    int h,z,a;

    h=3;
    z=5;	
    
    // imprime  0 (es decir Falso)
    printf("h=3 z=5 (h==1) \t\t==> %d\n", h == 1); 
    
    // imprime  1 (es decir Verdadero)
    printf("h=3 z=5 (h==3) \t\t==> %d\n", h == 3); 
    
    // imprime  5 (es decir Verdadero)
    printf("h=3 z=5 (z) \t\t==> %d\n", z ); 
    
    // imprime  1 (es decir Verdadero)
    printf("h=3 z=5 (z>=h) \t\t==> %d\n", z >= h); 
    
    // imprime  0 (es decir Falso)
    printf("h=3 z=5 (h>=z) \t\t==> %d\n", h >= z); 
    
    // imprime  1 (es decir Verdadero)
    printf("h=3 z=5 (5<=z) \t\t==> %d\n", 5 <= z); 
    
    // imprime  0 (es decir Falso)
    printf("h=3 z=5 (5<z) \t\t==> %d\n", 5 < z); 

    // imprime  1 (es decir Verdadero)
    a= (h!=z); // o sin paréntesis
    printf("h=3 z=5 (a= (h!=z)) \t==> %d\n", a); 

    // imprime  0 (es decir Falso)
    a= h==z;
    printf("h=3 z=5 (a= h==z) \t==> %d\n", a); 

    return 0;

}