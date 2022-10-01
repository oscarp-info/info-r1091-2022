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
    char name[100];
    char genero[100];

};
typedef struct persona PERSONA;

void remove_newline_ch(char *line);

int main(){

    FILE *fp;
    char buff[MAX_LINE_LEN];
    char *token;
    PERSONA arr[MAX_ARRAY_LEN];
    int i = 0;

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
        strcpy(arr[i].name, token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        //  printf("token=%s\n", token);
        strcpy(arr[i].genero, token);


        // imprimo la estructura
        printf("(%d,%s,%s)\n",arr[i].id, arr[i].name, arr[i].genero );

    }

    fclose(fp);
    return 0;


}


void remove_newline_ch(char *line){
    int new_line = strlen(line) -1;
    
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}