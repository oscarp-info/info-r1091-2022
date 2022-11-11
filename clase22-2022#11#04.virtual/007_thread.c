/*
 * Get return value from a thread (pthread_join)
 *
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void *work(void *arg);

int main(int argc, char **argv)
{
    pthread_t thread1;
    long valor1 = 1;

    // puntero para obtener la respuesta del thread en el join
    int *res;

    srand(time(NULL));

    pthread_create(&thread1, NULL, work, (void *)&valor1);
    pthread_join(thread1, (void **)&res);

    printf("res: %d\n", *res);

    // imprimimos la direccion
    printf("main: %p\n", res);

    free(res);

    return 0;
}

void *work(void *arg)
{
    int valor = rand() % 10 + 1;

    // warning: function returns address of local variable [-Wreturn-local-addr]
    // Segmentation fault
    // return (void *)&valor;

    // solucion: crear variable dinamicamente
    int *r = malloc(sizeof(int));
    *r = valor;

    // imprimimos la direccion
    printf("work: %p\n", r);

    return (void *)r;
}
