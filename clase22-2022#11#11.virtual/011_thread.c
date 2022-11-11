/*
pthread * pthread_t vs SYS_gettid (linux specific, kernel mode)
 *
 * pthread_t
 *  tecnicamente es "unsigned long" en linux, pero en la especificacion POSIX es del tipo "opaque data type"
 *  por eso no se deberia utilizar salvo con las funciones de la propia libreria, ya que podria ser
 *  un int, un char o una estructura....es decir no podemos asumir un "tipo"
 *  pthread_create y pthread_join lo utilizan para hacer referencia al mismo thread
 *  si quiere obtenerlo dentro del thread se utiliza pthread_self()
 *voi
 * int = SYS_gettid() => thread id
 *  es el thread id como "entero" a nivel de kernel
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define THREAD_NUMBER 5

void *work(void *arg);

int main(int argc, char **argv)
{
    int i = 0;
    pthread_t arr_thread_id[THREAD_NUMBER];

    printf("main:: main pid: %d\n", getpid());
    printf("main:: main pthread_t: %lu\n", pthread_self());

    for (i = 0; i < THREAD_NUMBER; i++)
    {
        pthread_create(&arr_thread_id[i], NULL, work, NULL);
        printf("main:: work pthread_t: %lu\n", arr_thread_id[i]);
    }

    for (i = 0; i < THREAD_NUMBER; i++)
    {
        pthread_join(arr_thread_id[i], NULL);
    }

    return 0;
}

void *work(void *arg)
{
    pthread_t t = pthread_self();
    printf("\twork:: pthread_t: %lu\n", t);

    return NULL;
}
