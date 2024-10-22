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

// Function to insert a node at the end of a circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If the list is empty, make the new node the head and point it to itself
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Point the new node to itself
    } else {
        struct Node* temp = *head;

        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Link the new node at the end
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node from the beginning of a circular linked list
void deleteFromBeginning(struct Node** head) {
    // If the list is empty, there's nothing to delete
    if (*head == NULL) {
        printf("List is already empty!\n");
        return;
    }

    // If the list contains only one node
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        printf("Node deleted. List is now empty.\n");
        return;
    }

    // If the list contains more than one node
    struct Node* temp = *head;

    // Traverse to the last node
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Update the last node to point to the second node
    struct Node* toDelete = *head;
    temp->next = (*head)->next;  // Last node points to the new head
    *head = (*head)->next;  // Update head to the second node

    // Free the old head
    free(toDelete);
    printf("Node deleted from the beginning.\n");
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

// Main function to demonstrate deletion at the beginning
int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete from beginning\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert at the end of the list: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 2:
                deleteFromBeginning(&head);
                break;

            case 3:
                printList(head);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
