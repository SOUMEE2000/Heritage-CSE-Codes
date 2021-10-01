#include<stdio.h>
#include<limits.h>

int bracket[10000][10000];
int m[10000][10000];
void printParenthesis (int i, int j)
{
// If only one matrix left in current segment
  if (i == j)
    {
      printf ("A%d", i);
    }
  else
    {
      printf ("(");
      printParenthesis (i, bracket[i][j]);
      printParenthesis ((bracket[i][j] + 1), j);
      printf (")");
    }
}

void MatrixChainMultiplication (int p[], int n)
{


  int i, j, k, L, q;

  for (i = 1; i < n; i++)
    m[i][i] = 0; //number of multiplications are 0(zero) when there is only one matrix

  //Here L is chain length. It varies from length 2 to length n.
  for (L = 2; L < n; L++)
    {
      for (i = 1; i < n - L + 1; i++)
         {
             j = i + L - 1;
             m[i][j] = INT_MAX; //assigning to maximum value

             for (k = i; k <= j - 1; k++)
              {
                   q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                   if (q < m[i][j])
                     {
                         m[i][j] = q; //if number of multiplications found less that number will be updated.
                         bracket[i][j] = k;
                     }
               }
                printf ("\n");
           }
    }

  printf ("\nOptimal Parenthesization is : ");
  printParenthesis (1, n - 1);
  printf ("\nMinimum number of multiplications is %d ", m[1][n - 1]); //returning the final answer which is M[1][n]
  printf ("\nM matrix is: \n\n");

  for (i = 1; i < n; i++)
    {
      for (j = 1; j < n; j++)
      {
           if (i > j)
           printf ("-\t ");
           else
           printf ("%d\t ", m[i][j]);
      }
      printf ("\n");
    }

  printf ("\nS matrix is: \n\n");
  for (i = 1; i < n; i++)
    {
      for (j = 1; j < n; j++)
        {
            if (i > j)
            printf ("-\t ");
            else
            printf ("%d\t ", bracket[i][j]);
        }
            printf ("\n");
    }

}

int
main ()
{
  int n, i;
  printf ("Enter number of matrices\n");
  scanf ("%d", &n);

  n++;

  int arr[n];

  printf ("Enter dimensions \n");

  for (i = 0; i < n; i++)
    {
      printf ("Enter d%d :: ", i);
      scanf ("%d", &arr[i]);
    }

  int size = sizeof (arr) / sizeof (arr[0]);
  MatrixChainMultiplication (arr, size);
  return 0;
}
