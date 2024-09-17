#include <stdio.h>
#include <stdlib.h>

// self referencial structure
typedef struct snode
{
    int info;
    struct snode *next;
} snode;

snode *insertatbeg(snode *head)
{
    snode *temp = (snode *)malloc(sizeof(snode));
    if (temp == NULL)
        printf("Memory not allocated!");
    else
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        temp->next = head;
        head = temp;
    }
    return head;
}

snode *insertafternode(snode *head)
{
    snode *temp = (snode *)malloc(sizeof(snode));
    if (temp == NULL)
        printf("Memory not allocated!");
    else if (head == NULL)
    {
        head = temp;
        head->next = NULL;
        printf("Enter the info :");
        scanf("%d", &temp->info);
    }
    else
    {
        snode *p1 = head;
        int info;
        printf("Enter the info after which node is to be inserted :");
        scanf("%d", &info);
        printf("Enter the info :");
        scanf("%d", &temp->info);
        while (p1->info != info)
            p1 = p1->next;
        temp->next = p1->next;
        p1->next = temp;
    }
    return head;
}

snode *insertatmiddle(snode *head)
{
    snode *temp = (snode *)malloc(sizeof(snode));
    if (temp == NULL)
        printf("Memory not allocated!");

    //for an empty list
    else if (head == NULL)
    {
        head = temp;
        head->next = NULL;
        printf("Enter the info :");
        scanf("%d", &temp->info);
    }

    //for a list having one node
    else if(head->next==NULL){
        printf("Enter the info :");
        scanf("%d", &temp->info);
        temp->next=head->next;
        head->next=temp;
    }

    else{
        printf("Enter the info :");
        scanf("%d", &temp->info);
        int c=0;
        snode* p1=head;
        while(p1!=NULL){
            p1=p1->next;
            c++;
        }
        c=c/2;
        p1=head;
        while(c>1){
            p1=p1->next;
            c--;
        }
        temp->next = p1->next;
        p1->next = temp;
    }
    return head;
}



void display(snode *head)
{
    snode *p1 = head;
    while (p1 != NULL)
    {
        printf("%d ", p1->info);
        p1 = p1->next;
    }
    printf("\n");
}

int main()
{
    int choice;

    snode *head = NULL;
    do
    {
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insertatbeg(head);
            break;
            case 2:
                head = insertafternode(head);
                break;
            case 3:
                head = insertatmiddle(head);
                break;
            // case 4:
            //     head = insertatlast(head);
            //     break;
            // case 5:
            //     head = insertatnthpos(head);
            //     break;
            // case 6:
            //     head = insertatnthposfromlast(head);
            //     break;

            // case 7:
            //     head = deleteatbeg(head);
            //     break;
            // case 8:
            //     head = deleteatmiddle(head);
            //     break;
            // case 9:
            //     head = deleteafternode(head);
            //     break;
            // case 10:
            //     head = deleteatlast(head);
            //     break;
            // case 11:
            //     head = deleteatnthpos(head);
            //     break;
            // case 12:
            //     head = insertatnthposfromlast(head);
            //     break;

        case 13:
            display(head);
            break;

        default:
            exit(0);
        }
    } while (1);
}