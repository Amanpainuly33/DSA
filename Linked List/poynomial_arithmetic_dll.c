#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the polynomial
typedef struct node {
    int coeff;         // Coefficient
    int expo;          // Exponent
    struct node* next; // Pointer to the next node
} node;

// Function to create a new node
node* createNode(int coeff, int expo) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
node* insertAtLast(node* head, int coeff, int expo) {
    node* newNode = createNode(coeff, expo);
    
    if (head == NULL) {
        return newNode;
    }
    
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to add two polynomials and return the result list
node* addPolynomials(node* poly1, node* poly2) {
    node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->expo > poly2->expo) {
            result = insertAtLast(result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            result = insertAtLast(result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                result = insertAtLast(result, sumCoeff, poly1->expo);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1
    while (poly1 != NULL) {
        result = insertAtLast(result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2
    while (poly2 != NULL) {
        result = insertAtLast(result, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }

    return result;
}

// Function to subtract two polynomials and return the result list
node* subtractPolynomials(node* poly1, node* poly2) {
    node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->expo > poly2->expo) {
            result = insertAtLast(result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            result = insertAtLast(result, -poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } else {
            int diffCoeff = poly1->coeff - poly2->coeff;
            if (diffCoeff != 0) {
                result = insertAtLast(result, diffCoeff, poly1->expo);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1
    while (poly1 != NULL) {
        result = insertAtLast(result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2 with negative sign
    while (poly2 != NULL) {
        result = insertAtLast(result, -poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    node* temp = head;
    while (temp != NULL) {
        if (temp->coeff > 0 && temp != head) {
            printf("+ ");
        }
        printf("%dx^%d ", temp->coeff, temp->expo);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, coeff, expo;
    node* poly1 = NULL;
    node* poly2 = NULL;
    node* result = NULL;

    do {
        printf("\n1. Insert in Polynomial 1\n");
        printf("2. Insert in Polynomial 2\n");
        printf("3. Add Polynomials\n");
        printf("4. Subtract Polynomials\n");
        printf("5. Display Polynomial 1\n");
        printf("6. Display Polynomial 2\n");
        printf("7. Display Result\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient and exponent for Polynomial 1: ");
                scanf("%d %d", &coeff, &expo);
                poly1 = insertAtLast(poly1, coeff, expo);
                break;

            case 2:
                printf("Enter coefficient and exponent for Polynomial 2: ");
                scanf("%d %d", &coeff, &expo);
                poly2 = insertAtLast(poly2, coeff, expo);
                break;

            case 3:
                result = addPolynomials(poly1, poly2);
                printf("Polynomials added successfully!\n");
                break;

            case 4:
                result = subtractPolynomials(poly1, poly2);
                printf("Polynomials subtracted successfully!\n");
                break;

            case 5:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                break;

            case 6:
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                break;

            case 7:
                printf("Result: ");
                displayPolynomial(result);
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
