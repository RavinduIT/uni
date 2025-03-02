#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node Structure
typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode *left, *right;
} AVLNode;

// Rotation count array: [LL, RR, LR, RL]
int rotationCount[4] = {0, 0, 0, 0};

// Function to get the height of a node
int height(AVLNode *node) {
    return (node == NULL) ? 0 : node->height;
}

// Function to get balance factor
int getBalance(AVLNode *node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

// Function to create a new node
AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

// Right Rotation (LL Rotation)
AVLNode* rightRotate(AVLNode *y) {
    rotationCount[0]++; // Increment LL count
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));
    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));

    return x;
}

// Left Rotation (RR Rotation)
AVLNode* leftRotate(AVLNode *x) {
    rotationCount[1]++; // Increment RR count
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));
    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));

    return y;
}

// Left-Right Rotation (LR Rotation)
AVLNode* leftRightRotate(AVLNode *node) {
    rotationCount[2]++; // Increment LR count
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

// Right-Left Rotation (RL Rotation)
AVLNode* rightLeftRotate(AVLNode *node) {
    rotationCount[3]++; // Increment RL count
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

// AVL Tree Insertion with Rotation Counting
AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node; // No duplicates allowed

    // Update height
    node->height = 1 + ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Perform rotations and count them
    if (balance > 1 && key < node->left->key) return rightRotate(node);  // LL
    if (balance < -1 && key > node->right->key) return leftRotate(node);  // RR
    if (balance > 1 && key > node->left->key) return leftRightRotate(node);  // LR
    if (balance < -1 && key < node->right->key) return rightLeftRotate(node);  // RL

    return node;
}

// Function to print in-order traversal of the tree
void inOrder(AVLNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Function to get the smallest node (minimum transaction ID)
AVLNode* findMin(AVLNode *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to get the largest node (maximum transaction ID)
AVLNode* findMax(AVLNode *node) {
    while (node->right != NULL)
        node = node->right;
    return node;
}

// Function to get the tree height
int getTreeHeight(AVLNode* root) {
    return height(root);
}

int main() {
    AVLNode *root = NULL;

    // Insert transaction IDs in given order
    int keys[] = {2, 5, 4, 6, 7, 9, 8, 3, 1, 10};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    // Print in-order traversal
    printf("In-order traversal of AVL tree: ");
    inOrder(root);
    printf("\n");

    // Print the smallest and largest transaction ID
    printf("Smallest transaction ID: %d\n", findMin(root)->key);
    printf("Largest transaction ID: %d\n", findMax(root)->key);

    // Print tree height
    printf("Final height of AVL tree: %d\n", getTreeHeight(root));

    // Print rotation counts
    printf("\nTotal Rotations Performed:\n");
    printf("LL Rotations: %d\n", rotationCount[0]);
    printf("RR Rotations: %d\n", rotationCount[1]);
    printf("LR Rotations: %d\n", rotationCount[2]);
    printf("RL Rotations: %d\n", rotationCount[3]);

    return 0;
}
