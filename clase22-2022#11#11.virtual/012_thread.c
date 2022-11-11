/*
 * creacion de threads con loop for y array de threads id
 *  - primero crear todos los threads
 *  - segundo hacer todos los joins
 *  - si hacemos create-join, create-join....todo el programa es secuencial
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// para simular un recurso compartido, primer version como variable global
int shared_resource = 0;
int read_shared_resource(void);
void write_shared_resource(int value);

// funcion que realiza un tarea sobre el recurso compartido
void *work(void *);

// mutex variable
pthread_mutex_t mutex;

// cantidad maxima de threads
#define THREAD_NUM 10

int main(int argc, char **argv)
{
    pthread_t arr_thread_id[THREAD_NUM];
    int before, after;
    int valor[THREAD_NUM];
    int i;

    // initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    before = read_shared_resource();
    printf("before: %d\n", before);

    for (i = 0; i < THREAD_NUM; i++)
    {
        valor[i] = (i + 1) * 100;
    }

    for (i = 0; i < THREAD_NUM; i++)
    {
        pthread_create(&arr_thread_id[i], NULL, work, (void *)&valor[i]);
        printf("main pthread_t %ld started\n", arr_thread_id[i]);
    }

    for (i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(arr_thread_id[i], NULL);
    }

    // destroy the mutex
    pthread_mutex_destroy(&mutex);

    after = read_shared_resource();
    printf("after: %d\n", after);

    return 0;
}

void *work(void *arg)
{
    // simulamos una accion sobre el recurso compartido
    int valor;

    // el primer thread blockea el "recurso" y los demas se quedan esperando a que se libere
    // el lock y el unlock del mutex definen los limetes de la zona critica (donde se podria
    // producir race condition)
    pthread_mutex_lock(&mutex);

    // leer
    valor = read_shared_resource();
    // modificar
    valor += *((int *)arg);
    // escribir
    write_shared_resource(valor);

    // unlock, se liberar el mutex (salida de la zona critica) y ya otros threads pueden acceder
    pthread_mutex_unlock(&mutex);

    return NULL;
}

/*
 * API's para interactual con el recurso compartido
 */

int read_shared_resource(void)
{
    usleep(250000);
    return shared_resource;
}

void write_shared_resource(int value)
{
    usleep(250000);
    shared_resource = value;
}
