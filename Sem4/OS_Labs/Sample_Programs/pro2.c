#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <string.h> 

int main(int argc, char *argv[]) 
{ 
     int sm;
     sm=atoi(argv[1]); 
     printf("Hello from pro2 my Process ID is %d and the ",getpid()); 
     
     int i; 
     if(n<2) return 0; 
   
     for(i=2;i*i<=sm;i++) 
     { 
           if(sm%i) 
           {
		flag = 1;
		break;
	   }
     } 
      
     if(flag) 
          printf("Sum is Prime\n"); 
     else 
          printf("Sum is Not Prime\n"); 

     return 0; 
} 
