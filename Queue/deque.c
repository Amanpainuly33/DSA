#include<stdio.h>
#include<stdlib.h>

#define max 10

// Check if the deque is full
int isFull(int front, int rear) {
    return (front == (rear + 1) % max);
}

// Check if the deque is empty
int isEmpty(int front, int rear) {
    return (front == -1);
}

// Insert element at the rear
void insertRear(int deque[], int item, int *front, int *rear) {
    if (isFull(*front, *rear)) {
        printf("Deque is full\n");
    } else if (*rear == -1) { // Initially empty
        *front = *rear = 0;
        deque[*rear] = item;
    } else {
        *rear = (*rear + 1) % max; // Circular increment
        deque[*rear] = item;
    }
}

// Insert element at the front
void insertFront(int deque[], int item, int *front, int *rear) {
    if (isFull(*front, *rear)) {
        printf("Deque is full\n");
    } else if (*front == -1) { // Initially empty
        *front = *rear = 0;
        deque[*front] = item;
    } else {
        *front = (*front - 1 + max) % max; // Circular decrement
        deque[*front] = item;
    }
}

// Delete element from the front
void deleteFront(int deque[], int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Deque is empty!\n");
    } else if (*front == *rear) { // Only one element in the deque
        printf("Element deleted from front: %d\n", deque[*front]);
        *front = *rear = -1; // Reset deque
    } else {
        printf("Element deleted from front: %d\n", deque[*front]);
        *front = (*front + 1) % max; // Circular increment
    }
}

// Delete element from the rear
void deleteRear(int deque[], int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Deque is empty!\n");
    } else if (*front == *rear) { // Only one element in the deque
        printf("Element deleted from rear: %d\n", deque[*rear]);
        *front = *rear = -1; // Reset deque
    } else {
        printf("Element deleted from rear: %d\n", deque[*rear]);
        *rear = (*rear - 1 + max) % max; // Circular decrement
    }
}

// Traverse the deque from front to rear
void traverse(int deque[], int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", deque[i]);
            i = (i + 1) % max; // Circular traversal
        }
        printf("%d\n", deque[rear]); // Print the last element
    }
}

// Main function to test the deque operations
int main() {
    int deque[max], choice, item;
    int front = -1, rear = -1;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert at rear\n");
        printf("2. Insert at front\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Traverse deque\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted at rear: ");
                scanf("%d", &item);
                insertRear(deque, item, &front, &rear);
                break;

            case 2:
                printf("Enter the element to be inserted at front: ");
                scanf("%d", &item);
                insertFront(deque, item, &front, &rear);
                break;

            case 3:
                deleteFront(deque, &front, &rear);
                break;

            case 4:
                deleteRear(deque, &front, &rear);
                break;

            case 5:
                traverse(deque, front, rear);
                break;

            default:
                exit(0);
        }
    } while (1);

    return 0;
}
