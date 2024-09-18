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

    // for an empty list
    else if (head == NULL)
    {
        head = temp;
        head->next = NULL;
        printf("Enter the info :");
        scanf("%d", &temp->info);
    }

    // for a list having one node
    else if (head->next == NULL)
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        temp->next = head->next;
        head->next = temp;
    }

    else
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        int c = 0;
        snode *p1 = head;
        while (p1 != NULL)
        {
            p1 = p1->next;
            c++;
        }
        c = c / 2;
        p1 = head;
        while (c > 1)
        {
            p1 = p1->next;
            c--;
        }
        temp->next = p1->next;
        p1->next = temp;
    }
    return head;
}
snode *insertatlast(snode *head)
{
    snode *temp = (snode *)malloc(sizeof(snode));

    if (temp == NULL)

        printf("Memory not allocated!");

    else if (head == NULL)
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        head = temp;
        head->next = NULL;
    }
    else
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        snode *p1 = head;
        while (p1->next != NULL)
            p1 = p1->next;
        temp->next = NULL;
        p1->next = temp;
    }
    return head;
}

snode *insertatnthpos(snode *head)
{
    snode *temp = (snode *)malloc(sizeof(snode));
    int n;
    printf("Enter a valid position to be entered (indexing starts from 1):");
    scanf("%d", &n);

    if (temp == NULL)

        printf("Memory not allocated!");

    else if (head == NULL)
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        head = temp;
        head->next = NULL;
    }
    else if (n == 1)
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        temp->next = head;
        head = temp;
    }
    else
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        snode *p1 = head;
        int c = 1;
        while (c < (n - 1))
        {
            p1 = p1->next;
            c++;
        }
        temp->next = p1->next;
        p1->next = temp;
    }
    return head;
}
snode *insertatnthposfromlast(snode *head)
{
    snode *temp = (snode *)malloc(sizeof(snode));
    int n;
    int m = 0;
    snode *p1 = head;
    while (p1 != NULL)
    {
        p1 = p1->next;
        m++;
    }

    printf("Enter the position to be entered from last [choices -> 1 to %d] :", m + 1);
    scanf("%d", &n);

    if (temp == NULL)

        printf("Memory not allocated!");

    else if (head == NULL)
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        head = temp;
        head->next = NULL;
    }
    else if (n <= m)
    {
        temp->next = NULL;
        printf("Enter the info :");
        scanf("%d", &temp->info);
        p1 = head;
        int c = 1;
        while (c < (m - n + 1))
        {
            p1 = p1->next;
            c++;
        }
        temp->next = p1->next;
        p1->next = temp;
    }
    // n=m+1
    else
    {
        printf("Enter the info :");
        scanf("%d", &temp->info);
        temp->next = head;
        head = temp;
    }
    return head;
}

snode *deleteatbeg(snode *head)
{
    if (head == NULL)
        printf("List is empty!");
    else
    {
        snode *p1 = head;
        head = head->next;
        free(p1);
    }
    return head;
}

snode *deleteatmiddle(snode *head)
{

    if (head == NULL)

        printf("List is empty!");

    else
    {

        int c = 0;
        snode *p1 = head, *p2;
        while (p1 != NULL)
        {
            p1 = p1->next;
            c++;
        }
        c = c / 2;
        p1 = head;
        while (c > 1)
        {
            p1 = p1->next;
            c--;
        }
        p2 = p1->next;
        p1->next = p1->next->next;
        free(p2);
    }
    return head;
}

snode *deleteafternode(snode *head)
{
    if (head == NULL)
        printf("List is empty!");
    else
    {

        snode *p1 = head, *p2;
        int info;

        printf("Enter the info after which node is to be deleted(pls don't enter the last info) :");
        scanf("%d", &info);

        while (p1->info != info)
            p1 = p1->next;
        p2 = p1->next;
        p1->next = p1->next->next;
        free(p2);
    }
    return head;
}

snode *deleteatlast(snode *head)
{
    if (head == NULL)
        printf("Empty List!");

    // no of nodes =1
    else if (head->next == NULL)
    {
        snode *p1 = head;
        head = NULL;
        free(p1);
    }
    else
    {
        snode *p1 = head, *p2;
        while (p1->next->next != NULL)
            p1 = p1->next;
        p2 = p1->next;
        p1->next = NULL;
        free(p2);
    }
    return head;
}

snode *deleteatnthpos(snode *head)
{
    int n, m;
    printf("Enter the position you want the node to be deleted :");
    scanf("%d", &n);
    snode *p1 = head;

    if (head == NULL)
        printf("List is empty!");

    else if (head->next == NULL)
    {
        printf("Only one node was available and its deleted!");
        head = NULL;
        free(p1);
    }
    else if (n == 1)
    {
        head = head->next;
        free(p1);
    }
    else
    {
        int c = 1;
        snode *p2;
        while (c < (n - 1))
        {
            p1 = p1->next;
            c++;
        }
        p2 = p1->next;
        p1->next = p2->next;
        free(p2);
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
        case 4:
            head = insertatlast(head);
            break;
        case 5:
            head = insertatnthpos(head);
            break;
        case 6:
            head = insertatnthposfromlast(head);
            break;

        case 7:
            head = deleteatbeg(head);
            break;
        case 8:
            head = deleteatmiddle(head);
            break;
        case 9:
            head = deleteafternode(head);
            break;
        case 10:
            head = deleteatlast(head);
            break;
        case 11:
            head = deleteatnthpos(head);
            break;
            // case 12:
            //     head = deleteatnthposfromlast(head);
            //     break;

        case 13:
            display(head);
            break;

        default:
            exit(0);
        }
    } while (1);
}
