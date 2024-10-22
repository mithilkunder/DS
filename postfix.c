#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack structure
struct Stack {
    int data[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to perform operations based on the operator
int performOperation(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': return pow(operand1, operand2);
        default: 
            printf("Unexpected operator: %c\n", operator);
            exit(1);
    }
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* expression) {
    struct Stack stack;
    initStack(&stack);
    int i = 0;

    while (expression[i] != '\0') {
        // If the character is a digit, push it to the stack
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0'); // Convert char to int
        } 
        // If the character is an operator, pop two elements, perform the operation, and push the result
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result = performOperation(expression[i], operand1, operand2);
            push(&stack, result);
        }
        i++;
    }
    // The final result will be the only element left in the stack
    return pop(&stack);
}

// Main function to test the postfix evaluation
int main() {
    char expression[MAX];

    printf("Enter a valid postfix expression (e.g., 53+62/*): ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
