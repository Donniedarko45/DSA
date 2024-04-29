#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* create_node(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Create a sample tree
    struct TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    // Sample tree structure:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    // Display the tree structure
    printf("Sample tree structure:\n");
    printf("       %d\n", root->data);
    printf("      / \\\n");
    printf("     %d   %d\n", root->left->data, root->right->data);
    printf("    / \\\n");
    printf("   %d   %d\n", root->left->left->data, root->left->right->data);

    return 0;
}
