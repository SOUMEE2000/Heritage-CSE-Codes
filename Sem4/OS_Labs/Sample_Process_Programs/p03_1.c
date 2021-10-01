#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();

	if(pid > 0)
	{
		printf("\nI am parent. Fork() = %d, process_id = %d, parent_id = %d\n", pid, getpid(), getppid());
	}
	else if(pid == 0)
	{
	        printf("\nI am child. Fork() = %d, process_id = %d, parent_id = %d\n", pid, getpid(), getppid());
		sleep(10);
		printf("\nI am child. Fork() = %d, process_id = %d, parent_id = %d\n", pid, getpid(), getppid());
	}
	return 0;
}
