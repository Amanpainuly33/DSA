#include <stdio.h>
#include <stdlib.h>

#define max 10

typedef struct {
    int front, rear;
    int arr[max];
} Queue;

// Initialize the queue
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return q->rear == max - 1;
}

// Enqueue an element into the queue
void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = item;
}

// Dequeue an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset the queue when it's empty
    } else {
        q->front++;
    }
    return item;
}

// Push operation (insert element in the stack using two queues)
void push(Queue *q1, Queue *q2, int item) {
    enqueue(q2, item); // Always enqueue to q2 (new element comes last)
    
    // Transfer all elements from q1 to q2
    while (!isEmpty(q1)) {
        enqueue(q2, dequeue(q1));
    }

    // Swap q1 and q2 pointers (so q1 now has all elements in the correct stack order)
    Queue temp = *q1;
    *q1 = *q2;
    *q2 = temp;

    printf("Pushed: %d\n", item);
}

// Pop operation (remove element from the stack using two queues)
int pop(Queue *q1) {
    if (isEmpty(q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    int poppedItem = dequeue(q1);
    printf("Popped: %d\n", poppedItem);
    return poppedItem;
}

// Traverse the stack (elements are stored in q1 in correct order)
void traverse(Queue *q1) {
    if (isEmpty(q1)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (from top to bottom): ");
    for (int i = q1->front; i <= q1->rear; i++) {
        printf("%d ", q1->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q1, q2; // Two queues
    int choice, item;

    // Initialize both queues
    init(&q1);
    init(&q2);

    do {
        printf("\nEnter your choice:\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Traverse stack\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &item);
                push(&q1, &q2, item);
                break;

            case 2:
                pop(&q1);
                break;

            case 3:
                traverse(&q1);
                break;

            default:
                exit(0);
        }
    } while (1);

    return 0;
}
