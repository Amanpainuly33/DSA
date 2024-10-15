#include<stdio.h>
#include<stdlib.h>

#define max 10

typedef struct {
    int data;
    int priority;
} Node;

// Insert an element into the priority queue
void insert(Node pq[], int *n, int item, int priority) {
    if (*n == max) {
        printf("Priority Queue is full\n");
        return;
    }
    
    Node temp;
    temp.data = item;
    temp.priority = priority;

    pq[*n] = temp; // Insert at the end
    (*n)++;

    // Sort the queue based on priority (Min-Priority Queue)
    for (int i = 0; i < *n - 1; i++) {
        for (int j = i + 1; j < *n; j++) {
            if (pq[i].priority > pq[j].priority) {
                Node t = pq[i];
                pq[i] = pq[j];
                pq[j] = t;
            }
        }
    }
}

// Delete the element with the highest priority (smallest priority value)
void delete(Node pq[], int *n) {
    if (*n == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Element deleted: %d (Priority: %d)\n", pq[0].data, pq[0].priority);
    for (int i = 0; i < *n - 1; i++) {
        pq[i] = pq[i + 1]; // Shift elements left
    }
    (*n)--;
}

// Traverse the priority queue and display its contents
void traverse(Node pq[], int n) {
    if (n == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    Node pq[max];
    int n = 0; // Number of elements in the priority queue
    int choice, item, priority;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Traverse priority queue\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element and its priority: ");
                scanf("%d %d", &item, &priority);
                insert(pq, &n, item, priority);
                break;

            case 2:
                delete(pq, &n);
                break;

            case 3:
                traverse(pq, n);
                break;

            default:
                exit(0);
        }
    } while (1);

    return 0;
}

/*
if (pq[i].priority < pq[j].priority) {
    // Swap elements to make highest priority first
}

*/