#include <stdio.h>
#include <unistd.h>

// (1)
#include <pthread.h>

// (2) compilar con -lpthread

// (3) crear la funcion que se ejecutara al crear el thread
void *work();

int main(int argc, char **argv)
{

    pthread_t thread1;

    // (4) crear el thread
    pthread_create(&thread1, NULL, work, NULL);

    // (5) esperar a que termine el thread1
    pthread_join(thread1, NULL);

    return 0;
}

void *work()
{
    printf("== Informatica I ==\n");
}
