#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_t tid[3];

void *test_thread(void* arg)
{
	unsigned long int i = 0;
	pthread_t id = pthread_self();
	
	if(pthread_equal(id, tid[0]))
	{
		printf("I am 0th thread: %lu\n", id);
	}
	else if(pthread_equal(id, tid[1]))
        {
                printf("I am 1st thread: %lu\n", id);
        }
	else if(pthread_equal(id, tid[2]))
	{
	        printf("I am 2nd thread: %lu\n", id);
	}
	pthread_exit(NULL);
}
int main()
{
	int i;
	pthread_t sid;
	for ( i=0; i<3; i++){

 	 	if(pthread_create(&(tid[i]),NULL, test_thread, (void*)&tid))
	 	{
	 		exit(1);
	 	}
	 	sid = pthread_self();
	 	printf("Main thread %lu. Created %dth thread with id %lu\n", sid, i+1, tid[i]);

	}

	pthread_exit(NULL);
	return 0;
}
