  #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <pthread.h>
  
int number, result;
 
  
void* accept_input(void* args){
          pthread_t *call_id=(pthread_t*)args;
          printf("My caller id is:%lu\n",*call_id);
// 	  int number;
          pthread_t sid;
          sid=pthread_self();
          printf("My thread id is:%lu\n",sid);
 
          printf("Enter number: ");
	  scanf("%d", &number);
 
          pthread_exit(NULL);
  }

void* cal_pay(void* args){
          pthread_t *call_id=(pthread_t*)args;
          printf("My caller id is:%lu\n",*call_id);
          pthread_t sid;
          sid=pthread_self();
          result = number + 1500 + 0.18*number;
        // printf("Answer is %d", number); 
          pthread_exit(NULL);
  }

void* display(void* args){
          pthread_t *call_id=(pthread_t*)args;
          printf("My caller id is:%lu\n",*call_id);
          pthread_t sid;
          sid=pthread_self();
          printf("Answer is %d", result); 
          pthread_exit(NULL);
  }
  int main(int args,char *argv[]){
      /*creating thread id*/
      pthread_t id,sid;
      int ret1, ret2, ret3;
      //printf("Enter value:");
      
      sid=pthread_self();
 
      /*creating thread*/
      ret1=pthread_create(&id,NULL,&accept_input,(void*)&sid);
      if(ret1==0){
          printf("1st thread created successfully.\n");
      }
      else{
          printf("Thread not created.\n");
      }
      pthread_join(id, (void**)&(ret1));
 
      printf("My thread id is:%lu\n",sid);
       
      sid=pthread_self();
      ret2=pthread_create(&id,NULL,&cal_pay,(void*)&sid);
      if(ret2==0){
          printf("2nd Thread created successfully.\n");
      }
      else{
          printf("Thread not created.\n");
      }
      pthread_join(id, (void**)&(ret2));
 
      printf("My thread id is:%lu\n",sid);

      sid=pthread_self();
      ret3=pthread_create(&id,NULL,&display,(void*)&sid);
     if(ret3==0){
          printf("3rd Thread created successfully.\n");
      }
      else{
          printf("Thread not created.\n");
      }
      pthread_join(id, (void**)&(ret3));
 
      printf("My thread id is:%lu\n",sid);
     sleep(10);
     

 pthread_exit(NULL);
      return 0;
  }
