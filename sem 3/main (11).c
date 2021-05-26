#include <stdio.h>
#include <stdlib.h>

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
    
    int **matrixOne = (int **)malloc(r1 * sizeof(int *)); 
    for (i=0; i<r1; i++) 
         matrixOne[i] = (int *)malloc(c1 * sizeof(int)); 
  
 
    for (i = 0; i <  r1; i++) 
      for (j = 0; j < c1; j++) 
         matrixOne[i][j]=rand();
    
    int **matrixTwo = (int **)malloc(r2 * sizeof(int *)); 
    for (i=0; i<r2; i++) 
         matrixTwo[i] = (int *)malloc(c2 * sizeof(int)); 
  
 
    for (i = 0; i <  r2; i++) 
      for (j = 0; j < c2; j++) 
         matrixTwo[i][j]=rand();
    
    int **matrixResult = (int **)malloc(r1 * sizeof(int *)); 
    for (i=0; i<r1; i++) 
         matrixResult[i] = (int *)malloc(c2 * sizeof(int)); 
  
 
    for (i = 0; i <  r1; i++) 
      for (j = 0; j < c2; j++) 
          matrixResult[i][j]=0;
    
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
    
    for(i=0; i<r1; i++)
    {
        for (j=0; j<c2; j++)
        {
           printf("%d ",matrixResult[i][j]); 
        }
    
        printf("\n");
    }
    
    return 0;
}
