#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26 // Assuming only lowercase letters a-z

// Node structure
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to insert a node into the BST (no duplicates)
struct Node* insert(struct Node* root, char data) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) { // Prevent duplicates
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the height of the tree
int findHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Function to find the size of the tree
int findSize(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return findSize(root->left) + findSize(root->right) + 1;
    }
}

// Function to find the minimum value node
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value node
struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to create a mirror image of the tree
void mirrorImage(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp;
    mirrorImage(root->left);
    mirrorImage(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Function to print the mirrored tree in a readable format
void printMirrorTree(struct Node* root, int space) {
    if (root == NULL) return;
    space += 5; // Increase distance between levels
    printMirrorTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%c\n", root->data);
    printMirrorTree(root->left, space);
}

// Main function
int main() {
    struct Node* root = NULL;
    FILE* file = fopen("input.txt", "r");
    char word[100];
    int charPresent[ALPHABET_SIZE] = {0}; // Array to track unique characters

    // Read words from file and insert into BST
    while (fscanf(file, "%s", word) != EOF) {
        for (int i = 0; word[i] != '\0'; i++) {
            int index = word[i] - 'a'; // Convert char to index (0-25)
            if (!charPresent[index]) { // Check if character is already inserted
                root = insert(root, word[i]);
                charPresent[index] = 1; // Mark as present
            }
        }
    }
    fclose(file);

    // Print the required outputs
    printf("Height of tree: %d\n", findHeight(root));
    printf("Size of tree: %d\n", findSize(root));
    printf("Minimum value: %c\n", findMin(root)->data);
    printf("Maximum value: %c\n", findMax(root)->data);
    
    // Print the mirror image of the tree
    printf("Mirror Image of the tree:\n");
    mirrorImage(root);
    printMirrorTree(root, 0); // Print mirrored tree in a readable format

    return 0;
}