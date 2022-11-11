/*
 * deadlock
 *      con 2(dos) mutex
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

pthread_mutex_t mutex_counter2;
int counter2 = 5;

void *work(void *args)
{
    // tenemos un error si se realiza en diferente orden
    // ejecutar varias veces
    // un thread realiza el look de counter1 y el otro thread de counter2
    // aparece un deadlock
    // los dos threads se quedan esperando mutex diferentes al mismo tiempo
    if (rand() % 2 == 0)
    {
        pthread_mutex_lock(&mutex_counter1);
        sleep(1); // para lograr el deadlock
        pthread_mutex_lock(&mutex_counter2);
    }
    else
    {
        pthread_mutex_lock(&mutex_counter2);
        sleep(1); // para lograr el deadlock
        pthread_mutex_lock(&mutex_counter1);
    }

    counter1 += 10;
    counter2 += 1;
    printf("work:: counter1: %d\n", counter1);
    printf("work:: counter2: %d\n", counter2);
    pthread_mutex_unlock(&mutex_counter1);
    pthread_mutex_unlock(&mutex_counter2);
}

int main(int argc, char *argv[])
{
    int i;
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutex_counter1, NULL);
    pthread_mutex_init(&mutex_counter2, NULL);

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
    printf("main:: counter2: %d\n", counter2);

    pthread_mutex_destroy(&mutex_counter1);
    pthread_mutex_destroy(&mutex_counter2);

    return 0;
}