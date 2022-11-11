/*
 * Get return multiple values from a thread (passed struct as reference as parameter)
 *
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

struct data
{
    pthread_t thread_id;
    long valor;
    long resultado;
};

typedef struct data DATA;

void *work(void *arg);

int main(int argc, char **argv)
{

    DATA st_data;

    st_data.thread_id = 0;
    st_data.valor = 10;
    st_data.resultado = 0;

    pthread_create(&st_data.thread_id, NULL, work, (void *)&st_data);
    pthread_join(st_data.thread_id, NULL);

    printf("res: %ld\n", st_data.resultado);

    return 0;
}

void *work(void *arg)
{

    DATA *st = (DATA *)arg;

    st->resultado = st->valor + 1;

    return NULL;
}
