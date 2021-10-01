#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("Hello\n");
	fork();
	printf("Hello\n");
	fork();
	printf("Hello\n");
	fork();
	return 0;
}
