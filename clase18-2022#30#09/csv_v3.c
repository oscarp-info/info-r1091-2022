/*
 * Generacion de archivos .csv basado en datos reales para 'tests'
 * https://www.mockaroo.com/
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // atoi

#define MAX_LINE_LEN    1000
#define MAX_ARRAY_LEN   500

struct persona{
    int id;
    char *name;
    char *genero;

};
typedef struct persona PERSONA;

void remove_newline_ch(char *line);

int main(){

    FILE *fp;
    char buff[MAX_LINE_LEN];
    char *token;
    PERSONA arr[MAX_ARRAY_LEN];
    int i = 0, j = 0;


    fp = fopen("example.csv", "r");
    if (fp == NULL){
        printf("Error al abrir csv\n");
        return -1;
    }

    // ojo que incluye el \n si lo encuentra
    // avanza linea a linea por cada llamada
    // los delim mas comunes , ; | tab space (no pueden ser parte del contenido)
    while(fgets(buff, sizeof(buff), fp) != NULL){
        //printf("buff=%s\n", buff);
        
        // limpiar el \n si existe
        remove_newline_ch(buff);
        
        // primer llamada...primer tocken (campo del csv)
        token = strtok(buff, ",");
        if (token == NULL)
            continue;
        // si es la primer linea la salteo, es el encabezado del csv
        if (strcmp(token,"id") == 0){
            continue;
        }

        // imprimo el str original buff
        // con esto verifico que en realidad strtok modifica
        // buff agregando un 0 al final del token y devolviendo un puntero 
        // donde empieza el token
        // ver:
        // https://codebrowser.dev/glibc/glibc/string/strtok.c.html
        // https://codebrowser.dev/glibc/glibc/string/strtok_r.c.html#__strtok_r
        printf("%s\n", buff);

        //printf("token=%s\n", token);
        // asigno el id
        // convierte str to int (atoi)
        arr[i].id = atoi(token);
      
        // siguentes llamadas...siguientes token (campos del csv)
        // se llama con NULL
        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        //printf("token=%s\n", token);
        // ojo, esto no se puede hacer...ver mas abajo
        arr[i].name = token;

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        //printf("token=%s\n", token);
        // ojo, esto no se puede hacer...ver mas abajo
        arr[i].genero = token;

        i++;

     }

    // ojo!
    // recorro todo el array hasta 'i' y verifico que strtok 
    // el funcionamiento de strtok
    // NO UTILIZA 'malloc'
    // ojo que modifica el str original!!!!
    printf("Se agregaron %d elementos\n", i);
    for (j=0;j<i;j++){
        printf("(%d,%s,%s)\n",arr[j].id, arr[j].name, arr[j].genero );
    }

    fclose(fp);
    return 0;


}


void remove_newline_ch(char *line){
    int new_line = strlen(line) -1;
    
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}