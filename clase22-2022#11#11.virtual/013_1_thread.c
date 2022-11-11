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

    // por default los threads son joinable
    // pero si a un thread lo detachamos, lo que estamos haciendo es que no permita join
    // al querer hacer un join nos da error
    // y en este caso no veremos los printf de los threas ya que al terminar main
    // terminan lso threads (no tienen join)
    for (i = 0; i < THREAD_NUM; i++)
    {
        pthread_create(&th[i], NULL, work, NULL);
        pthread_detach(th[i]);
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