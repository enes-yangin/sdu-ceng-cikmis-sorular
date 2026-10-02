#include <stdio.h>
#include <stdlib.h>

//Stack Queue Ciddi Binary Tree
//inorder postorder Ağaç çiz

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

struct Node *insert(struct Node *q, int x) {
    if (q == NULL)
        return newNode(x);
    else if (x <= q->data)
        q->left = insert(q->left, x);
    else
        q->right = insert(q->right, x);
    return (q);
}

int size(struct Node *root) {
    if (root == NULL) return 0;

    size(root->left + 1 + size(root->right));
}

int maxDepth(struct Node *q) {
    if (q == NULL) return 0;

    int lDepth = maxDepth(q->left);
    int rDepth = maxDepth(q->right);

    if (lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
}

int minValue(struct Node *q) {
    struct Node *q2 = q;

    while (q2->left != NULL)
        q2 = q2->left;

    return q2->data;
}

//Yapraklar alınsın 1.seviyeye gitsin vs.

void mirror(struct Node *q) {
    if (q == NULL) return;

    struct Node *temp;

    mirror(q->left);
    mirror(q->right);

    temp = q->left;
    q->left = q->right;
    q->right = temp;
}

int main() {
    struct Node *root;
}