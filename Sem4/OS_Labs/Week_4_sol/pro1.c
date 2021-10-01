#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <string.h> 
int main(int argc, char *argv[]) 
{ 
  int i,sm=0; 
  int l,h; 
  l=atoi(argv[1]); 
  h=atoi(argv[2]); 
  
  for(i=l;i<=h;i++) 
  { 
       sm+=i; 
   } 
  printf("Hello from pro1 my Process ID is %d and sum is = %d\n",getpid(),sm); 
  return sm; 
} 
