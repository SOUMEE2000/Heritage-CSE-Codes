#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>

pthread_t tid[3];
char *ret[3];
int sum = 0, low, high;

// The function to be executed by all threads 
void *test_thread(void *arg) 
{ 
	unsigned long i = 0;
	char *msg = malloc(16);
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {
        strcpy(msg, "First Done!");
        int i;
         for( i= low; i<= high; i++)
         {
             sum = sum + i;
         }  
	printf("\n Sum Done! by %lu and it is %d called by %lu\n", pthread_self(), sum, tid[0]);
	pthread_exit((void*)msg);
    }
    else if (pthread_equal(id,tid[1]))
    {
	strcpy(msg, "Second Done!\n");
         int n = sum/2;
         int flag = 0, i;
         for(i=2;i<=n;i++) 
         { 
	      if(sum%i==0) 
	      { 
		      printf("\n Second Thread %lu and it is not prime called by %lu\n", pthread_self(), tid[1]); 
		      flag=1; 
		      break; 
	      } 
         } 
      if(flag==0) 
	   printf("\n Second Thread %lu and it is prime\n", pthread_self());
		pthread_exit((void*)msg);
    }
   //else
   //{
    //	printf("\n Third Thread %lu\n", pthread_self());
   //		strcpy(msg, "Third Done!");
		//printf("\n%s",msg);
   //		pthread_exit((void*)msg);
   //}

    for(i=0; i<(0xFFFFFFFF);i++);
} 
  
int main(int argc, char** argv) 
{ 
    int i; 
    pthread_t sid; 
    low = argv[1][0]-'0';
    high = argv[2][0]-'0';
    // Let us create three threads 
    
        int ret = pthread_create(&(tid[0]), NULL, test_thread, (void *)&tid);
	pthread_join(tid[0], (void**)&(ret));
	sid = pthread_self();
	printf("\n This is main thread (%lu): Created %dth thread (%lu)... \n", sid, 1, tid[0]);

        int ret1 = pthread_create(&(tid[1]), NULL, test_thread, (void *)&tid);
        pthread_join(tid[1], (void**)&(ret1));
        sid = pthread_self();
	printf("\n This is main thread (%lu): Created %dth thread (%lu)... \n", sid, 2, tid[1]);

	
	printf ("\nThread %lu said %d", tid[0], ret);
        printf ("\nThread %lu said %d", tid[1], ret1);

	
//	printf ("\n Main Thread %lu exitting.. " , pthread_self());
    return 0; 
}

