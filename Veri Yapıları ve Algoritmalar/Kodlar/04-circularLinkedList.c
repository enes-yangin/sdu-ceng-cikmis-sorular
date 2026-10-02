#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for the circular linked list.
typedef struct Node {
    int data;              // Data stored in the node.
    struct Node* next;     // Pointer to the next node in the list.
} Node;

/*
 * createNode: Allocates and initializes a new node with the given data.
 * Explanation: This function allocates memory for a new node, sets its data field,
 * and makes its next pointer point to itself, since it will be used in a circular list.
 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Initially, the new node points to itself.
    return newNode;
}

/*
 * insertAtBeginning: Inserts a new node at the beginning of the circular linked list.
 * Explanation: If the list is empty, the new node becomes the head.
 * Otherwise, the function finds the last node, updates its next pointer to the new node,
 * and makes the new node point to the previous head. The new node becomes the new head.
 */
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if(head == NULL) {
        // List is empty: the new node is the head.
        return newNode;
    }
    Node* curr = head;
    // Traverse to the last node (whose next pointer points to head).
    while(curr->next != head) {
        curr = curr->next;
    }
    curr->next = newNode;  // Last node now points to the new node.
    newNode->next = head;  // New node points to the old head.
    return newNode;        // New node is the new head.
}

/*
 * insertAtEnd: Inserts a new node at the end of the circular linked list.
 * Explanation: If the list is empty, the new node becomes the head.
 * Otherwise, the function finds the last node and inserts the new node after it.
 * The new node's next pointer is set to point to head.
 */
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if(head == NULL) {
        return newNode;
    }
    Node* curr = head;
    while(curr->next != head) {
        curr = curr->next;
    }
    curr->next = newNode;  // Last node now points to the new node.
    newNode->next = head;  // New node points back to head.
    return head;           // Head remains unchanged.
}

/*
 * insertAfter: Inserts a new node after the node containing a specific target value.
 * Explanation: The function searches for the target value in the list. If found,
 * it inserts the new node right after the target node. If the target is not found,
 * the list remains unchanged.
 */
Node* insertAfter(Node* head, int target, int data) {
    if(head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    Node* curr = head;
    do {
        if(curr->data == target) {
            Node* newNode = createNode(data);
            newNode->next = curr->next;
            curr->next = newNode;
            return head;
        }
        curr = curr->next;
    } while(curr != head);
    printf("Element %d not found in the list.\n", target);
    return head;
}

/*
 * displayList: Prints all the elements of the circular linked list.
 * Explanation: The function starts from the head and traverses the list until it comes back to the head.
 */
void displayList(Node* head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* curr = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while(curr != head);
    printf("\n");
}

/*
 * searchNode: Searches for a node with the specified key in the circular linked list.
 * Explanation: This function traverses the list from head to head again and returns a pointer
 * to the node if the key is found; otherwise, it returns NULL.
 */
Node* searchNode(Node* head, int key) {
    if(head == NULL)
        return NULL;
    Node* curr = head;
    do {
        if(curr->data == key)
            return curr;
        curr = curr->next;
    } while(curr != head);
    return NULL;
}

/*
 * deleteNode: Deletes the first node with the specified key from the circular linked list.
 * Explanation: The function handles the deletion of the head node and any other node.
 * For the head deletion, it finds the last node to update its next pointer.
 * If the key is not found, the list remains unchanged.
 */
Node* deleteNode(Node* head, int key) {
    if(head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    
    Node *curr = head, *prev = NULL;
    
    // Check if head node is to be deleted.
    if(head->data == key) {
        // If there is only one node in the list.
        if(head->next == head) {
            free(head);
            return NULL;
        }
        // Find the last node to update its next pointer.
        Node* last = head;
        while(last->next != head)
            last = last->next;
        last->next = head->next;
        Node* temp = head->next;
        free(head);
        return temp;  // New head is the next node.
    }
    
    // Traverse the list to find the node to delete.
    prev = head;
    curr = head->next;
    while(curr != head) {
        if(curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Element %d not found in the list.\n", key);
    return head;
}

/*
 * countNodes: Counts the number of nodes in the circular linked list.
 * Explanation: The function traverses the list starting from the head until it loops back,
 * incrementing a counter for each node.
 */
int countNodes(Node* head) {
    if(head == NULL)
        return 0;
    int count = 0;
    Node* curr = head;
    do {
        count++;
        curr = curr->next;
    } while(curr != head);
    return count;
}

/*
 * main: Demonstrates the circular linked list operations.
 * Explanation: The main function creates a circular linked list and performs various operations:
 *   - Inserting nodes at the beginning, at the end, and after a specific node.
 *   - Displaying the list.
 *   - Searching for a node.
 *   - Counting the nodes.
 *   - Deleting a node.
 */
int main() {
    Node* head = NULL;
    
    // Insert elements at the end.
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    displayList(head);
    
    // Insert an element at the beginning.
    head = insertAtBeginning(head, 5);
    displayList(head);
    
    // Insert an element after a specific node.
    head = insertAfter(head, 20, 25);
    displayList(head);
    
    // Search for an element.
    int key = 25;
    Node* found = searchNode(head, key);
    if(found)
        printf("Element %d found in the list.\n", key);
    else
        printf("Element %d not found in the list.\n", key);
    
    // Count the number of nodes.
    printf("Total nodes in the list: %d\n", countNodes(head));
    
    // Delete a node.
    head = deleteNode(head, 30);
    displayList(head);
    
    return 0;
}

