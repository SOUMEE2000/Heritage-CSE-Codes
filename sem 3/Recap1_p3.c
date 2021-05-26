/******************************************************************************
 Diagonal matrix: when elements not in the principal diagonal are zero and the diagonal elements may or may not be zero.
 Identity matrix: when principal diagonal elemnts are 1.


 Thought process: i> Check if non diagonal elements are zero or not.
                  ii> If they are not then automatically it is neither a diagonal nor an identity matrix. return 0.
                  iii> If they are check the diagonal elements
                  iv> If diagonal elements have any other value than 1 then it is a diagonal matrix. 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, flag=0;
    printf("No.of elemnts: ");
    scanf("%d",&n);
    int **arr= (int**)malloc(sizeof(int*)*n);
    
    printf("The elements:\n");
    for(i=0; i<n; i++)
    {
        arr[i]= (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    
    
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j && arr[i][j]!=0)
            {
                printf("Neither an identity matrix nor a diagonal matrix\n");
                return 0;
            }
            
            if(i==j)
            {
                if(arr[i][j]!=1)
                flag=1;
            }
        }
    }
    
    if(flag)
    {
        printf("Diagonal matrix\n");
    }
    else
    {
        printf("Identity matrix\n");
    }
    
    free(arr);
    return 0;
}
