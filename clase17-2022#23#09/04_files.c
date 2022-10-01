#include <stdio.h>
#include <string.h>

struct registro{
    int id;
    char nombre[30];
    char genero;
};

typedef struct registro REGISTRO;

void Escribir(void);
void Leer(void);
void BuscarPorId(int id);

int main(){
    
    //Escribir();
    //Leer();
    BuscarPorId(3);

}

void Escribir(void){
    REGISTRO a = {1, "Juan", 'M'};
    REGISTRO b = {2, "Maria", 'F'};
    REGISTRO c = {3, "Pedro", 'M'};

    REGISTRO arr[3] = {a,b,c};
    
    //1)
    FILE *fp;
    fp = fopen("listado.bin", "w");
    
    //2) verificar...

    //3) escribo
    fwrite(arr, sizeof(REGISTRO), 3, fp);

    //4)cerrar
    fclose(fp);
}


void Leer(void){
    FILE *fp;
    REGISTRO arr[3];
    int i;

    //1
    fp = fopen("listado.bin", "r");

    //2

    //3
    fread(arr, sizeof(REGISTRO), 3, fp);

    //4
    fclose(fp);

    for (i=0; i<3;i++){
        printf("%d | %s | %c\n", arr[i].id, arr[i].nombre, arr[i].genero );
    }    
}

void BuscarPorId(int id){
    FILE *fp;
    REGISTRO a = {0,"",'X'};
    int r;

    fp = fopen("listado.bin", "r");
    
    fseek(fp, sizeof(REGISTRO)*(id-1), SEEK_SET);

    r = fread(&a, sizeof(REGISTRO), 1, fp);
    if(r == 0){
        printf("No encontrado\n");
    }
    else {
        printf("%d | %s | %c\n", a.id, a.nombre, a.genero );
    }

    fclose(fp);

}