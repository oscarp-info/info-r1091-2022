#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *work();

int main(int argc, char **argv)
{

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, work, NULL);
    // (1) crear el segundo thread
    pthread_create(&thread2, NULL, work, NULL);

    pthread_join(thread1, NULL);
    // (2) esperar a que termine el thread2
    pthread_join(thread2, NULL);

    return 0;
}

void *work()
{
    printf("== Informatica I ==\n");
    // (3) para simular el "paralelismo"
    sleep(3);
    printf("== Fin ==\n");
}
