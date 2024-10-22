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

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newNode;
}

// Function to delete a node from the end of the list
void deleteFromEnd(struct Node** head) {
    // If the list is empty, there's nothing to delete
    if (*head == NULL) {
        printf("List is already empty!\n");
        return;
    }

    // If the list has only one node, delete it
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from the end. List is now empty.\n");
        return;
    }

    // Traverse to the second-to-last node
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Free the memory of the last node
    free(temp->next);
    temp->next = NULL;  // Update the second-to-last node to be the new end
    printf("Node deleted from the end.\n");
}

// Function to print the linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate deletion from the end
int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete from end\n");
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
                deleteFromEnd(&head);
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
