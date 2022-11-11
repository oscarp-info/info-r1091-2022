/*
 * pass argument to thread
 *
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *work(void *arg);

int main(int argc, char **argv)
{

    pthread_t thread1;
    long valor1 = 1;

    // (1) agrego un nuevo thread
    pthread_t thread2;
    long valor2 = 2;

    pthread_create(&thread1, NULL, work, (void *)&valor1);

    // (1) agrego un nuevo thread
    pthread_create(&thread2, NULL, work, (void *)&valor2);

    pthread_join(thread1, NULL);

    // (1) agrego un nuevo thread
    pthread_join(thread2, NULL);

    return 0;
}

void *work(void *arg)
{

    // casting...
    long *valor = (long *)(arg);

    printf("valor %ld\n", *valor);

    return NULL;
}
