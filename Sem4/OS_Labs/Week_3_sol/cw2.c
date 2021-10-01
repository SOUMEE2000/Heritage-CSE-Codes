#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
        
int low,high,sum=0;
int isPrime(int sum){
	if(sum<2){
		return 0;
	}
	for(int i=2;i<=sum/2;i++){
		if(sum%i==0){
			return 0;
		}
	}
	return 1;
}

/*factorial function definition*/
void* sumofNumbers(void* args){
	pthread_t *call_id=(pthread_t*)args;
	printf("My caller id is:%lu\n",*call_id);
	
	pthread_t sid;
	sid=pthread_self();
	printf("My thread id is:%lu\n",sid);
	
    for(int i=low;i<=high;i++){
    	sum+=i;
	}
	
	printf("The sum is:%d\n",sum);
	
	pthread_exit(NULL);
}
int main(int args,char *argv[]){
    /*creating thread id*/
    pthread_t id,sid;
    int ret;
    //printf("Enter value:");
    low=atoi(argv[1]);
    high=atoi(argv[2]);
    
    sid=pthread_self();
    
    /*creating thread*/
    ret=pthread_create(&id,NULL,&sumofNumbers,(void*)&sid);
    if(ret==0){
        printf("Thread created successfully.\n");
    }
    else{
        printf("Thread not created.\n");
    }
    pthread_join(id, (void**)&(ret));
    
    printf("My thread id is:%lu\n",sid);
    
    //check prime
    if(isPrime(sum)){
    	printf("My sum is prime.\n");
	}
	else{
		printf("My sum is not prime.\n");
	}
    
    
    pthread_exit(NULL);
    return 0;
}
