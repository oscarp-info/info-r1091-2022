#include <stdio.h>

int main(void){

    int nota;

    printf("Ingrese una nota: ");
    scanf("%d",&nota);

    switch (nota) { 
        case 10: 
            printf ("Excelente\n");
            printf ("Ha alcanzado la nota mas alta");
            break;
        case 9:
        case 8: 
            printf ("Muy Bueno"); 
            break;
        case 7:
        case 6: 
            printf ("Bueno"); 
            break; 
        case 5:
        case 4: 
            printf ("Ya no alcanza"); 
            break; 
        case 1: 
            printf ("Un desastre\n");
        case 2:
        case 3: 
            printf ("siga participando"); 
            break; 
        default: 
            printf ("ERROR en nota (%d)",nota); 
            break;
        }

    return 0;
}