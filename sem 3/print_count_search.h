void print(struct node* head)
{
    struct node* change=head;
    while(change->next!=head)
    {
        printf(" %x %d %x      ", change->prev,change->data,&change->data);
        change=change->next;
    }
    printf(" %x %d %x      ", change->prev,change->data,&change->data);
    printf("\n");
}

void count(struct node* head)
{
    struct node* change=head;
    int count=0;
    while(change->next!=head)
    {
        count++;
        change=change->next;
    }
    count++;
    printf("%d", count);
    printf("\n");
}

void search(struct node* head)
{
     struct node* change=head;
    int n;
    printf("Enter value to be searched: ");
    scanf("%d", &n);
    if(head->data==n)
    {
        printf("Value found\n");
        return;
    }
    change=change->next;
    while(change!=head && change->data==n)
    {
        change=change->next;
    }
    if(change==head)
        printf("Value not found");
    else
        printf("value found");
    printf("\n");
}
