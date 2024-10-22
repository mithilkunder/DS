#include <stdio.h>
#define SIZE 5 // Define the maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    // Check if the queue is full
    if (rear == SIZE - 1) {
        printf("Queue is full! Cannot insert %d.\n", value);
    } else {
        if (front == -1) {
            front = 0; // Set front to 0 when inserting the first element
        }
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

void dequeue() {
    // Check if the queue is empty
    if (front == -1 || front > rear) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        front++; // Increment front to remove the element
    }
}

void display() {
    // Check if the queue is empty
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations: \n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
