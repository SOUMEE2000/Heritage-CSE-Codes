#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char** argv)
{
   pid_t pid;
   int sum = 0;
   if ((pid = vfork()) > 0) { // parent process
      int n = sum/2;
      int flag = 0, i;
      for(i=2;i<=n;i++) 
      { 
	      if(sum%i==0) 
	      { 
		      printf("\n %d is not prime. ", sum); 
		      flag=1; 
		      break; 
	      } 
      } 
      if(flag==0) 
	      printf("\n %d is prime. ",sum);

      printf("I am Parent, my ID %d, I have child with ID: %d, My ParentID = %d\nI check whether %d is prime or not\n", getpid(), pid, getppid(),sum);
      exit(10);
   }

   else if (pid == 0) { // child process
     int i;
     for( i= argv[1][0] - '0'; i<=argv[2][0]-'0'; i++)
     {
         sum = sum + i;
     }
     printf("I am Child, my ID %d, MY PARENT ID = %d.\n I calculate sum = %d",getpid(),getppid(), sum);
     exit(10);

   }

  else printf("Problem in child creation....\n");
}
