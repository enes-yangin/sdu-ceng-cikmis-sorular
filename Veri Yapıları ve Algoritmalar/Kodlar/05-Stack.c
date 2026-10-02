#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum capacity of the stack

// Define the Stack structure using an array.
typedef struct {
    int items[MAX]; // Array to store stack elements.
    int top;        // Index of the top element in the stack.
} Stack;

/*
 * initStack: Initializes the stack.
 * Explanation: This function sets the top index to -1, indicating that the stack is empty.
 */
void initStack(Stack *s) {
    s->top = -1;
}

/*
 * isEmpty: Checks if the stack is empty.
 * Explanation: Returns 1 (true) if the stack is empty, otherwise returns 0 (false).
 */
int isEmpty(Stack *s) {
    return s->top == -1;
}

/*
 * isFull: Checks if the stack is full.
 * Explanation: Returns 1 (true) if the stack has reached its maximum capacity, otherwise returns 0 (false).
 */
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

/*
 * push: Pushes an element onto the stack.
 * Explanation: This function adds a new element to the top of the stack. It first checks if the stack is full.
 */
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow. Cannot push %d\n", value);
        return;
    }
    s->items[++(s->top)] = value;
}

/*
 * pop: Removes the top element from the stack and returns it.
 * Explanation: This function first checks if the stack is empty. If not, it returns the top element and decrements the top index.
 */
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow. Cannot pop from an empty stack.\n");
        exit(1); // Terminate the program in case of underflow.
    }
    return s->items[(s->top)--];
}

/*
 * peek: Returns the top element of the stack without removing it.
 * Explanation: This function checks if the stack is empty and then returns the top element.
 */
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No top element.\n");
        exit(1); // Terminate the program if the stack is empty.
    }
    return s->items[s->top];
}

/*
 * size: Returns the number of elements in the stack.
 * Explanation: This function calculates the current size of the stack by adding one to the top index.
 */
int size(Stack *s) {
    return s->top + 1;
}

/*
 * printStack: Prints all elements in the stack from top to bottom.
 * Explanation: This function iterates from the top element down to the bottom of the stack and prints each element.
 */
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

/*
 * main: Demonstrates the stack operations.
 * Explanation: This function creates a stack, performs several operations (push, pop, peek, size, and printStack),
 * and prints the results.
 */
int main() {
    Stack stack;
    initStack(&stack);
    
    // Push elements onto the stack.
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    // Display the stack.
    printStack(&stack);
    
    // Peek the top element.
    printf("Top element: %d\n", peek(&stack));
    
    // Pop an element from the stack.
    printf("Popped element: %d\n", pop(&stack));
    
    // Display the current size of the stack.
    printf("Stack size: %d\n", size(&stack));
    
    // Print the stack after pop operation.
    printStack(&stack);
    
    return 0;
}
