#include <iostream>
#include <memory>

using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
};

Node* MakeNode(int data){
    
    Node* root = new Node();
    root->data = data;
    root->right = root->left = NULL;
    return root;
    
}

Node* Insert(Node* root, int data){
    
    if(root == NULL){
        root = MakeNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(Node* root, int data){
    
    if(root == NULL){
        return false;
    }
    else if(data == root->data){
        return true;
    }
    else if(data < root->data){
        return Search(root->left, data);
    }
    return Search(root->left, data);
    
} 

int main() {
    int search;
    Node* root = NULL;
    
    while(1){
        int data;
        cout << "Enter ur data(0 to exit): ";
        cin >> data;
        if(data == 0){
            break;
        }
        root = Insert(root, data);
    }
    cout << "Enter the data that you wanna search: ";
    cin >> search;
    if(Search(root, search)){
        cout << "Found it";
    }else{
        cout << "Couldn't find";
    }
    return 0;
}