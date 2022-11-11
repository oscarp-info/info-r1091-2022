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
    // sem_init(&semEmpty, 0, 10);
    // sem_init(&semFull, 0, 0);

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
    // sem_destroy(&semEmpty);
    // sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);

    return 0;
}

void *producer(void *args)
{
    while (1)
    {
        int x = rand() % 100;
        // sleep(1);

        // Add to the buffer
        // sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        if (count < BUFFER_MAX)
        {
            buffer[count] = x;
            count++;
        }
        pthread_mutex_unlock(&mutexBuffer);
        // sem_post(&semFull);
    }
}

void *consumer(void *args)
{
    while (1)
    {
        int y = -1;

        // Remove from the buffer
        // sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        if (count > 0)
        {
            y = buffer[count - 1];
            count--;
        }
        pthread_mutex_unlock(&mutexBuffer);
        // sem_post(&semEmpty);

        // Consume
        printf("Got %d\n", y);
        // sleep(1);
    }
}