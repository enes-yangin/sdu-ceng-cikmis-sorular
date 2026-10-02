#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node.
typedef struct Node {
    int data;               // Data value stored in the node.
    struct Node* left;      // Pointer to the left child.
    struct Node* right;     // Pointer to the right child.
} Node;

/*
 * createNode: Creates a new binary tree node with the given data.
 * Explanation: This function allocates memory for a new node, initializes its data,
 * and sets both left and right children to NULL.
 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*
 * insert: Inserts a new node with the given data into the binary search tree.
 * Explanation: This function recursively finds the correct position for the new data
 * in the tree following BST properties and inserts it.
 */
Node* insert(Node* root, int data) {
    if(root == NULL) {
        // If tree is empty, return a new node.
        return createNode(data);
    }
    if(data < root->data) {
        // Insert in the left subtree if data is less than current node's data.
        root->left = insert(root->left, data);
    } else if(data > root->data) {
        // Insert in the right subtree if data is greater than current node's data.
        root->right = insert(root->right, data);
    }
    // If data is equal, duplicates are not inserted.
    return root;
}

/*
 * search: Searches for a node with the given data in the binary search tree.
 * Explanation: This function recursively traverses the tree. If the value is found, 
 * it returns the pointer to the node; otherwise, it returns NULL.
 */
Node* search(Node* root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    }
    if(data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

/*
 * inorderTraversal: Performs an inorder traversal of the binary tree.
 * Explanation: This function recursively visits the left subtree, prints the node's data,
 * and then visits the right subtree. Inorder traversal of a BST gives nodes in ascending order.
 */
void inorderTraversal(Node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

/*
 * preorderTraversal: Performs a preorder traversal of the binary tree.
 * Explanation: This function prints the node's data first, then recursively visits the left
 * and right subtrees. Preorder traversal is useful for creating a copy of the tree.
 */
void preorderTraversal(Node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

/*
 * postorderTraversal: Performs a postorder traversal of the binary tree.
 * Explanation: This function recursively visits the left and right subtrees first, and then 
 * prints the node's data. Postorder traversal is useful for deleting the tree.
 */
void postorderTraversal(Node* root) {
    if(root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

/*
 * findMin: Finds the node with the minimum value in the binary search tree.
 * Explanation: The minimum value is located at the leftmost node in a BST. This function
 * iteratively traverses the left subtree until it finds the leftmost node.
 */
Node* findMin(Node* root) {
    while(root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

/*
 * deleteNode: Deletes a node with the given data from the binary search tree.
 * Explanation: This function recursively finds the node to be deleted. Once found, it handles 
 * three cases:
 *   1. Node with only one child or no child.
 *   2. Node with two children: Replace the node's value with the minimum value from the right subtree,
 *      and then delete that minimum node.
 */
Node* deleteNode(Node* root, int data) {
    if(root == NULL) {
        return root;
    }
    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one child or no child.
        if(root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        // Copy the inorder successor's data to this node.
        root->data = temp->data;
        // Delete the inorder successor.
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/*
 * treeHeight: Computes the height of the binary tree.
 * Explanation: This function recursively calculates the height of the tree as the maximum height 
 * between the left and right subtrees plus one.
 */
int treeHeight(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Main function to demonstrate the binary search tree operations.
int main() {
    Node* root = NULL;
    
    // Insert elements into the binary search tree.
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Display the tree using different traversals.
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Search for a value in the tree.
    int valueToSearch = 40;
    Node* foundNode = search(root, valueToSearch);
    if(foundNode != NULL) {
        printf("Value %d found in the tree.\n", valueToSearch);
    } else {
        printf("Value %d not found in the tree.\n", valueToSearch);
    }

    // Delete a node from the tree.
    root = deleteNode(root, 30);
    printf("Inorder traversal after deleting 30: ");
    inorderTraversal(root);
    printf("\n");

    // Get the height of the tree.
    int height = treeHeight(root);
    printf("Height of the tree: %d\n", height);

    return 0;
}
