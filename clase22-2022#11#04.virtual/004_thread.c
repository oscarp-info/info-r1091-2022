#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *work();

int main(int argc, char **argv)
{

    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, work, NULL) != 0)
        return 1;

    if (pthread_create(&thread2, NULL, work, NULL) != 0)
        return 2;

    // if (pthread_join(thread1, NULL) != 0)
    //     return 3;

    // if (pthread_join(thread2, NULL) != 0)
    //     return 4;

    printf("==End main()==");

    // si no forzamos la escritura, quizas podemos observar que siempre se escribe al finalziar los threads
    // y no podriamos ver el funcionamiento correcto
    fflush(stdout);

    // al no hacer los join, si utilizamos return 0, finaliza main y todos los threads
    // en cambio si finalizamos main con pthread_exit, los threads que se estan ejecutando continuan
    // a pesar de que main finalice.
    // esto quiere decir que el proceso sigue vivo (no asi el thread main)
    pthread_exit(NULL);

    // return 0;
}

void *work()
{
    // (3) para simular el "paralelismo"
    int i;
    int j;
    int resto;
    char c = 'X';

    // solo para que en funcion al ultimo digito del thread id, imprima una 'x' o un 'o'
    i = (int)pthread_self();
    resto = i - (i / 10) * 10;
    if (resto > 5)
    {
        c = 'o';
    }

    // con esto puedo visualizar en pantalla el switch task de threads...
    // ejecutar varias veces porque quizas coincide que los dos threas imprimen el mismo caracter
    for (i = 0; i < 100; ++i)
    {
        fprintf(stderr, "%c", c);
        usleep(10000);
    }

    pthread_exit(NULL);
}
