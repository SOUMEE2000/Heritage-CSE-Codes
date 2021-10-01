#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<math.h> 
int main(int argc, char **argv) 
{ 
	int min=atoi(argv[1]), max=atoi(argv[2]); 
	pid_t p1 = fork(); 
	if(p1==0) 
	{ 
		int sum =0, i; 
		for(i=min;i<=max;i++) 
		{ 
			if(i%2==0) 
			{ 
				printf("\n %d is even. ",i); 
				sum+=i; 
			} 
			else printf("\n %d is odd. ",i); 
		} 
		printf("\nI am a child process with id %d. I was checking for odd and even. My parent is %d \n\n\n\n",getpid(),getppid()); 
	        exit(sum); 
	} 
	int esum; 
	wait(&esum); 
	pid_t p2=fork(); 
	if(p2==0) 
	{ 
		int sum=0; 
		int i,j; 
		for(i=min;i<=max;i++) 
		{ 
			int n=i/2; 
			int f=0; 
			for(j=2;j<=n;j++) 
			{ 
				if(i%j==0) 
				{ 
					f=1; 
					break; 
				} 
			} 
			if(f) printf("\n %d is not prime.",i); 
			else 
			{ 
				printf("\n %d is prime . ",i); 
				sum+=i; 
			} 
		} 
		printf("\n I am a child process checking for prime and non prime. My process id is %d.My parent is %d.\n\n\n\n\n",getpid(),getppid()); 
		exit(sum); 
	} 
	int psum; 
	wait(&psum); 
	printf("\n Hello I am parent process with process id %d. My parent is %d. My children are %d and %d. \nI am printing sum of even and primes. Sum of even numbers is %d.Sum of prime numbers is %d\n. ",getpid(),getppid(),p1,p2,WEXITSTATUS(esum),WEXITSTATUS(psum));
	return 0; 
} 

