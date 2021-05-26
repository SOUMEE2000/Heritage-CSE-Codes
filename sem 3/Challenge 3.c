
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, ,1;
    scanf("%d",&n1);
    int **trip1= (int**)malloc(sizeof(int*)*n1);
    for(i=0; i<n1; i++)
    {
        trip1= (int*)malloc(sizeof(int*)*3);
        scanf("%d%d%d", &trip1[i][0], &trip1[i][1], &trip1[i][2]);
    }


    scanf("%d",&n2);
    int **trip2= (int**)malloc(sizeof(int*)*n2);
    for(i=0; i<n2; i++)
    {
        trip2= (int*)malloc(sizeof(int*)*3);
        scanf("%d%d%d", &trip2[i][0], &trip2[i][1], &trip2[i][2]);
    }

    //transposing the second matrix

    for(i=0; i<n2; i++)
    {
        int temp=trip2[i][0];
        trip2[i][0]=trip2[i][1];
        trip2[i][1]=temp;
    }
    int ** result= (int**)malloc(sizeof(int*)*(n1+n2+1));
    result[0]=(int*)malloc(sizeof(int)*3);
    result[0][0]=trip1[0][0];
    result[0][0]=trip2[0][0];

    for(i=1; i<n1; i++)
    {
        result[k]=(int*)malloc(sizeof(int)*3);
        for(j=1; j<n2; j++)
        {
            if(trip1[i][1]==trip2[j][0])
            {
                result[k][2]=trip1[i][2]*trip2[j][2];
                result[k][0]=trip1[0]
            }
        }
        k++;

    }
    return 0;
}

