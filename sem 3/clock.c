/* Using a clock to calculat time. Interestingly enough for matrices number of comparisons for 2d matrices follow a pattern.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int flag=0,r1, c1, r2, c2,i,j,k, count=0;
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
         matrixOne[i][j]=rand()%1000;
    
    int **matrixTwo = (int **)malloc(r2 * sizeof(int *)); 
    for (i=0; i<r2; i++) 
         matrixTwo[i] = (int *)malloc(c2 * sizeof(int)); 
  
 
    for (i = 0; i <  r2; i++) 
      for (j = 0; j < c2; j++) 
         matrixTwo[i][j]=rand()%1000;
    
    int **matrixResult = (int **)malloc(r1 * sizeof(int *)); 
    for (i=0; i<r1; i++) 
         matrixResult[i] = (int *)malloc(c2 * sizeof(int)); 
  
 
    for (i = 0; i <  r1; i++) 
      for (j = 0; j < c2; j++) 
          matrixResult[i][j]=0;
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for(i=0; i<r1; i++)
    { count++;
        for(j=0; j<c2; j++)
        {count++;
            for (k=0; k<c1; k++)
            {count++;
                matrixResult[i][j]+=+matrixOne[i][k]*matrixTwo[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start));
    
    /*for(i=0; i<r1; i++)
    {
        for (j=0; j<c2; j++)
        {
           printf("%d ",matrixResult[i][j]); 
        }
    
        printf("\n");
    }*/
     printf("Time taken %f\n",cpu_time_used/CLOCKS_PER_SEC);
     printf("No. of comparisons %d",count);
free(matrixOne);
free(matrixTwo);
free(matrixResult);
    return 0;
}
