/*
 * Ejemplo 001:
 * 	Creacion  de un thread
 *		Imprime el mensaje "Hello World"
 *		Sync entre threads
 *
 *	Compilacion
 *		gcc 001_pthread.c -o test -l pthread
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * Header de la libreria pthreads
 */
#include <pthread.h>

/*
 * Prototipos
 */
void *work(void *);
void print(char *);

/*
 * Variables Globales
 */
int contador = 0;

int main(int argc, char **argv)
{

    /*
     * Definido en "sys/types.h" como "typedef unsigned int pthread_t"
     *
     */
    pthread_t tid;

    int rc;

    fprintf(stderr, "Main:: pid %d\n", (int)getpid());

    /*
     * int pthread_create(	pthread_t *thread,
     *											const pthread_attr_t *attr,
     * 											void *(*start_routine)(void*),
     * 											void *arg);
     */
    rc = pthread_create(&tid, NULL, work, NULL);

    if (rc != 0)
    {
        fprintf(stderr, "Main :: No se pudo crear el thread.");
        exit(-1);
    }

    rc = pthread_join(tid, NULL);
    if (rc)
    {
        printf("ERROR; return code from pthread_join() is %d\n", rc);
        exit(-1);
    }

    fprintf(stderr, "Main :: Fin\n");
}

void *work(void *p)
{

    char s[80];

    sprintf(s, "Thread :: Hello World, pid %d thread  id %ld", (int)getpid(), pthread_self());

    print(s);

    pthread_exit(NULL);
}

void print(char *s)
{

    while (s != NULL && *s != '\0')
    {
        fputc((int)*s, stderr);
        s++;
    }

    fputc('\n', stderr);
}
