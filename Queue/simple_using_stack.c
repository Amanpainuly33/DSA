#include <stdio.h>
#include <stdlib.h>

#define max 10

typedef struct {
    int top;
    int arr[max];
} Stack;

// Initialize a stack
void init(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == max - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = item;
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Enqueue function using two stacks
void enqueue(Stack *s1, int item) {
    push(s1, item); // Push directly to the first stack (s1)
    printf("Enqueued: %d\n", item);
}

// Dequeue function using two stacks
int dequeue(Stack *s1, Stack *s2) {
    if (isEmpty(s2)) {
        if (isEmpty(s1)) {
            printf("Queue is empty\n");
            return -1;
        }
        // Transfer all elements from s1 to s2
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
        }
    }
    // Pop from the second stack (s2) to simulate dequeuing
    int dequeuedItem = pop(s2);
    printf("Dequeued: %d\n", dequeuedItem);
    return dequeuedItem;
}

// Traverse the queue (just print elements in s1 and s2 as they are)
void traverse(Stack *s1, Stack *s2) {
    if (isEmpty(s1) && isEmpty(s2)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements (in order): ");
    // Traverse second stack s2 in reverse order
    for (int i = s2->top; i >= 0; i--) {
        printf("%d ", s2->arr[i]);
    }
    // Traverse first stack s1 in normal order
    for (int i = 0; i <= s1->top; i++) {
        printf("%d ", s1->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s1, s2;
    int choice, item;

    // Initialize both stacks
    init(&s1);
    init(&s2);

    do {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue element\n");
        printf("2. Dequeue element\n");
        printf("3. Traverse queue\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &item);
                enqueue(&s1, item);
                break;

            case 2:
                dequeue(&s1, &s2);
                break;

            case 3:
                traverse(&s1, &s2);
                break;

            default:
                exit(0);
        }
    } while (1);

    return 0;
}
