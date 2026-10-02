#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
// Each node contains an integer data and a pointer to the next node.
struct Node {
    int data;             // Data stored in the node
    struct Node* next;    // Pointer to the next node
};

// Function to create a new node
// Allocates memory for a new node, assigns the given value to data, and sets next to NULL.
struct Node* yeniNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
// Updates the head pointer to the new node.
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = yeniNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
// Traverses the list to find the last node and appends the new node.
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = yeniNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a node after a given index (0-based index)
// Inserts a new node after the node at the specified index.
void insertAfterIndex(struct Node** head, int value, int index) {
    struct Node* newNode = yeniNode(value);
    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL)
            return; // Index out of bounds, do nothing
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete the first node of the list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node of the list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Function to delete a node at a given index (0-based index)
void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL) return;
    struct Node* current = *head;
    if (index == 0) {
        *head = current->next;
        free(current);
        return;
    }
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) return; // Index out of bounds
    struct Node* nextNode = current->next->next;
    free(current->next);
    current->next = nextNode;
}

// Function to reverse the linked list
// Reverses the direction of the node links so that the last node becomes the head.
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;  // Save next node
        current->next = prev;      // Reverse the link
        prev = current;            // Move prev forward
        current = nextNode;        // Move current forward
    }
    *head = prev; // Update head to the new first node
}

// Function to make the list circular
// Connects the last node's next pointer to the head, forming a circular list.
void makeCircular(struct Node* head) {
    if (head == NULL) return;
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head;
}

// Function to print the linked list
// Prints each node's data sequentially, ending with NULL.
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize the list as empty

    // Append elements to the list
    printf("Initial list:\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);

    // Insert at the beginning
    printf("\nInsert 5 at the beginning:\n");
    insertAtBeginning(&head, 5);
    printList(head);

    // Append another element
    printf("\nAppend 40 to the list:\n");
    insertAtEnd(&head, 40);
    printList(head);

    // Insert after a given index (inserting 25 after index 1, which means after the second node)
    printf("\nInsert 25 after index 1:\n");
    insertAfterIndex(&head, 25, 2);
    printList(head);

    // Delete the first node
    printf("\nDelete from the beginning:\n");
    deleteFromBeginning(&head);
    printList(head);

    // Delete a node at a given index (delete node at index 2)
    printf("\nDelete node at index 2:\n");
    deleteAtIndex(&head, 2);
    printList(head);

    // Delete the last node
    printf("\nDelete from the end:\n");
    deleteFromEnd(&head);
    printList(head);

    // Reverse the list
    printf("\nReverse the list:\n");
    reverseList(&head);
    printList(head);

    return 0;
}
