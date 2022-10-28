/*
 * Ejemplo 002:
 * 	Creacion  de un thread
 *  Threads con datos compartidos ( shared data )
 *
 *	Compilacion
 *		gcc 002_pthread.c -o test -l pthread
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

	for (i = 0; i < *args; ++i)
	{
		j = gCounter;
		j++;
		fprintf(stderr, ".");
		gCounter = j;
	}

	fprintf(stderr, "INFO; worker %ld end\n", pthread_self());
	pthread_exit(NULL);
}