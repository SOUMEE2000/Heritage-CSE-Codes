#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

int main()
{
	int i; 
	pthread_t sid; 
	      
	// Let us create three threads 
	for (i = 0; i < 3; i++) {
	if (pthread_create(&(tid[i]), NULL, test_thread, (void *)&tid)){
		perror ("\npthread_create() error");
		exit(1);
	}
        sid = pthread_self();
	printf("\n This is main thread (%lu): Created %dth thread (%lu)... \n", sid, i+1, tid[i]);
       }
	return 0;
}
