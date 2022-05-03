/*
 * Scope o alcance de variables
 * recuerden que esta delimitado por {}
 *
 */

#include <stdio.h>


int main (void){

	// variables locales o automaticas
	int a=5, b=3, c=-7;

	printf("%d %d %d\n", a,b,c);			//5 3 -7

    {
		int b=8;
		float c=9.9;

		printf("%d %d %f\n", a,b,c);		//5 8 9.9

		a=b;

			{
                int c;
                c=b;
                printf("%d %d %d\n", a,b,c);	//8 8 8
			}
		printf("%d %d %f\n", a,b,c);		//8 8 9.9
    }

	printf("%d %d %d\n", a,b,c);			//8 3 -7

	return 0;
}
