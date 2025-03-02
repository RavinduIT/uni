#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode *left, *right;
} AVLNode;

// Function to get height of a node
int height(AVLNode *node) {
    return (node == NULL) ? 0 : node->height;
}

// Function to compute balance factor
int getBalance(AVLNode *node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

// Create a new node
AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

// Right rotation (LL case)
AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Left rotation (RR case)
AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Insert a node into the AVL tree
AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = getBalance(node);

    // Balancing cases
    if (balance > 1 && key < node->left->key) return rightRotate(node); // LL
    if (balance < -1 && key > node->right->key) return leftRotate(node); // RR
    if (balance > 1 && key > node->left->key) { // LR
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) { // RL
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find the smallest node
AVLNode* findMin(AVLNode* node) {
    while (node->left) node = node->left;
    return node;
}

// Find the largest node
AVLNode* findMax(AVLNode* node) {
    while (node->right) node = node->right;
    return node;
}

// In-order traversal to display the tree
void inOrder(AVLNode *root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Main function
int main() {
    AVLNode *root = NULL;
    int keys[] = {2, 5, 4, 6, 7, 9, 8, 3, 1, 10};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    printf("In-order traversal: ");
    inOrder(root);
    
    printf("\nSmallest TID: %d", findMin(root)->key);
    printf("\nLargest TID: %d", findMax(root)->key);

    return 0;
}
