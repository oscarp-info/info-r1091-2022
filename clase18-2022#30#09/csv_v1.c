/*
 * Generacion de archivos .csv basado en datos reales para 'tests'
 * https://www.mockaroo.com/
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN    1000

int main(){

    FILE *fp;
    char buff[MAX_LINE_LEN];
    char *token;

    fp = fopen("example.csv", "r");
    if (fp == NULL){
        printf("Error al abrir csv\n");
        return -1;
    }

    // ojo que incluye el \n si lo encuentra
    // avanza linea a linea por cada llamada
    // los delim mas comunes , ; | tab space (no pueden ser parte del contenido)
    while(fgets(buff, sizeof(buff), fp) != NULL){
        printf("buff=%s\n", buff);
        
        // limpiar el \n si existe
        // completar...
        
        // primer llamada...primer tocken (campo del csv)
        token = strtok(buff, ",");
        if (token == NULL)
            return;
        printf("token=%s\n", token);

      
        while(token != NULL){
            // siguentes llamadas...siguientes token (campos del csv)
            // se llama con NULL
            token = strtok(NULL, ",");
            if (token != NULL){
                printf("token=%s\n", token);
            }
        }


    }

    fclose(fp);
    return 0;


}





