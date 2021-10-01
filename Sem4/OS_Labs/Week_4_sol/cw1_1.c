#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <string.h> 

int main(int argc, char *argv[]) 
{ 
  int sm; char res[10]; 
  pid_t pid; 
  pid=fork(); 
  if(pid==0)
  { 
      printf("I am CHILD PROCESS. ID = %d and PARENT's' ID = %d\n",getpid(),getppid()); 
      execl("pro1","pro1",argv[1],argv[2],(char*)NULL); 
      exit(0); 
   } 
   
  else if(pid>0) 
  { 
     int sum; 
     wait(&sum); 
     sm=WEXITSTATUS(sum); 
     printf("I am PARENT PROCESS. ID = %d and PARENT's ID = %d\n",getpid(),getppid()); 
     sprintf(res ,"%d", sm); 
     execl("pro2","pro2",res,(char*)NULL); 
     exit(0); 
  } 
else 
     printf("Error in Child Creation\n"); 

return 0; 
}
