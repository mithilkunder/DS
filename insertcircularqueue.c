#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

// Function to insert an element into the circular queue
void insert(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) { // Queue is initially empty
            front = rear = 0;
        } else if (rear == SIZE - 1 && front != 0) { // Wrap around condition
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = value;
        printf("%d inserted into the queue\n", value);
    }
}

// Function to display the elements of the circular queue
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again\n");
        }
    }
}
