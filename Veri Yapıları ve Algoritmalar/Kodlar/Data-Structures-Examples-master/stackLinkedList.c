#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* createNode(int newData) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));

    stackNode->data = newData;
    stackNode->next = NULL;

    return stackNode;
}

int isEmpty(struct StackNode *root){
    return !root;
}

void push(struct StackNode **root, int data) {
    struct StackNode *newNode = createNode(data);

    newNode->next = *root;
    *root = newNode;
}

int pop(struct StackNode **root){
    if (isEmpty(*root)) return -1;

    struct StackNode *temp = *root;
    int tempData = temp->data;

    *root = temp->next;
    free(temp);

    return tempData;
}

int peek(struct StackNode *root){
    if (isEmpty(root)) return -1;

    return (root->data);
}

void printStack(struct StructNode *root){
    if(isEmpty(root)) return;

    struct StackNode *iter = root;

    while(iter != NULL){
        printf("%d\n", iter->data);
        iter = iter->next;
    }
}

int main() {
    struct StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);
    push(&root, 50);

    printStack(root);

    printf("Popped: %d\n", pop(&root));
    printf("Popped: %d\n", pop(&root));
    printf("Popped: %d\n", pop(&root));

    printStack(root);

    printf("Peeked: %d\n", peek(root));

    printStack(root);

    return 0;
}