#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node
{
    int data;
    struct node * next;
};

struct node* new_node()
{
    int n;
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&n);
    temp->data=n;
    temp->next=NULL;
    return temp;
}

void isfull(struct node* head)
{
    int count=0;
    struct node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
        if(count>MAX)
        {
            printf("Stack overflow\n");
            break;
        }
    }
}
struct node * push(struct node* head)
{
    struct node *change=head, *temp;
    if(head==NULL)
    {
        temp=new_node();
        head=temp;
    }
    else
    {
        temp=new_node();
        while(change->next!=NULL)
        {
            change=change->next;
        }
        change->next=temp;
    }
    return head;
}

struct node* pop(struct node* head)
{
    struct node *change=head, *temp;
    if(head==NULL)
    {
        printf("Stack undeflow.\n");
    }
    else if(head->next==NULL)
    {
        printf("%d is popped.\n", head->data);
        head=NULL;
    }
    else
    {
        while(change->next->next!=NULL)
        {
            change=change->next;
        }
        printf("%d is popped.\n", change->next->data);
        change->next=NULL;
    }
    return head;
}

void peek(struct node* head)
{
    struct node *change=head, *temp;
    if(head==NULL)
    {
        printf("Stack underflow.\n");
    }
    else
    {
        while(change->next!=NULL)
        {
            change=change->next;
        }
        printf("%d",change->data);
    }
}

int isempty(struct node*head)
{
    if(head==NULL)
    {
        printf("Stack is empty.\n");
        return 1;
    }
    else
        return 0;
}


void print(struct node* head)
{
    struct node* change=head;
    while(change!=NULL)
    {
        printf("%d  ",change->data);
        change=change->next;
    }
    printf("\n");
}
int main()
{
    int option=0,is_empty;
    struct node* head=NULL;
    do
    {
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option)
        {
              case 1: head=push(head);
                      break;
              case 2: head= pop(head);
                      break;
              case 3: peek(head);
                      break;
              case 4: print(head);
                      break;
              case 5: is_empty=isempty(head);
                      break;
              case 6: isfull(head);
                      break;
        }
        printf("Enter 1 to continue , 0 to exit: ");
        scanf("%d",&option);
    }while(option);
    free(head);
    return 0;
}

