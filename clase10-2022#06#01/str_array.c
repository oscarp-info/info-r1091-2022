// https://overiq.com/c-programming-101/array-of-strings-in-c/


/*
 * un str, es un array de una dimension de caracteres (1-D array)
 * un array de str, es un array de dos dimensiones de caracteres (2-D array)  
 */

#include <stdio.h>  // puts

int main(void){
    int i;

    /*
     * char arr[q][l];
     *      q = cantidad de cadenas
     *      l = longitud maxima del string 
     */

    /*
     * cuanta memoria alloca el compilador?
     *      3x80x1 = 240 bytes
     *
     */
    char arr_name_1[3][80];

    char arr_name_2[3][80] = {
        "Juan",
        "Carlos",
        "Pedro"
    };

    char arr_name_3[3][80] = {
            {'J', 'U', 'a', 'n', 0},
            {'C', 'a', 'r', 'l', 'o', 'S', '\0'},
            {'P', 'e', 'D', 'r', 'o', 0}
    };

    puts(arr_name_2[0]);
    puts(arr_name_3[1]);

    /*
     * el nombre del array es un puntero(static) al primer elemento
     * entonces...que es arr_name_1?
     *  The arr_name_1 es un puntero a un array de 80 caracteres o char(*)[80]. 
     *      arr_name_1 + 0 points to the 0th string or 0th 1-D array.
     *      arr_name_1 + 1 points to the 1st string or 1st 1-D array.
     *      arr_name_1 + 2 points to the 2nd string or 2nd 1-D array.
     *      In general, ch_arr + i points to the ith string or ith 1-D array.
     *
     *      *(ch_arr + 0) + 0 points to the 0th character of 0th 1-D array (i.e s)
     *      *(ch_arr + 0) + 1 points to the 1st character of 0th 1-D array (i.e p)
     *      *(ch_arr + 1) + 2 points to the 2nd character of 1st 1-D array (i.e m)
     *  
     */

    // cuantos bytes hay entre cada string ===> 80 
    for(i = 0; i < 3; i++){
        printf("string = %s \t address = %u\n", arr_name_3 + i, arr_name_3 + i);
    }

}
