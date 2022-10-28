/*
 *	Variables Condicionales
 *
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //sleep

#define NUM_THREADS 3
#define COUNT_LIMIT 12

int count = 0;
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

void *watch_count(void *t);
void *inc_count(void *t);

int main(int argc, char *argv[])
{
	int i, rc;
	long t1 = 1, t2 = 2, t3 = 3;
	pthread_t threads[3];
	pthread_attr_t attr;

	/* Initialize mutex and condition variable objects */
	pthread_mutex_init(&count_mutex, NULL);
	pthread_cond_init(&count_threshold_cv, NULL);

	/* For portability, explicitly create threads in a joinable state */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	pthread_create(&threads[0], &attr, watch_count, (void *)t1);
	pthread_create(&threads[1], &attr, inc_count, (void *)t2);
	pthread_create(&threads[2], &attr, inc_count, (void *)t3);

	printf("Main :: Join thread[0]\n\n");
	pthread_join(threads[0], NULL);

	/* Clean up and exit */
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv);

	printf("Main(): Waited on %d threads. Final value of count = %d. Done.\n", NUM_THREADS, count);

	// pthread_exit (NULL);		// permite que otros threads continuen
	exit(0);
}

void *inc_count(void *t)
{
	int i;
	long my_id = (long)t;

	while (1)
	{
		pthread_mutex_lock(&count_mutex);
		count++;

		if (count == COUNT_LIMIT)
		{
			printf("inc_count(): thread %ld, count = %d  Threshold reached. ", my_id, count);
			pthread_cond_signal(&count_threshold_cv);
			printf("Just sent signal.\n");
		}

		printf("inc_count(): thread %ld, count = %d, unlocking mutex\n", my_id, count);
		pthread_mutex_unlock(&count_mutex);

		/* Do some work so threads can alternate on mutex lock */
		sleep(1);
	} // end while

	pthread_exit(NULL);
}

void *watch_count(void *t)
{
	long my_id = (long)t;

	printf("Starting watch_count(): thread %ld\n", my_id);

	pthread_mutex_lock(&count_mutex);

	if (count < COUNT_LIMIT)
	{
		printf("watch_count(): thread %ld going into wait...\n", my_id);
		pthread_cond_wait(&count_threshold_cv, &count_mutex);
		printf("watch_count(): thread %ld Condition signal received.\n", my_id);
		count += 125;
		printf("watch_count(): thread %ld count now = %d.\n", my_id, count);
	}

	pthread_mutex_unlock(&count_mutex);
	pthread_exit(NULL);
}