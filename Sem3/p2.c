#include <stdlib.h>
#include <stdio.h>

int main()
{
    // n is the size of the array


    int n;
    scanf("%d", &n);
    int *arr= malloc(sizeof(int)*n);
    int i;        
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);

    for(i=0; i<n/2; i++)
    {
        arr[i]=arr[i]+arr[n-1-i];
        arr[n-1-i]=arr[i]-arr[n-1-i];
        arr[i]=arr[i]-arr[n-1-i];
    }

    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    free(arr);
    return 0;
}
