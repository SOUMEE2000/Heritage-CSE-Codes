#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	//pid = fork();
        int retval;
        int exitstatus;

	if(( pid=fork()) >= 0) {
	if( pid == 0)
	{
		printf("Enter a number\n");
		scanf("%d",&retval);
		exit(retval);
	}
	else if(pid > 0)
	{
		wait(&exitstatus);
		printf("Child returned: %d\n", WEXITSTATUS(exitstatus));
	}

	}
	return 0;
}
