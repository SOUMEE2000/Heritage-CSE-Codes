#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<sys/types.h> 
#include<unistd.h> 
int main() 
{ 
	pid_t p=getpid(); 
	pid_t c=fork(); 
	if(c==0) 
	{ 
		pid_t gc=fork(); 
		if(gc==0) 
		{ 
			printf("Hello I am process with ID %d . My parent is %d and my grandparent is %d. \n", getpid(),getppid(), p);
			exit(0); 
		} 
		int x; 
		wait(&x); 
		printf("\n Hello I am a process with ID %d. My parent is %d and my child is %d ",getpid(),p,gc); 
		exit(gc); 
	} 
	int gc_id; 
	wait(&gc_id); 
	printf("\n Hello I am a process with ID %d. My child is %d and my grandchild is %d . My parent is %d .\n",p,c,WEXITSTATUS(gc_id),getppid()); 
	return 0; 
} 

