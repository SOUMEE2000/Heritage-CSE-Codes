/******************************************************************************
Thought process: i> Modify array so that only the even positioned elements remain
                 ii> Sort modified array.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,temp;
    printf("No. of elements: ");
    scanf("%d", &n);
    int store=n;
    
    int *arr= (int*)malloc(sizeof(int)*n);
    
    printf("The elements:\n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(i=0; i<n; i++)
    {
        if(i%2!=0)
        {
            arr[i/2]=arr[i];
            store--;
        }
    }
    
    if(n%2!=0)
    n=store-1;
    else
    n=store;
    
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    for(i=0; i<n; i++)
    printf("%d ",arr[i]);
    
    free(arr);
    return 0;
}
