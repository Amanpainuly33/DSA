#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* push(int item,struct node* top){

    struct node* temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){
        printf("Stack overflow!\n");
        return top;
    }
    temp->next = top;        //making ll in reverse order
    temp->data = item;

    return temp;             //return the address of new node created
}

struct node* pop(struct node* top){

    struct node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void traverse (struct node* top){

    struct node* p1 = top;

    while(p1!=NULL){
        printf("%d ",p1->data);
        p1 = p1->next;
    }
    printf("\n");
}


int main(){
    int choice,item;
    struct node* top=NULL;

    do{
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
            printf("Enter the element to be pushed :");
            scanf("%d",&item);

            top =push(item,top);
            break;

            case 2:
            top = pop(top);
            break;

            case 3 :
            traverse(top);
            break;

            default:
            exit(0);
        }

    }while(1);
}