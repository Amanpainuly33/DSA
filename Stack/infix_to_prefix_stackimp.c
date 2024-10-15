#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for linked list stack
struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

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

char pop() {
    if (top == NULL)
        return -1;
    struct Node* temp = top;
    char popped = top->data;
    top = top->next;
    free(temp);
    return popped;
}

int precedence(char x) {
    if (x == '(' || x == ')')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void reverse(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void infixToPrefix(char *infix) {
    char *postfix = (char *)malloc(strlen(infix) + 1);
    int i = 0, j = 0;

    // Step 1: Reverse the infix expression
    reverse(infix);

    // Step 2: Replace '(' with ')' and vice versa
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    i = 0; // Reset the index for postfix conversion

    // Step 3: Apply the infix to postfix logic on reversed infix
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

    postfix[j] = '\0';  // Null-terminate the postfix expression

    // Step 4: Reverse the postfix expression to get the prefix expression
    reverse(postfix);
    printf("Prefix: %s\n", postfix);
    free(postfix);
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    gets(infix);

    infixToPrefix(infix);
    return 0;
}
