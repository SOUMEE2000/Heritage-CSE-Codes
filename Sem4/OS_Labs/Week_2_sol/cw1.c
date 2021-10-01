#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
{  
   pid_t pid;
   if ((pid = fork()) > 0) { // parent process
     int i;
     int fact = 1;
     for( i=1; i<=argv[1][0]-'0'; i++)
     {
           fact = fact*i;
     } 
     printf("I am Parent, my ID %d, I have child with ID: %d, My ParentID = %d\nI calculated factorial = %d\n", getpid(), pid, getppid(),fact);
     exit(10);
  } 
		   
  else if (pid == 0) { // child process
      int i;
      int fact = 1;
      int sum = 0;
      for( i=1; i<=argv[1][0]-'0'; i++)
      {
            fact = fact*i;
	    sum = sum + fact;
      }
      printf("I am Child, my ID %d, MY PARENT ID = %d.\n I calculated sum of factorial = %d\n",getpid(),getppid(), sum);
      exit(10);
   }
			      
 else printf("Problem in child creation....\n");
}

