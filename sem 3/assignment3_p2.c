#include <stdio.h>
#include <stdlib.h>

int** create_matrix(int r, int c)
{
    int count=0,i,j,k=1;
    
    int **arr= (int**)malloc(sizeof(int*)*r);
    printf("Enter the elements:\n");
    
    for(i=0; i<r; i++)
    {
        arr[i]= (int*)malloc(sizeof(int)*c);
        for( j=0; j<c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    return arr;
}

int main()
{
    int r1,c1,r2,c2,k=1,i,j,l,flag=0;
    printf("Enter number of  columns\n");
    scanf("%d",&c1);
    int **trip1=create_matrix(c1,3);
    
    printf("Enter number of rows and  columns\n");
    scanf("%d",&c2);
    int **trip2=create_matrix(c2,3);
    
    int **trip_res=(int**)malloc(sizeof(int*)*(c1+c2+1));
    trip_res[0]=(int*)malloc(sizeof(int*)*3);
    trip_res[0][0]=trip1[0][0];
    trip_res[0][1]=trip1[0][1];
    trip_res[0][2]=k;
    
    
    for(i=1; i<c1; i++)
       {
           trip_res[k]=(int*)malloc(sizeof(int)*3);
           for(j=1; j<c2; j++)
           {
               if(trip1[i][0]==trip2[j][0] && trip1[i][1]==trip2[j][1])
               {
                   trip_res[k][0]=trip1[i][0];
                   trip_res[k][1]=trip1[i][1];
                   trip_res[k][2]=trip1[i][2]+trip2[j][2];
                   trip2[j][2]=0;
                   trip1[i][2]=0;
                   k++;
                   flag=1;
                    
               }
           }
           
           if(!flag)
           {
               trip_res[k][0]=trip1[i][0];
               trip_res[k][1]=trip1[i][1];
               trip_res[k][2]=trip1[i][2];
               k++;
               flag=0;
                
           }
       }

       for(j=1; j<c2; j++)
       {
           trip_res[k]=(int*)malloc(sizeof(int)*3);
           if(trip2[j][2])
           {
               trip_res[k][0]=trip2[j][0];
               trip_res[k][1]=trip2[j][1];
               trip_res[k][2]=trip2[j][2];
               k++;
           }
       }
    
    
      //Row sorting
       for(i=1;i<k-1; i++)
       {
           for(j=i+1; j<k;j++)
           {
               if(trip_res[i][0]>trip_res[j][0])
               {
                   int temp= trip_res[i][0];
                   trip_res[i][0]=trip_res[j][0];
                   trip_res[j][0]=temp;
                   
                   temp= trip_res[i][1];
                   trip_res[i][1]=trip_res[j][1];
                   trip_res[j][1]=temp;
                   
                   temp= trip_res[i][2];
                   trip_res[i][2]=trip_res[j][2];
                   trip_res[j][2]=temp;
               }
           }
       }
       
       for(i=1; i<k; i++)
       {
           int val=0;
           for(j=1; j<c1; j++)
           {
               if(trip_res[i][0]==trip_res[j][0])
               {
                   val++;
               }
               else
               break;
           }
           //second col sorting
           for(j=i; j<val+i-2; j++)
           {
               for(l=j+1; l<val+i-1;l++)
               {
                   if(trip_res[j][1]<trip_res[l][1])
                  {
                      int temp= trip_res[j][0];
                      trip_res[j][0]=trip_res[l][0];
                      trip_res[l][0]=temp;
                      
                      temp= trip_res[j][1];
                      trip_res[j][1]=trip_res[l][1];
                      trip_res[l][1]=temp;
                      
                      temp= trip_res[j][2];
                      trip_res[j][2]=trip_res[l][2];
                      trip_res[l][2]=temp;
                  }
               }
           }
       }
       trip_res[0][2]=k-1;
       printf("\nAnswer:\n");
       for(i=0; i<k; i++)
       {
           printf("%d %d %d\n",trip_res[i][0],trip_res[i][1],trip_res[i][2]);
       }
      free(trip1);
      free(trip2);
      free(trip_res);
   return 0;
}