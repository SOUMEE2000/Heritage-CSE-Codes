/****

Program prints out the number of clock cycles required during matrix multiplication

****/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int flag=0,r1, c1, r2, c2,i,j,k;
    while(!flag)
    {
         printf("Please enter the dimensions of the matrices\n");
         scanf("%d%d", &r1,&c1);
         scanf("%d%d", &r2,&c2);
         if(c1==r2)
            flag=1;
    }
    
    // 1st matrix
    
    int **matrixOne = (int **)malloc(r1 * sizeof(int *)); 
    for (i=0; i<r1; i++) 
         matrixOne[i] = (int *)malloc(c1 * sizeof(int)); 
  
 
    for (i = 0; i <  r1; i++) 
      for (j = 0; j < c1; j++) 
         matrixOne[i][j]=rand();
    
    // 2nd matrix
    
    int **matrixTwo = (int **)malloc(r2 * sizeof(int *)); 
    for (i=0; i<r2; i++) 
         matrixTwo[i] = (int *)malloc(c2 * sizeof(int)); 
  
 
    for (i = 0; i <  r2; i++) 
      for (j = 0; j < c2; j++) 
         matrixTwo[i][j]=rand();
    
    // Resultant matrix
    
    int **matrixResult = (int **)malloc(r1 * sizeof(int *)); 
    for (i=0; i<r1; i++) 
         matrixResult[i] = (int *)malloc(c2 * sizeof(int)); 
  
 
    for (i = 0; i <  r1; i++) 
      for (j = 0; j < c2; j++) 
          matrixResult[i][j]=0;
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();                 //calculating CPU clock cycles for matrix multiplication
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            for (k=0; k<c1; k++)
            {
                matrixResult[i][j]= matrixResult[i][j]+matrixOne[i][k]*matrixTwo[k][i];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start));
    
    for(i=0; i<r1; i++)
    {
        for (j=0; j<c2; j++)
        {
           printf("%d ",matrixResult[i][j]); 
        }
    
        printf("\n");
    }
     printf("%f\n",cpu_time_used/CLOCKS_PER_SEC;);
    
    return 0;
}
