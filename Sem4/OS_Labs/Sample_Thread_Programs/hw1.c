#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>

pthread_t tid[10];
char *ret[10];

// The function to be executed by all threads 
void *test_thread(void *arg) 
{ 
	unsigned long i = 0;
	char *msg = malloc(16);
    pthread_t id = pthread_self();
	
    if(pthread_equal(id,tid[0]))
    {
        printf("  1 Thread created with id %lu\n", pthread_self());
//        printf("  Hello\n");
		strcpy(msg, "  1 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[1]))
    {
        printf("  2 Thread created with id %lu\n", pthread_self());
//        printf("  Hello\n");
		strcpy(msg, "  2 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
	else if (pthread_equal(id,tid[2]))
	{
		printf("  3 Thread created with id %lu\n", pthread_self());
//		printf("  Hello\n");
		strcpy(msg, "  3 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
	}
	else if (pthread_equal(id,tid[3]))
    {
        printf("  4 Thread created with id %lu\n", pthread_self());
  //      printf("  Hello\n");
		strcpy(msg, "  4 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[4]))
    {
        printf("  5 Thread created with id %lu\n", pthread_self());
//        printf("  Hello\n");
		strcpy(msg, "  5 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[5]))
    {
        printf("  6 Thread created with id %lu\n", pthread_self());
//        printf("  Hello\n");
		strcpy(msg, "  6 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[6]))
    {
        printf("  7 Thread created with id %lu\n", pthread_self());
 //       printf("  Hello\n");
		strcpy(msg, "  7 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[7]))
    {
        printf("  8 Thread created with id %lu\n", pthread_self());
//        printf("  Hello\n");
		strcpy(msg, "  8 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[8]))
    {
        printf("  9 Thread created with id %lu\n", pthread_self());
 //       printf("  Hello\n");
		strcpy(msg, "  9 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else
    {
        printf("  10 Thread created with id %lu\n", pthread_self());
		strcpy(msg, "  10 ended");
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }

    for(i=0; i<(0xFFFFFFFF);i++);
} 
  
int main() 
{ 
    int i; 
    pthread_t sid; 
  	sid = pthread_self();
  	printf("\nThe main thread created with id %lu\n",sid);
  		
    // Let us create three threads 
    for (i = 0; i < 10; i++) {
        if (pthread_create(&(tid[i]), NULL, test_thread, (void *)&tid)){
			perror ("\npthread_create() error");
			exit(1);
		}
	}
    for(int i=0;i<10;i++){
		pthread_join(tid[i], (void**)&(ret[i]));
	}
    
    for(int i=0;i<10;i++){
    	printf ("\n%s with id %lu ", ret[i],tid[i]);	
	}
	
//    printf ("\nThread %lu said %s", tid[1], ret[1]);
//	printf ("\nThread %lu said %s", tid[2], ret[2]);
	
	printf ("\nMain Thread %lu exit\n" , pthread_self());
    return 0; 
}
