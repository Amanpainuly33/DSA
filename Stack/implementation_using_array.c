#include<stdio.h>
#include<stdlib.h>
#define max 10

void push(int arr[],int item,int *top){
    if(*top==max-1){
        printf("Stack is full!\n");
        exit(0);
    }
    else{
        *top +=1;
        arr[*top]=item;
    }
}

void pop(int arr[],int *top){
    if(*top==-1){
        printf("Stack underflow!\n");
        exit(0);
    }
    else{
        printf("%d is deleted\n",arr[*top]);
        *top -=1;
    }
}

void traverse(int arr[],int* top){
    int t = *top;
    while(t!=-1){
        printf("%d ",arr[t]);
        t -=1;
    }
}

int main(){
    int arr[max],choice,item,top=-1;

    do{
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
            printf("Enter the element to be inserted :");
            scanf("%d",&item);
            push(arr,item,&top);
            break;

            case 2:
            pop(arr,&top);
            break;

            case 3 :
            traverse(arr,&top);
            break;

            default:
            exit(0);
        }

    }while(1);
}
