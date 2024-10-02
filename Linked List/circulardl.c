#include <stdio.h>
#include <stdlib.h>

typedef struct circulardoubly
{
    struct circulardoubly *prev;
    int info;
    struct circulardoubly *next;
} cdnode;

void display(cdnode *head)
{
    cdnode *p1 = head;
    if (head == NULL)
        printf("List is empty!");
    else
    {

        do
        {
            printf("%d ", p1->info);
            p1 = p1->next;
        } while (p1 != head);
    }
}
cdnode *insertatbeg(cdnode *head)
{
    cdnode *temp = (cdnode *)malloc(sizeof(cdnode));
    if (temp == NULL)
        printf("Memory not allocated!");
    else if (head == NULL)
    {
        printf("Enter the info:");
        scanf("%d", &temp->info);
        temp->prev = temp;
        temp->next = temp;
        head = temp;
    }
    else
    {
        printf("Enter the info:");
        scanf("%d", &temp->info);
        temp->prev = head->prev;
        temp->next = head;
        head->prev->next = temp; // for the last node
        head->prev = temp;
        head = temp;
    }
    return head;
}
cdnode *insertatlast(cdnode *head)
{
    cdnode *temp = (cdnode *)malloc(sizeof(cdnode));
    if (temp == NULL)
        printf("Memory not allocated!");
    else if (head == NULL)
    {
        printf("Enter the info:");
        scanf("%d", &temp->info);
        temp->prev = temp;
        temp->next = temp;
        head = temp;
    }
    else
    { // for 1 or more than 1 node
        printf("Enter the info:");
        scanf("%d", &temp->info);
        cdnode *p1 = head;
        do
        {
            p1 = p1->next;
        } while (p1->next != head); // p1 is at he last node

        p1->next = temp;
        temp->prev = p1;
        temp->next = head;
        head->prev = temp;
    }
    return head;
}

cdnode *insertatgivenpos(cdnode *head)
{
    cdnode *temp = (cdnode *)malloc(sizeof(cdnode));
    if (temp == NULL)
        printf("Memory not allocated!");
    else if (head == NULL)
    {
        printf("List is empty , so it will be the first node!\n");
        printf("Enter the info:");
        scanf("%d", &temp->info);
        temp->prev = temp;
        temp->next = temp;
        head = temp;
    }
    else
    {
        cdnode *p1 = head;
        int c = 1, n;
        while (p1->next != head)
        {
            p1 = p1->next;
            ++c;
        }

        printf("ENter the position you want the node to be inserted!\n Possible positions(%d) :", c);
        scanf("%d", &n);
        printf("Enter the info:");
        scanf("%d", &temp->info);
        if (n == 1)
        {
            temp->prev = head->prev;
            temp->next = head;
            head->prev->next = temp; // for the last node
            head->prev = temp;
            head = temp;
        }
        else
        {
            p1 = head;
            while (n > 2)
            {
                p1 = p1->next;
                --n;
            }
            p1->next->prev = temp;
            temp->next = p1->next;
            temp->prev = p1;
            p1->next = temp;
        }
    }
    return head;
}

cdnode *insertafternode(cdnode *head)
{
    cdnode *temp = (cdnode *)malloc(sizeof(cdnode));
    if (temp == NULL)
        printf("Memory not allocated!");
    else if (head == NULL)
    {
        printf("List is empty , so it will be the first node!\n");
        printf("Enter the info:");
        scanf("%d", &temp->info);
        temp->prev = temp;
        temp->next = temp;
        head = temp;
    }
    else
    {
        int key;
        printf("Enter the value of node after you want the node to be inserted :");
        scanf("%d", &key);
        printf("Enter the info:");
        scanf("%d", &temp->info);
        cdnode *p1 = head;
        do
        {
            if (p1->info == key)
            {
                p1->next->prev = temp;
                temp->next = p1->next;
                temp->prev = p1;
                p1->next = temp;
            }
            p1 = p1->next;

        } while (p1 != head);
    }
    return head;
}

cdnode *deletefrombeg(cdnode *head)
{
    if (head == NULL)
        printf("List is Empty");
    else if (head->next == head)
    {
        cdnode *p1 = head;
        head = NULL;
        free(p1);
    }
    else
    {
        cdnode *p1 = head;
        head = head->next;
        p1->next->prev = p1->prev;
        p1->prev->next = p1->next;
        free(p1);
    }
    return head;
}

cdnode *deletefromlast(cdnode *head)
{
    if (head == NULL)
        printf("List is Empty");
    else if (head->next == head)
    {
        cdnode *p1 = head;
        head = NULL;
        free(p1);
    }
    else
    {
        cdnode *p1 = head;
        do
        {
            p1 = p1->next;
        } while (p1->next != head); // p1 is at he last node

        p1->prev->next = p1->next;
        p1->next->prev = p1->prev;
        free(p1);
    }
    return head;
}

cdnode *deletefromgivenpos(cdnode *head)
{
    if (head == NULL)
    {
        printf("List is Empty");
        return head;
    }

    else
    {
        cdnode *p1 = head;
        int c = 1, n;
        while (p1->next != head)
        {
            p1 = p1->next;
            ++c;
        }

        printf("ENter the position you want the node to be deleted!\n Possible positions(%d) :", c);
        scanf("%d", &n);

        p1 = head;
        if (n < 1 || n > c)
        {
            printf("Invalid position!\n");
            return head;
        }
        if (n == 1)
        {
            if (head->next == head)
            {
                printf("Last node was left and its been deleted");
                free(head);
                head = NULL;
            }
            else
            {
                head = head->next;
                p1->next->prev = p1->prev;
                p1->prev->next = p1->next;
                free(p1);
            }
        }
        else
        {
            while (n > 1)
            {
                p1 = p1->next;
                --n;
            }
            p1->prev->next = p1->next;
            p1->next->prev = p1->prev;
            free(p1);
        }
    }
    return head;
}
cdnode *deletebeforenode(cdnode *head){
    if(head == NULL){
        printf("List is empty!");
        return head;
    }
    else if(head->next==head){
        int key;
        printf("Enter the node before which which you want the node to be deleted :");
        scanf("%d",&key);
        free(head);
        head = NULL;

    }
    else {
        int key;
        printf("Enter the node before which which you want the node to be deleted :");
        scanf("%d",&key);
        cdnode *p1 = head;
        if(head->next->info==key){
            head = head->next;
            p1->next->prev=p1->prev;
            p1->prev->next=p1->next;
            free(p1);
            return head;
        }
        else{
            do{
                if(p1->info==key){
                    cdnode* todelete = p1->prev;
                    todelete->next->prev=todelete->prev;
                    todelete->prev->next=todelete->next;
                    free(todelete);

                    return head;
                }
                p1= p1->next;

            }while(p1!=head);

        }
    }
}

int main()
{

    int choice;
    cdnode *head = NULL;

    do
    {
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insertatbeg(head);
            break;
        case 2:
            head = insertatlast(head);
            break;
        case 3:
            head = insertatgivenpos(head);
            break;
        case 4:
            head = insertafternode(head);
            break;

        case 5:
            head = deletefrombeg(head);
            break;
        case 6:
            head = deletefromlast(head);
            break;
        case 7:
            head = deletefromgivenpos(head);
            break;
        case 8:
            head = deletebeforenode(head);
            break;

        case 9:
            display(head);
            break;

        default:
            exit(0);
        }
    } while (1);
}