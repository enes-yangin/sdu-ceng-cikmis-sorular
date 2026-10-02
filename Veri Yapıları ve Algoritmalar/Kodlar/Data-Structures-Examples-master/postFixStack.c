#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    int *array;
    unsigned capacity;
};

struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));

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

// strlen = bir string dizisinin uzunlugu -> string.h icinde
// isdigit = numara olup olmadigini kontrol eder -> ctype.h icinde
int calcPostfix(char *expression) {
    struct Stack *stack = createStack(strlen(expression));

    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i]))
            push(stack, expression[i] - '0');  //- '0' karakter atanamasın demek
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (expression[i]) {
                case '+':
                    push(stack, val2 + val1);
                    break;
                case '-':
                    push(stack, val2 - val1);
                    break;
                case '/':
                    push(stack, val2 / val1);
                    break;
                case '*':
                    push(stack, val2 * val1);
                    break;
                default:
                    printf("Gecersiz Operator\n");
            }
        }
    }

    return pop(stack);
}

int main() {
    char str[] = "2345+-6/*";
    printf("Sonuc: %d\n", calcPostfix(str));
    return 0;
}