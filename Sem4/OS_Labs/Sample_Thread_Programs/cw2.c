#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

int number;
pthread_t tid[2];
// The function to be executed by all threads 
void *test_thread(void *arg) 
{ 
	unsigned long i = 0;
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {
        
        int i;
        int fact = 1;
        for( i=1; i<=number; i++)
        {
             fact = fact*i;
        } 
        printf("\n First Thread %lu and factorial is %d\n", pthread_self(), fact);
    }
    else if (pthread_equal(id,tid[1]))
    {
        int i;
        int fact = 1;
        int sum = 0;
        for( i=1; i<=number; i++)
        {
             fact = fact*i;
	     sum = sum + fact;
        }
        printf("\n Second Thread %lu and sum is %d", pthread_self(), sum);
    }
    
    for(i=0; i<(0xFFFFFFFF);i++);
} 
  
int main(int argc, char** argv) 
{ 
    int i; 
    pthread_t sid; 
    number = argv[1][0] - '0';
    // Let us create three threads 
    for (i = 0; i < 2; i++) {
        if (pthread_create(&(tid[i]), NULL, test_thread, (void *)&tid)){
			perror ("\npthread_create() error");
			exit(1);
		}
        sid = pthread_self();
		printf("\n This is main thread (%lu): Created %dth thread (%lu)... \n", sid, i+1, tid[i]);
	}
    
    sleep(5);	
    return 0; 
} 
