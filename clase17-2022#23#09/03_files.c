#include <stdio.h>
#include <stdlib.h> //exit

int main(){
    int r;
    char data = 0;
    
    //1 paso: abrir el archivo
    FILE *fp;
    fp = fopen("database.dat", "r");

    // 2 paso: verificar fopen
    if ( fp == NULL){
        printf("No se puedo abrir el archivos");
        exit(-1);
    }

    // 3 paso: leer o escribir
    r = fread( &data, sizeof(data), 1, fp   );
    printf("Se leyeron %d bloque de %ld bytes/s\n", r, sizeof(data));
    printf("data = %c\n", data);

    r = fread( &data, sizeof(data), 1, fp   );
    printf("Se leyeron %d bloque de %ld bytes/s\n", r, sizeof(data));
    printf("data = %c\n", data);

    r = fread( &data, sizeof(data), 1, fp   );
    printf("Se leyeron %d bloque de %ld bytes/s\n", r, sizeof(data));
    printf("data = %c\n", data);

    // 4 paso: cerrar el archivo
    fclose(fp);

    return 0;

}


