#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100  // Maximum capacity of the queue

// Define the Queue structure using an array.
typedef struct {
    int items[MAX]; // Array to store queue elements.
    int front;      // Index of the front element.
    int rear;       // Index of the rear element.
} Queue;

/*
 * createQueue: Allocates memory for a new queue and initializes its members.
 * Returns a pointer to the newly created Queue.
 */
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

/*
 * isEmpty: Checks if the queue is empty.
 * Returns 1 (true) if the queue is empty, 0 (false) otherwise.
 */
int isEmpty(Queue* q) {
    return q->front == -1;
}

/*
 * isFull: Checks if the queue is full.
 * Returns 1 (true) if the queue is full, 0 (false) otherwise.
 */
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

/*
 * enqueue: Adds a new element to the rear of the queue.
 * If the queue is full, it prints an error message.
 * Explanation: This function inserts the given value at the end of the queue.
 */
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        // If the queue is empty, initialize the front index.
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

/*
 * dequeue: Removes and returns the front element of the queue.
 * If the queue is empty, it prints an error message and returns INT_MIN.
 * Explanation: This function removes the element from the front of the queue and returns it.
 */
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return INT_MIN;
    }
    int value = q->items[q->front];
    // If the queue has only one element, reset the queue after removal.
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

/*
 * frontElement: Returns the element at the front of the queue without removing it.
 * If the queue is empty, it prints an error message and returns INT_MIN.
 * Explanation: This function retrieves the front element without dequeuing it.
 */
int frontElement(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front element.\n");
        return INT_MIN;
    }
    return q->items[q->front];
}

/*
 * displayQueue: Prints all the elements in the queue from front to rear.
 * Explanation: This function traverses the queue from the front index to the rear index and prints each element.
 */
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

/*
 * size: Returns the number of elements currently in the queue.
 * Explanation: This function calculates the current size by subtracting the front index from the rear index and adding one.
 */
int size(Queue* q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q->rear - q->front + 1;
}

// Main function to demonstrate the Queue operations.
int main() {
    // Create a new Queue.
    Queue* q = createQueue();

    // Enqueue elements into the queue.
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Display the current queue.
    printf("Queue: ");
    displayQueue(q);

    // Dequeue an element and display it.
    printf("Dequeued: %d\n", dequeue(q));

    // Display the queue after a dequeue operation.
    printf("Queue after dequeue: ");
    displayQueue(q);

    // Retrieve and display the front element.
    printf("Front element: %d\n", frontElement(q));

    // Display the current size of the queue.
    printf("Queue size: %d\n", size(q));

    // Free the allocated memory for the queue.
    free(q);
    return 0;
}

