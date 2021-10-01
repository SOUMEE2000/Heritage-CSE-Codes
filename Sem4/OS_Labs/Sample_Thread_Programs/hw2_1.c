#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int ret[3];
pthread_t tid[3];
int flag = 0;

void *test_thread(void *arg) 
{ 
   unsigned long i = 0;
   char *msg = malloc(16);
   pthread_t id = pthread_self();
   printf("\n %d Thread %lu\n", flag, pthread_self());
   printf(" %d Done.\n",flag);

	for(i=0; i<(0xFFFFFFFF);i++){};
   pthread_exit(NULL);
} 
int main()
{

//	ret[0] = pthread_create(&(tid[0]), NULL, test_thread, (void *)&tid);
 //       pthread_join(tid[0], (void**)&(ret[0]));
//	flag = 1;
 //       ret[1] = pthread_create(&(tid[1]), NULL, test_thread, (void *)&tid);
//	pthread_join(tid[1], (void**)&(ret[0]));

	int i;
	for( i=0; i<3; i++)
	{
	       flag = i;
	       ret[i] = pthread_create(&(tid[i]), NULL, test_thread, (void *)&tid);
	}
	for(i=0; i<3; i++)
	{
	       pthread_join(tid[i], (void**)&(ret[i]));
	}
	return 0;
}
