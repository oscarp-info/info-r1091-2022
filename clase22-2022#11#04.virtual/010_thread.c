/*
 * race condition (salvada con mutex)
 *
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

int main(int argc, char **argv)
{
    pthread_t t1, t2;
    int before, after;
    int valor1, valor2;

    // initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    before = read_shared_resource();
    printf("before: %d\n", before);

    // work(100);
    // work(200);
    valor1 = 100;
    valor2 = 200;
    pthread_create(&t1, NULL, work, (void *)&valor1);
    pthread_create(&t2, NULL, work, (void *)&valor2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

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
