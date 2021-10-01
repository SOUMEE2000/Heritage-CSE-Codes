#include <stdio.h>
#include <stdlib.h>
#include "create.h"
#include "insert.h"
#include "delete.h"
#include "print_count_search.h"

int main()
{
    struct node* head=NULL;
    int option=0;
    char choice;
    do
    {
        printf("Enter option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("Enter choice: ");
                    getchar();
                    scanf("%c",&choice);
                    switch(choice)
                    {
                        case 'a': head=list_n_nodes(head);
                                  break;
                        case 'b': head=list_by_user(head);
                                  break;
                    }
                    break;
            case 2: printf("Enter choice: ");
                    getchar();
                    scanf("%c",&choice);
                    switch(choice)
                    {
                        case 'a': head= ins_at_beg(head);
                                  break;
                        case 'b': head= ins_at_end(head);
                                  break;
                        case 'c': head= ins_at_n_pos(head);
                                  break;
                        case 'd': head= ins_after_n_val(head);
                                  break;
                        case 'e': head= ins_before_n_val(head);
                                  break;
                    }
                    break;
            case 3: printf("Enter choice: ");
                    getchar();
                    scanf("%c",&choice);
                    switch(choice)
                    {
                        case 'a': head=del_1st_node(head);
                                  break;
                        case 'b': head=del_at_end(head);
                                  break;
                        case 'c': head=delete_n_val(head);
                                  break;
                        case 'd': head=delete_after_n_val(head);
                                  break;
                        case 'e': head= delete_before_n_val(head);
                                  break;
                    }
                    break;
            case 4: print(head);
                    break;
            case 5: search(head);
                    break;
            case 6: count(head);
                    break;
        }

        printf("Press 0 to exit, 1 to continue\n");
        scanf("%d",&option);
    }while(option);
    return 0;
}

