/*
 * detached(separado) threads
 *  un thread separado libera automáticamente los recursos asignados al salir (no ocurre lo mismo con joined)
 *  como el thread separado libera automáticamente los recursos al salir, no hay forma de determinar
 *  su valor de retorno de la función del thread separado
 *
 *  caso de uso:
 *      a)  tareas en background
 *      b)  se utiliza cuando desde el main tengo que lanzar muchos threads
 *          y no tiene sentido gastar mucho tiempo con los join
 *          directamente utilizo pthread_exit para que todos los threads puedan finalizar
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

    // otra forma de detach, con attr, pero ya lo creo detached
    pthread_attr_t detachedThread;
    pthread_attr_init(&detachedThread);
    pthread_attr_setdetachstate(&detachedThread, PTHREAD_CREATE_DETACHED);

    for (i = 0; i < THREAD_NUM; i++)
    {
        pthread_create(&th[i], &detachedThread, work, NULL);
    }

    // for (i = 0; i < THREAD_NUM; i++)
    // {
    //     if (pthread_join(th[i], NULL) != 0)
    //     {
    //         printf("Failed to join thread\n");
    //     }
    // }
    // return 0;
    pthread_attr_destroy(&detachedThread);
    pthread_exit(0);
}