#include <stdio.h>
#include <stdlib.h> //exit

int main(){
    int r;
    char data = '1';
    
    //1 paso: abrir el archivo
    FILE *fp;
    fp = fopen("database.dat", "w");

    // 2 paso: verificar fopen
    if ( fp == NULL){
        printf("No se puedo abrir el archivos");
        exit(-1);
    }

    // 3 paso: leer o escribir
    r = fwrite( &data, sizeof(data), 1, fp   );

    printf("Se escribieron %d bloque de %ld bytes/s\n", r, sizeof(data));

    // 4 paso: cerrar el archivo
    fclose(fp);

    return 0;

}


