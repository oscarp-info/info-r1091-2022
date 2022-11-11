/*
 * deadlock
 *  es un bug (hay que evitarlo!)
 *  se produce cuando un thread realiza un pthread_mutex_lock a un mutex que ya esta en lock
 *  se produce cuando dos threads esperan por el recurso que tiene el otro y ninguno puede continuar
 *
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 10

pthread_mutex_t mutex_counter1;
int counter1 = 50;

void *work(void *args)
{
    pthread_mutex_lock(&mutex_counter1);

    // deadlock!
    pthread_mutex_lock(&mutex_counter1);

    counter1 += 10;
    printf("work:: counter1: %d\n", counter1);
    pthread_mutex_unlock(&mutex_counter1);
}

int main(int argc, char *argv[])
{
    int i;
    pthread_t th[THREAD_NUM];

    // sin prevenir el deadlock
    pthread_mutex_init(&mutex_counter1, NULL);

    // para prevenir el deadlock
    // pthread_mutexattr_t attr;
    // pthread_mutexattr_init(&attr);
    // pthread_mutexattr_setkind_np(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
    // pthread_mutex_init(&mutex_counter1, &attr);

    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_create(&th[i], NULL, &work, NULL) != 0)
        {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }
    printf("main:: counter1: %d\n", counter1);
    pthread_mutex_destroy(&mutex_counter1);
    return 0;
}