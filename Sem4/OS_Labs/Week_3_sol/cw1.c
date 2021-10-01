#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
        
int nums;
int factorial(int n){
	int i,fact=1;
	for(i=1;i<=n;i++){
		fact*=i;
	}
	return fact;
}

/*factorial function definition*/
void* threadFunction(void* args){
	pthread_t *call_id=(pthread_t*)args;
	printf("My caller id is:%lu\n",*call_id);
	
	pthread_t sid;
	sid=pthread_self();
	printf("My thread id is:%lu\n",sid);
	
    int fact=factorial(nums);
	
	printf("Factorial is:%d\n",fact);
	
	pthread_exit(NULL);
}
int main(int args,char *argv[]){
    /*creating thread id*/
    pthread_t id,sid;
    int ret;
    //printf("Enter value:");
    nums=atoi(argv[1]);
    
    sid=pthread_self();
    
    /*creating thread*/
    ret=pthread_create(&id,NULL,&threadFunction,(void*)&sid);
    if(ret==0){
        printf("Thread created successfully.\n");
    }
    else{
        printf("Thread not created.\n");
    }
    
    printf("My thread id is:%lu\n",sid);
    
    //sum of factorials
    int sum=0;
    for(int i=1;i<=nums;i++){
    	sum+=factorial(i);
	}
    printf("The sum is: %d\n",sum);
    
    pthread_exit(NULL);
    return 0;
}
