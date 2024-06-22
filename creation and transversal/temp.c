#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    // If the tree is empty, create a new node and return it as the root
    if (root == NULL) {
        root = createNode(data);
    }
    // Otherwise, insert the new node recursively
    else {
        // If the data is less than the root's data, insert it into the left subtree
        if (data < root->data) {
            root->left = insertNode(root->left, data);
        }
        // If the data is greater than or equal to the root's data, insert it into the right subtree
        else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

// Function to print the elements of the binary tree in inorder traversal
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to test the binary tree implementation
int main() {
    struct TreeNode* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
