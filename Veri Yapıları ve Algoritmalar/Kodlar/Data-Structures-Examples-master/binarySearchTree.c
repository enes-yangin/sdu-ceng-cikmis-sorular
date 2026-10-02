#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int data) {
    if (root == NULL) return createNode(data);

    if (data <= root->data)
        root->left = insert(root->left, data);
    else if (data >= root->data)
        root->right = insert(root->right, data);

    return root;
}

void inOrder(struct Node *root) {
    if (root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(struct Node *root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct Node *root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int size(struct Node *root) {
    if (root == NULL) return 0;

    return (size(root->left) + size(root->right) + 1);
}

int maxDepth(struct Node *root) {
    if (root == NULL) return 0;

    int lDepth = maxDepth(root->left);
    int rDepth = maxDepth(root->right);

    if (lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
}

int minValue(struct Node *root) {
    struct Node *iter = root;

    while (iter->left != NULL)
        iter = iter->left;

    return iter->data;
}

int minValueRecur(struct Node *root) {
    if (root->left == NULL) return root->data;

    minValueRecur(root->left);
}

void mirror(struct Node *root) {
    if (root == NULL) return;

    mirror(root->left);
    mirror(root->right);

    struct Node *temp;

    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void pathFind(struct Node *root){
    int array[1000];

    pathFindingRecur(root, array, 0);
}

void printPath(int array[], int length){
    for (int i = 0; i < length; i++){
        if (i != length - 1)
            printf("%d->", array[i]);
        else
            printf("%d\n", array[i]);
        
    }
}

void pathFindingRecur(struct Node *root, int array[], int length) {
    if (root == NULL) return;

    array[length] = root->data;
    length++;

    if(root->left == NULL && root->right == NULL){
        printPath(array, length);
    }else{
        pathFindingRecur(root->left, array, length);
        pathFindingRecur(root->right, array, length);
    }
}

int main() {
    struct Node *root = NULL;

    printf("Size: %d\n", size(root));

    /* 

    Oluşturulacak Binary Search Tree
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 

    */

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Size: %d\n", size(root));
    printf("Max Depth: %d\n", maxDepth(root));
    printf("Min Value: %d\n", minValue(root));
    printf("Min Value Recursive: %d\n", minValueRecur(root));

    inOrder(root);

    //mirror(root);
    //printf("\n");
    //inOrder(root);

    printf("\nPaths\n");
    pathFind(root);

    return 0;
}