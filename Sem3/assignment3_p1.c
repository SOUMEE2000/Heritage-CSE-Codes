#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,c,count=0,i,j,k=1,flag=1;
    printf("Enter number of rows and columns\n");
    scanf("%d%d", &r,&c);
    
    int **arr= (int**)malloc(sizeof(int*)*r);
    
    while(flag){
    for(i=0; i<r; i++)
    {
        arr[i]= (int*)malloc(sizeof(int)*c);
        for( j=0; j<c; j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j]!=0)
            count++;
        }
    }
    if(count<= (2*r*c)/3)
    {
        flag=0;
    }
    if(flag==0)
    {
        count=0;
    }
    }
    
    int **trip=(int**)malloc(sizeof(int*)*(count+1));
    trip[0]=(int*)malloc(sizeof(int*)*3);
    trip[0][0]=r;
    trip[0][1]=c;
    trip[0][2]=count;
    
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(arr[i][j]!=0)
            {
                trip[k]=(int*)malloc(sizeof(int)*3);
                trip[k][0]=i;
                trip[k][1]=j;
                trip[k][2]=arr[i][j];
                k++;
            }
        }
    }
    
    printf("Triplet matrix is:\n");
    for(i=0; i<count+1; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ",trip[i][j]);
        }
        printf("\n");
    }
    
    

    return 0;
}
