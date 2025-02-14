#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    struct Node *left, *right;
};

struct Node* createNode(char* word) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char* word) {
    if (root == NULL) {
        return createNode(word);
    }
    if (strcmp(word, root->word) < 0) {
        root->left = insert(root->left, word);
    } else if (strcmp(word, root->word) > 0) {
        root->right = insert(root->right, word);
    }
    return root;
}

int getHeight(struct Node* root) {
    if (root == NULL) return -1;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int getSize(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

char* getMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root->word;
}

char* getMax(struct Node* root) {
    while (root && root->right) root = root->right;
    return root->word;
}

struct Node* createMirror(struct Node* root) {
    if (root == NULL) return NULL;
    struct Node* mirroredNode = createNode(root->word);
    mirroredNode->left = createMirror(root->right);
    mirroredNode->right = createMirror(root->left);
    return mirroredNode;
}

void printTree(struct Node* root, int space) {
    if (root == NULL) return;
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%s\n", root->word);
    printTree(root->left, space);
}

void loadWordsFromFile(const char* filename, struct Node** root) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("File not found.\n");
        return;
    }
    char word[50];
    while (fscanf(file, "%s", word) != EOF) {
        *root = insert(*root, word);
    }
    fclose(file);
}

int main() {
    struct Node* root = NULL;

    loadWordsFromFile("input.txt", &root);

    printf("Height of the tree: %d\n", getHeight(root));
    printf("Size of the tree: %d\n", getSize(root));
    printf("Minimum value in the tree: %s\n", getMin(root));
    printf("Maximum value in the tree: %s\n", getMax(root));

    printf("\nMirror Image of the tree:\n");
    struct Node* mirroredRoot = createMirror(root);
    printTree(mirroredRoot, 0);

    return 0;
}
