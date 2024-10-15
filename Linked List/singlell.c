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

snode *deleteatnthposfromlast(snode *head)
{
    if (head == NULL)
        printf("List is empty!");
    else if (head->next == NULL)
    {
        snode *p1 = head;
        head = NULL;
        free(p1);
    }
    else
    {

        int m = 0, c = 1, n;
        snode *p1 = head, *p2;
        while (p1 != NULL)
        {
            p1 = p1->next;
            m++;
        }
        printf("Enter the position you want to be deleted from last :");
        scanf("%d", &n);
        p1 = head;
        while (c < (m - n))
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

void displayreverse(snode* head){

    if(head ==NULL)
        return;
    if(head ->next!=NULL)
        displayreverse(head->next);

    printf("%d ",head->info);
    
}

snode* reverse(snode* head) {
    snode *prev = NULL, *current = head, *next = NULL;
    
    while (current != NULL) {
        next = current->next;   // Store the next node
        current->next = prev;   // Reverse the current node's pointer
        prev = current;         // Move the prev pointer ahead
        current = next;         // Move to the next node
    }
    
    head = prev;  // Update the head pointer to the new first node
    return head;
}

snode* rotateRight(snode* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    snode* current = head;
    int count = 1;

    // Traverse the list to find the total length
    while (current->next != NULL) {
        current = current->next;
        count++;
    }

    // If k is greater than the length of the list, reduce k
    k = k % count;

    // If k is 0, no rotation is needed
    if (k == 0) {
        return head;
    }

    // Connect the last node to the head to form a circular list
    current->next = head;

    // Traverse to the kth node
    current = head;
    for (int i = 1; i < k; i++) {
        current = current->next;
    }

    // Make the node after the current node the new head and break the loop
    head = current->next;
    current->next = NULL;

    return head;
}

snode* rotateLeft(snode* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    snode* current = head;
    int count = 1;

    // Traverse the list to get the total length and find the kth node
    while (current->next != NULL) {
        current = current->next;
        count++;
    }

    // If k is greater than the length of the list, reduce k
    k = k % count;

    // If k is 0, no rotation is needed
    if (k == 0) {
        return head;
    }

    // Connect the last node to the first node to form a circular list
    current->next = head;

    // Find the new last node after (count - k) nodes
    int steps = count - k;
    current = head;
    while (steps > 1) {
        current = current->next;
        steps--;
    }

    // Break the list to form the new head
    head = current->next;
    current->next = NULL;

    return head;
}

void printAlternate(snode* head) {
    int flag = 1; // Flag to toggle alternate nodes
    snode* current = head;

    while (current != NULL) {
        if (flag) {
            printf("%d -> ", current->info); // Print current node if flag is 1
        }
        current = current->next;
        flag = !flag; // Toggle flag to skip the next node
    }

    printf("NULL\n");
}

snode* deleteAlternate(snode* head) {
    if (head == NULL) {
        return head;
    }

    snode* current = head;
    snode* temp;

    // Traverse the list and delete alternate nodes
    while (current != NULL && current->next != NULL) {
        temp = current->next;        // Store the node to be deleted
        current->next = temp->next;  // Link the current node to the node after the one to be deleted
        free(temp);                  // Free the deleted node
        current = current->next;     // Move to the next node (skipping one)
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
    int choice,k;

    snode *head = NULL;
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
        case 12:
            head = deleteatnthposfromlast(head);
            break;
            
        case 13:
            displayreverse(head);
            break;
        case 14:
            head = reverse(head);
            break;
        case 15:
            printf("Enter the value of k for clockwise(Right) rotation: ");
            scanf("%d", &k);
            head = rotateRight(head, k);
            break;
        case 16:
            printf("Enter the value of k for anti-clockwise(Left) rotation: ");
            scanf("%d", &k);
            head = rotateLeft(head, k);
            break;
        case 17:
            printAlternate(head);
            break;
        case 18:
            head = deleteAlternate(head);
            break;
        case 19:
            display(head);
            break;

        default:
            exit(0);
        }
    } while (1);
}
