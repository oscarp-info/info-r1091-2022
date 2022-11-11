/*
 * single-thread vs multi-thread
 * utilizar "time" para comparar tiempos de ejecucion
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *work(void *arg);

int main(int argc, char **argv)
{

    pthread_t thread1;
    pthread_t thread2;
    long valor1 = 1;
    long valor2 = 2;

    if (argc < 2)
    {
        printf("utilizar: single-thread[s] o multi-thread[m] o sequential[j]?\n");
        return 0;
    }
    if (*argv[1] == 's')
    {
        // single-thread
        work((void *)&valor1);
        work((void *)&valor2);
    }
    else if (*argv[1] == 'm')
    {
        // multi-thread
        pthread_create(&thread1, NULL, work, (void *)&valor1);
        pthread_create(&thread2, NULL, work, (void *)&valor2);

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
    }
    else if (*argv[1] == 'j')
    {
        // multi-thread but sequential running
        pthread_create(&thread1, NULL, work, (void *)&valor1);
        pthread_join(thread1, NULL);

        pthread_create(&thread2, NULL, work, (void *)&valor2);
        pthread_join(thread2, NULL);
    }

    else
    {
        printf("las opciones son [s] o [m] o [j]\n");
    }

    return 0;
}

void *work(void *arg)
{
    // casting...
    long *valor = (long *)(arg);

    long suma, i;

    for (i = 0; i < 1000000000; i++)
    {
        suma = suma + *valor;
    }

    printf("valor %ld\n", *valor);

    return NULL;
}
