#include<stdio.h>
#include<stdlib.h>

#define max 10

void enqueue(int queue[], int item, int *front, int *rear) {
    if ((*rear + 1) % max == *front) {
        printf("Queue is full\n");
    } else if (*rear == -1) { // Queue is initially empty
        *rear = *front = 0;
        queue[*rear] = item;
    } else {
        *rear = (*rear + 1) % max; // Circular increment
        queue[*rear] = item;
    }
}

void dequeue(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is empty!\n");
    } else if (*rear == *front) { // Only one element in the queue
        printf("Element: %d\n", queue[*front]);
        *front = *rear = -1; // Reset queue after last element
    } else {
        printf("Element: %d\n", queue[*front]);
        *front = (*front + 1) % max; // Circular increment
    }
}

void traverse(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = *front;
        while (i != *rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % max; // Circular traversal
        }
        printf("%d\n", queue[*rear]); // Print the last element
    }
}

int main() {
    int queue[max], choice, item, rear = -1, front = -1;

    do {
        printf("Enter your choice (1-Enqueue, 2-Dequeue, 3-Traverse, 0-Exit): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                enqueue(queue, item, &front, &rear);
                break;

            case 2:
                dequeue(queue, &front, &rear);
                break;

            case 3:
                traverse(queue, &front, &rear);
                break;

            default:
                exit(0);
        }
    } while (1);

    return 0;
}
