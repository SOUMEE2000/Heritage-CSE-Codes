/******************************************************************************

 Memory Requiremnt: n1*n2
 Thought process:i> Store one of the polynomials in a structure
                 ii> Take the other as input but do not store it anywhere. Taking first term, multiply it with all the terms in the first polynomial.
                 iii>Taking each term till the second last term.
                 iv>Take the last term and multiply it in place with the first polynomial stored at the beginning of the array, since the first polynomial is no longer required.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int exponent;
};

int main()
{
    int n1,n2,i,j,coeff,exponent,count=0;
    printf("Please enter number of terms in first polynomial\n");
    scanf("%d",&n1);
    printf("Please enter number of terms in second polynomial\n");
    scanf("%d",&n2);
    
    struct poly *polynomial= (struct poly *)malloc(sizeof(struct poly)*n1*n2);
    
    for(i=0; i<n1*n2; i++)
    {
        polynomial[i].coeff=0;
    }
    
    printf("Enter the first polynomial\n");
    for (i=0; i<n1; i++)
    {
        printf("Enter coeff: ");
        scanf("%d",&polynomial[i].coeff);
        printf("Enter exponent: ");
        scanf("%d",&polynomial[i].exponent);
    }
    
    printf("Enter the second polynomial\n");
    for (i=0; i<n2; i++)
    {
        printf("Enter coefficient: ");
        scanf("%d",&coeff);
        printf("Enter exponent: ");
        scanf("%d",&exponent);
        for(j=0; j<n1; j++)
        {
            printf("%d x %d\n",coeff, polynomial[j].coeff);
            if(count>= n1*n2-n1)
            {
        
                polynomial[j].coeff=polynomial[j].coeff*coeff;
                polynomial[j].exponent=polynomial[j].exponent+exponent;
            }
            else
            {
                polynomial[n1+count].coeff=polynomial[j].coeff*coeff;
                polynomial[n1+count].exponent=polynomial[j].exponent+exponent;
            }
            count= count+1;
        }
    }
    
    for(i=0; i<n1+count-1; i++)
    {
        for(j=i+1; j<n1+count; j++)
        {
            if(polynomial[i].exponent==polynomial[j].exponent && polynomial[j].coeff!=0 && polynomial[i].coeff!=0)
            {
                polynomial[i].coeff+=polynomial[j].coeff;
                polynomial[j].coeff=0;
            }
        }
    }
    
    for(i=0; i<n1+count; i++)
    {
        if(polynomial[i].coeff)
        {
            printf("(%d)x^(%d) +", polynomial[i].coeff, polynomial[i].exponent);
        }
    }
    
    /*for(i=0; i<n1*n2; i++)
    {
        printf("\n%d\n%d\n\n\n",polynomial[i].coeff,polynomial[i].exponent);
    }*/
    free(polynomial);

    return 0;
}
