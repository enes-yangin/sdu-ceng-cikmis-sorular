#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node
    struct Node* prev;  // Pointer to the previous node
};

// Function to create a new node
// Allocates memory for a new node, sets the data, and initializes both pointers to NULL.
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->data = data;      // Set the node's data
    newNode->next = NULL;      // Initialize next pointer to NULL
    newNode->prev = NULL;      // Initialize previous pointer to NULL
    return newNode;            // Return the new node
}

// Function to insert a node at the beginning of the list
// Updates the head pointer to point to the new node.
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Create a new node
    if (*head == NULL) {                       // If the list is empty
        *head = newNode;                       // Set new node as head
        return;
    }
    newNode->next = *head;                     // Link new node's next to current head
    (*head)->prev = newNode;                   // Link current head's previous to new node
    *head = newNode;                           // Update head to the new node
}

// Function to insert a node at the end of the list
// Traverses to the end and appends the new node.
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);   // Create a new node
    if (*head == NULL) {                       // If the list is empty
        *head = newNode;                       // Set new node as head
        return;
    }
    struct Node* tail = *head;                 // Start from the head
    while (tail->next != NULL) {               // Traverse to the last node
        tail = tail->next;
    }
    tail->next = newNode;                      // Append the new node after the last node
    newNode->prev = tail;                      // Link new node's previous to the tail
}

// Function to insert a node after a given index (0-based)
// Inserts the new node after the node at the specified index.
void insertAfterIndex(struct Node** head, int data, int index) {
    struct Node* newNode = createNode(data);   // Create a new node

    // Insertion at beginning if index is 0
    if (index == 0) {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head != NULL) {                   // If the list is not empty
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    struct Node* temp = *head;                 // Start from the head
    // Traverse to the node at (index - 1) position
    for (int i = 0; i < index - 1; i++) {
        if (temp == NULL) return;              // If index is out of bounds, exit
        temp = temp->next;
    }
    newNode->next = temp->next;                // Link new node's next to temp's next
    newNode->prev = temp;                      // Link new node's previous to temp
    if (temp->next != NULL) {                  // If there is a node after temp
        temp->next->prev = newNode;            // Update that node's previous pointer to the new node
    }
    temp->next = newNode;                      // Link temp's next to the new node
}

// Function to delete the node from the beginning of the list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) return;                 // If the list is empty, do nothing
    struct Node* temp = *head;                 // Store the current head
    *head = (*head)->next;                     // Update head to the next node
    if (*head != NULL) {                       // If the list is not empty after deletion
        (*head)->prev = NULL;                  // Set new head's previous pointer to NULL
    }
    free(temp);                                // Free the memory of the old head
}

// Function to delete the node from the end of the list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) return;                 // If the list is empty, do nothing
    if ((*head)->next == NULL) {               // If there is only one node in the list
        free(*head);                         // Free it
        *head = NULL;
        return;
    }
    struct Node* tail = *head;                 // Start from the head
    while (tail->next != NULL) {               // Traverse to the last node
        tail = tail->next;
    }
    tail->prev->next = NULL;                   // Update the second-last node's next pointer to NULL
    free(tail);                                // Free the last node
}

// Function to delete a node at a given index (0-based)
// Deletes the node located at the specified index.
void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL) return;                 // If the list is empty, do nothing
    struct Node* temp = *head;
    if (index == 0) {                          // If deleting the first node
        *head = temp->next;                    // Update head to the next node
        if (*head != NULL) {
            (*head)->prev = NULL;              // Set new head's previous pointer to NULL
        }
        free(temp);                            // Free the old head
        return;
    }
    // Traverse to the node at the given index
    for (int i = 0; temp != NULL && i < index; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;                  // If index is out of bounds, do nothing
    if (temp->next != NULL) {                  // If there is a node after the node to be deleted
        temp->next->prev = temp->prev;         // Update its previous pointer
    }
    if (temp->prev != NULL) {                  // If there is a node before the node to be deleted
        temp->prev->next = temp->next;         // Update its next pointer
    }
    free(temp);                                // Free the node
}

// Function to reverse the doubly linked list
// Reverses the order of the nodes in the list.
void reverseList(struct Node** head) {
    struct Node* current = *head;              // Start from the head
    struct Node* temp = NULL;                  // Temporary pointer for swapping
    while (current != NULL) {
        // Swap the previous and next pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;               // Move to the next node (using prev due to swap)
    }
    if (temp != NULL) {
        *head = temp->prev;                    // Update head to the new first node
    }
}

// Function to print the doubly linked list
// Prints each node's data in order until the end of the list.
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);        // Print the node's data
        node = node->next;                     // Move to the next node
    }
    printf("NULL\n");                          // Indicate the end of the list
}

int main() {
    struct Node* head = NULL;  // Initialize the doubly linked list as empty

    // Insert nodes at the end
    printf("Initial list:\n");
    insertAtEnd(&head, 10); // Append 10
    insertAtEnd(&head, 20); // Append 20
    insertAtEnd(&head, 30); // Append 30
    printList(head);

    // Insert node at the beginning
    printf("\nInsert 5 at the beginning:\n");
    insertAtBeginning(&head, 5);  // Prepend 5
    printList(head);

    // Insert node at the end
    printf("\nInsert 40 at the end:\n");
    insertAtEnd(&head, 40); // Append 40
    printList(head);

    // Insert node after a given index (insert 25 after index 1)
    printf("\nInsert 25 after index 1:\n");
    insertAfterIndex(&head, 25, 2); // Insert 25 after the node at index 1
    printList(head);

    // Delete node from the beginning
    printf("\nDelete from the beginning:\n");
    deleteFromBeginning(&head);
    printList(head);

    // Delete node at index 2
    printf("\nDelete node at index 2:\n");
    deleteAtIndex(&head, 2);
    printList(head);

    // Delete node from the end
    printf("\nDelete from the end:\n");
    deleteFromEnd(&head);
    printList(head);

    // Reverse the list
    printf("\nReverse the list:\n");
    reverseList(&head);
    printList(head);

    return 0;
}

