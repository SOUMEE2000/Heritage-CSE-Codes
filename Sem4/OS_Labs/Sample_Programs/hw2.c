#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<unistd.h> 
#include<pthread.h> 
pthread_t tid[10]; 
char *str[50]; 
int c=1; 
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; 
void* threadCall(void* args) 
{ 
	pthread_t *thd_id = (pthread_t*)args; 
	pthread_mutex_lock(&mutex1); 
	char ch; char *st=(char*)malloc(sizeof(char)*20); 
	pthread_t id=pthread_self(); 
	printf("HELLO says Thread %d with THREAD ID = %lu,Argument Received from Main = %lu\n",c,id,*thd_id); 
	strcat(st,"thread ended"); 
	c++; 
	pthread_mutex_unlock(&mutex1); 
	pthread_exit((void*)st); 
} 

int main()
{ 
	int i; 
	pthread_t sid; 
	sid=pthread_self(); 
	printf("Hello from Main thread with id=%lu\n",sid); 
	for(i=0;i<10;i++) 
	{ 
		if(pthread_create(&(tid[i]),NULL,&threadCall,(void*)&tid[i])) 
		{ 
			perror("pthread_create() error\n"); 
			exit(1); 
		} 
		else 
		{ 
			pthread_join(tid[i],(void**)&(str[i])); 
			printf("%d %s with THREAD ID = %lu has ENDED \n",i+1,str[i],tid[i]); 
		} 
	} 
		printf("Main thread ends with id=%lu\n",sid); 
return 0; 
} 
