/*
 *	Devolver un valor
 *	Atributos en los threads, concepto de join y detach
 *	pthread_exit ( diferencia en el main y en otro thread )
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h> //sleep
#include <pthread.h>

typedef struct _argument
{
	int i;
	char c;
} ARGUMENT;

void *worker(void *unused);

void SetArgs(ARGUMENT *, int, char);

int main(int argc, char **argv)
{

	int rc;

	pthread_t thread1_id;
	pthread_t thread2_id;

	pthread_attr_t attr;

	ARGUMENT args1;
	ARGUMENT args2;

	int x = 10;
	int y = 10;

	int i;
	int ch1;

	int r1 = 0;
	int r2 = 0;

	while ((ch1 = getopt(argc, argv, "x:y:")) != -1)
	{
		switch (ch1)
		{
		case 'x':
			x = atoi(optarg);
			break;
		case 'y':
			y = atoi(optarg);
			break;
		default:
			x = 10;
			y = 10;
		}
	}

	fprintf(stderr, "Main :: start...(x,y)=(%d,%d)\n", x, y);

	SetArgs(&args1, x, 'X');
	SetArgs(&args2, y, 'O');

	pthread_attr_init(&attr);

	/*
	 * Si pasamos NULL, el valor por defecto es PTHREAD_CREATE_JOINABLE
	 */
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	rc = pthread_create(&thread1_id, &attr, &worker, &args1);

	if (rc != 0)
	{
		fprintf(stderr, "ERROR; return code from pthread_create() is %d\n", rc);
		exit(-1);
	}
	else
	{
		fprintf(stderr, "INFO; pthread_create() asign thread_id %ld\n", thread1_id);
	}

	rc = pthread_create(&thread2_id, &attr, &worker, &args2);

	if (rc != 0)
	{
		fprintf(stderr, "ERROR; return code from pthread_create() is %d\n", rc);
		exit(-1);
	}
	else
	{
		fprintf(stderr, "INFO; pthread_create() asign thread_id %ld\n", thread2_id);
	}

	int *rr1, *rr2;
	pthread_join(thread1_id, (void *)&r1);
	pthread_join(thread2_id, (void *)&r2);
	// pthread_join(thread1_id, (void *)rr1);
	// pthread_join(thread2_id, (void *)rr2);

	pthread_attr_destroy(&attr);

	fprintf(stderr, "Main :: end (r1,r2) = (%d,%d)!\n", r1, r2);

	return 0;
}

void *worker(void *p)
{

	ARGUMENT *args = (ARGUMENT *)p;
	int i;

	for (i = 0; i < args->i; ++i)
		fputc(args->c, stderr);

	pthread_exit((void *)&(args->i));
}

void SetArgs(ARGUMENT *p, int i, char c)
{

	p->i = i;
	p->c = c;
}
