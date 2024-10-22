#include <stdio.h>
#define MAX 5 // Maximum size of the stack

int stack[MAX]; // Array to implement stack
int top = -1;   // Variable to track the top element of the stack

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } 
    else
     {
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Function to display the elements of the stack
void display() {
    if (top == -1) 
    {
        printf("Stack is empty!\n");
    } 
    else 
    {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) 
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) 
    {
        printf("\n1. Push\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                display();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
