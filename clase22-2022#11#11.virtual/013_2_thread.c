/*
 * detached threads
 *
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 2

void *work(void *args)
{
    sleep(1);
    printf("End\n");
}

int main(int argc, char *argv[])
{
    int i;
    pthread_t th[THREAD_NUM];

    // otra forma de detach, con attr
    pthread_attr_t detachedThread;
    pthread_attr_init(&detachedThread);
    pthread_attr_setdetachstate(&detachedThread, PTHREAD_CREATE_DETACHED);

    for (i = 0; i < THREAD_NUM; i++)
    {
        pthread_create(&th[i], &detachedThread, work, NULL);
    }

    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            printf("Failed to join thread\n");
        }
    }
    return 0;
}