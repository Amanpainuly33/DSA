#include<stdio.h>
#include<stdlib.h>

#define max 10
void enqueue(int queue[],int item,int *front,int *rear){
    if(*rear==max-1)
        printf("Queue is full");
    else if(*rear==-1){
        *rear = *front = 0;
        queue[*rear] = item;
    }
    else{
        *rear +=1;
        queue[*rear] = item;  
    }
}
void dequeue(int queue[],int *front,int *rear){
    if(*front==-1)
        printf("Queue is empty!");
    else if(*rear==*front){
        printf("Element :%d\n",queue[*front]);
        *front = *rear = -1;
    }
    else{
        printf("Element :%d\n",queue[*front]);
        *front= *front+1;
    }

}
void traverse(int queue[],int* front , int *rear){
    if(*front==-1)
        printf("Queue is empty");
    else{
        for(int i = *(front);i<=*(rear);i++)
            printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    int queue[max],choice,item,rear=-1,front=-1;

    do{
        printf("Enter your choice (1-Enqueue, 2-Dequeue, 3-Traverse, 0-Exit): ");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
            printf("Enter the element to be inserted :");
            scanf("%d",&item);
            enqueue(queue,item,&front,&rear);
            break;

            case 2:
            dequeue(queue,&front,&rear);
            break;

            case 3 :
            traverse(queue,&front,&rear);
            break;

            default:
            exit(0);
        }

    }while(1);
}