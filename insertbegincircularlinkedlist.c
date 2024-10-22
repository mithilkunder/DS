#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of a circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If the list is empty, make the new node the head and point it to itself
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Point the new node to itself
    } else {
        struct Node* temp = *head;

        // Traverse the list to find the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Link the new node to the current head
        newNode->next = *head;

        // Update the last node to point to the new node
        temp->next = newNode;

        // Update the head to the new node
        *head = newNode;
    }
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");  // To indicate that it loops back to the head
}

// Main function to demonstrate insertion at the beginning
int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert at the beginning of the list: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 2:
                printList(head);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
