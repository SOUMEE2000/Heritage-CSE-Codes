#include <stdio.h>
#include <stdlib.h>

struct people
{
    char name[10];
    char acc[10];
    int balance;
};

void balance(struct people people[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if (people[i].balance<200)
        {
            printf("%s\n",people[i].name);
        }
    }
}

void add(struct people people[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(people[i].balance>1000)
        {
            people[i].balance+=100;
            printf("100 added to %s\n", people[i].name);
        }
    }
}

int main()
{
    int n,i;
    printf("Number of people:\n");
    scanf("%d",&n);
    struct people *people= (struct people*)malloc(sizeof(struct people)*n);
    
    for(i=0; i<n; i++)
    {   
        getchar();
        printf("Enter name\n");
        scanf("%[^\n]s",people[i].name);
        getchar();
        printf("Enter account\n");
        scanf("%[^\n]s",people[i].acc);
        getchar();
        printf("Enter balance\n");
        scanf("%d", &people[i].balance);
    }
    
    printf("People who have less than 200 in their accounts:\n");
    balance(people,n);
    printf("People with balance more than 1000:\n");
    add(people,n);
    free(people);
    return 0;
}
