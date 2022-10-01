#include <stdio.h>
#include <stdlib.h> //exit

int main(){
    int r;
    int data_01 = 1;
    int data_02 = 2;
    
    //1 paso: abrir el archivo
    FILE *fp;
    fp = fopen("database.dat", "r");

    // 2 paso: verificar fopen
    if ( fp == NULL){
        printf("No se puedo abrir el archivos");
        exit(-1);
    }

    // 3 paso: leer o escribir
    r = fwrite( &data_01, sizeof(data_01), 1, fp   );
    // fwrite( &data_02, sizeof(data_02), 1, fp   );
    
    printf("Se escribieron %d bloque de %ld bytes/s\n", r, sizeof(data_01));

    // 4 paso: cerrar el archivo
    fclose(fp);

    return 0;

}


