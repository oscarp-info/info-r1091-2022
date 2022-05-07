#include <stdio.h>

int main(){

    int h,z,a,b;

    h=3; 
    z=5;	
    a=0;

    printf("h=3 z=5 ((h == 1) || (z <= 1)) \t\t==> %d\n",(h == 1) || (z <= 1)); 
    printf("h=3 z=5 ((h != 1) && (z == 1)) \t\t==> %d\n",(h != 1) && (z == 1)); 
    printf("h=3 z=5 (( h ) || (z == 1)) \t\t==> %d\n", ( h ) || (z == 1)); 
    printf("a=0 (!a) \t\t\t\t==> %d\n", !a ); 
    printf("h=3 z=5 a=0 (h && z && a) \t\t==> %d\n", h && z && a); 
    printf("h=3 z=5 a=0 (h && z && !a) \t\t==> %d\n", h && z && !a); 
    printf("h=3 z=5 a=0 !(h && z && a) \t\t==> %d\n", !(h && z && a)); 

    b= ((h!=z) && (a)) || (z>0) ;
    printf("h=3 z=5 a=0 (((h!=z) && (a)) || (z>0)) \t==> %d\n", b);

    b= !((h!=z) || (a)) && (z>0) ;
    printf("h=3 z=5 a=0 (!((h!=z) || (a)) && (z>0)) ==> %d\n", b);
    

}

