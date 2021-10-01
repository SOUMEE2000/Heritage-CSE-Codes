#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>

int res_sum = 0;
int stat;

int main(int argc, char** argv)
{
   pid_t pid;
   int sum = 0;
   if ((pid = fork()) > 0) {
  // execl("pro2", "pro2", "5", "10", (char*)NULL);
   pid_t cpid = waitpid(pid, &stat, 0);
   if (WIFEXITED(stat))
        printf("%d", WEXITSTATUS(stat));

   execl("pro2", "pro2", (char*)NULL);
   exit(10);
   }

   else if (pid == 0) { // child process
     int i;
    // execl("pro2", "pro2", (char*)NULL);
     execl("pro1", "pro1", "5", "10", (char*)NULL);  
     exit(10);

   }

  else printf("Problem in child creation....\n");
}
