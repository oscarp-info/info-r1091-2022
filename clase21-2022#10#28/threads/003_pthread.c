/*
 * Ejemplo 003:
 * 	Creacion  de un thread
 *  Threads con datos compartidos ( shared data )
 *  Sync ( mutex,  definicion de zona critica )
 *
 *	Compilacion
 *		gcc 003_pthread.c -o test -l pthread
 *
 * El contador global deberia ser 200 al finalizar la ejecucion. Que sucede ?
 *
 */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
 * Prototypes
 */
void *worker(void *);

/*
 * Global counter
 */
int gCounter;
pthread_mutex_t mtxgCounter;

int main(void)
{
	pthread_t thread1_id;
	pthread_t thread2_id;
	int args1, args2;
	int r1, r2;
	int rc;
	gCounter = 0;
	args1 = 100;
	args2 = 100;

	/*
	 * Inicializacion del  mutex
	 */
	pthread_mutex_init(&mtxgCounter, NULL);

	/*
	 * Launch thread 1)
	 */

	rc = pthread_create(&thread1_id, NULL, worker, &args1);
	if (rc != 0)
	{
		fprintf(stderr, "ERROR; return code from pthread_create() is %d\n", rc);
		exit(-1);
	}
	else
	{
		fprintf(stderr, "INFO; pthread_create(1) asign thread_id %ld\n", thread1_id);
	}

	/*
	 * Launch thread 2)
	 */
	rc = pthread_create(&thread2_id, NULL, worker, &args2);
	if (rc != 0)
	{
		fprintf(stderr, "ERROR; return code from pthread_create() is %d\n", rc);
		exit(-1);
	}
	else
	{
		fprintf(stderr, "INFO; pthread_create(2) asign thread_id %ld\n", thread2_id);
	}

	/*
	 * Wait worker threads finish
	 */
	pthread_join(thread1_id, (void *)&r1);
	fprintf(stderr, "INFO; Finalizo el thread (1)\n");
	pthread_join(thread2_id, (void *)&r2);
	fprintf(stderr, "INFO; Finalizo el thread (2)\n");

	/*
	 * Print global counter "gCounter"
	 */
	fprintf(stderr, "INFO; Global counter is %d\n", gCounter);

	/*
	 * Exit and cleanup threads
	 */
	exit(0);
}

void *worker(void *p)
{

	int *args = (int *)p;
	int i;
	int j;
	char c = 'x';
	int resto;

	/*
	 * Solo para que en funcion al ultimo digito del thread id, imprima una 'x' o un 'o'
	 */
	i = (int)pthread_self();
	resto = i - (i / 10) * 10;
	if (resto > 5)
	{
		c = 'o';
	}

	for (i = 0; i < *args; ++i)
	{

		pthread_mutex_lock(&mtxgCounter);
		// ingreso a la zona critica
		j = gCounter;
		j++;
		fprintf(stderr, "%c", c);
		gCounter = j;
		pthread_mutex_unlock(&mtxgCounter);
		// salgo de la zona critica
	}

	fprintf(stderr, "INFO; worker %ld end\n", pthread_self());
	pthread_exit(NULL);
}