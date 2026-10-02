#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int *array;
    unsigned capacity;
};

struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(sizeof(int) * stack->capacity);

    return stack;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == stack->capacity - 1);
}

void push(struct Stack *stack, int newData) {
    if (isFull(stack)) return;

    stack->array[++stack->top] = newData;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) return -1;

    return (stack->array[stack->top--]);
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) return -1;

    return (stack->array[stack->top]);
}

void print(struct Stack *stack) {
    if (isEmpty(stack)) return;

    for (int i = stack->top; i >= 0; i--)
        printf("%d\n", stack->array[i]);
}

int main() {
    struct Stack *stack = createStack(5);

    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    push(stack, 20);
    push(stack, 25);

    print(stack);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    print(stack);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
}