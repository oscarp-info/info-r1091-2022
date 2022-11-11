/*
 * Ejemplo productor-consumidor con mutex
 *      es ineficiencia ya que ambos threads
 *      continuamente en el while(1) verifican buffer lleno o vacio
 *
 *      en el algoritmo del producer, podria a llegar a descartar valores (los random)
 *      si el buffer esta lleno
 *      en un programa real seria una condicion indeseable
 *      deberiamos quedarnos esperando a que se vacie el buffer
 *      para no descartar el valor
 *
 *      una solucion posible es utilizar semaforos, pero no forma parte del alcance de la materia
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 2
#define BUFFER_MAX 10

int buffer[BUFFER_MAX];
int count = 0;
pthread_mutex_t mutexBuffer;

void *producer(void *args);
void *consumer(void *args);

int main()
{
    int i;
    pthread_t th[THREAD_NUM];

    srand(time(NULL));

    pthread_mutex_init(&mutexBuffer, NULL);

    for (i = 0; i < THREAD_NUM; i++)
    {
        if (i % 2 == 0)
        {
            if (pthread_create(&th[i], NULL, &producer, NULL) != 0)
            {
                perror("Failed to create thread");
            }
        }
        else
        {
            if (pthread_create(&th[i], NULL, &consumer, NULL) != 0)
            {
                perror("Failed to create thread");
            }
        }
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexBuffer);

    return 0;
}

void *producer(void *args)
{
    while (1)
    {
        int x = rand() % 100;

        // Add to the buffer
        pthread_mutex_lock(&mutexBuffer);
        if (count < BUFFER_MAX)
        {
            buffer[count] = x;
            count++;
        }
        else
        {
            printf("producer:: skipped value\n");
        }
        pthread_mutex_unlock(&mutexBuffer);
    }
}

void *consumer(void *args)
{
    while (1)
    {
        int y = -1;

        // Remove from the buffer
        pthread_mutex_lock(&mutexBuffer);
        if (count > 0)
        {
            y = buffer[count - 1];
            count--;
        }
        pthread_mutex_unlock(&mutexBuffer);

        // Consume
        printf("Got %d\n", y);
    }
}