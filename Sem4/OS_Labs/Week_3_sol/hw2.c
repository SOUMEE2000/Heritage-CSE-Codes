#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>

pthread_t tid[10];
char *ret[10];
int flag[10]={0};
// The function to be executed by all threads 
void *test_thread(void *arg) 
{ 
	unsigned long i = 0;
	char *msg = malloc(16);
    pthread_t id = pthread_self();
	
    if(pthread_equal(id,tid[0]) && flag[0]==0)
    {
        printf("  1 Thread created with id %lu\n", pthread_self());
        printf("  Hello\n");
		strcpy(msg, "  1 ended");
		flag[0]=1;
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[1]) && flag[1]==0)
    {
        printf("  2 Thread created with id %lu\n", pthread_self());
        printf("  Hello\n");
		strcpy(msg, "  2 ended");
		flag[1]=1;
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
	else if (pthread_equal(id,tid[2]) && flag[2]==0)
	{
		printf("  3 Thread created with id %lu\n", pthread_self());
		printf("  Hello\n");
		strcpy(msg, "  3 ended");
		flag[2]=1;
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
	}
	else if (pthread_equal(id,tid[3]) && flag[3]==0)
    {
        printf("  4 Thread created with id %lu\n", pthread_self());
        printf("  Hello\n");
		strcpy(msg, "  4 ended");
		flag[3]=1;
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[4]) && flag[4]==0)
    {
        printf("  5 Thread created with id %lu\n", pthread_self());
        printf("  Hello\n");
		strcpy(msg, "  5 ended");
		flag[4]=1;
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[5]) && flag[5]==0)
    {
        printf("  6 Thread created with id %lu\n", pthread_self());
        printf("  Hello\n");
		strcpy(msg, "  6 ended");
		flag[5]=1;
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[6]) && flag[6]==0)
    {
        printf("  7 Thread created with id %lu\n", pthread_self());
        printf("  Hello\n");
		strcpy(msg, "  7 ended");
		flag[6]=1;
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[7]) && flag[7]==0)
    {
        printf("  8 Thread created with id %lu\n", pthread_self());
        printf("  Hello\n");
		strcpy(msg, "  8 ended");
		flag[7]=1;
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[8]) && flag[8]==0)
    {
        printf("  9 Thread created with id %lu\n", pthread_self());
        printf("  Hello\n");
		strcpy(msg, "  9 ended");
		flag[8]=1;
		//printf("\n%s",msg);
		pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[9]) && flag[9]==0)
    {
        printf("  10 Thread created with id %lu\n", pthread_self());
        printf("  Hello\n");
		strcpy(msg, "  10 ended");
		flag[9]=1;
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
		else{
			pthread_join(tid[i], (void**)&(ret[i]));
			printf ("%s with id %lu \n", ret[i],tid[i]);
		}
	}
		
	printf ("Main Thread %lu exit\n" , pthread_self());
    return 0; 
} 
