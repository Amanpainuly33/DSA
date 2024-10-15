#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for linked list implementation of stack
struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(char x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Stack overflow\n");
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop operation
char pop() {
    if (top == NULL)
        return -1;
    struct Node* temp = top;
    char popped = top->data;
    top = top->next;
    free(temp);
    return popped;
}

// Check precedence of operators
int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    char* postfix = (char*)malloc(strlen(infix) + 1);
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char x = infix[i];
        
        if (isalnum(x)) {
            postfix[j++] = x;
        } else if (x == '(') {
            push(x);
        } else if (x == ')') {
            while (top != NULL && top->data != '(')
                postfix[j++] = pop();
            pop();  // Remove '(' from stack
        } else {
            while (top != NULL && precedence(top->data) >= precedence(x))
                postfix[j++] = pop();
            push(x);
        }
        i++;
    }
    
    while (top != NULL)
        postfix[j++] = pop();
    
    postfix[j] = '\0';  // Null-terminate postfix expression
    printf("Postfix: %s\n", postfix);
    free(postfix);
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    gets(infix);
    
    infixToPostfix(infix);
    return 0;
}
