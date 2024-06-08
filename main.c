#include <stdio.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

long count;
sem_t *var;
pthread_t thread[4];


void *routine(void *param)
{
	sem_wait(var);
	sleep(1);
	printf("hello %ld\n", count++);
	sem_post(var);
	return NULL;
}

int main()
{
	int i = 0;

	var = sem_open("/mehdi", 0644, 1);
	if (!var )
	{
		printf("jdgjfhdjhkjfhgjhfjkhg\n");
	}
	while (i < 4)
	{
		pthread_create(&thread[i], NULL, &routine, NULL);
		i++;
	}
	while (1)
	{
		/* code */
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	
}