/*
 * race condition
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
void work(int);

int main(int argc, char **argv)
{
    int before, after;

    before = read_shared_resource();
    printf("before: %d\n", before);

    work(100);
    work(200);

    after = read_shared_resource();
    printf("after: %d\n", after);

    return 0;
}

void work(int arg)
{

    // simulamos una accion sobre el recurso compartido
    int valor;

    // leer
    valor = read_shared_resource();
    // modificar
    valor += arg;
    // escribir
    write_shared_resource(valor);
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
