#include <stdio.h>
#include <stdlib.h>

// Define the AVL tree node structure
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    int height; // Height of the subtree rooted at this node
};

// Function to create a new AVL tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // New node is initially a leaf with height 1
    return newNode;
}

// Function to calculate the height of a node
int getHeight(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to update the height of a node
void updateHeight(struct TreeNode* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

// Function to perform a right rotation (clockwise)
struct TreeNode* rotateRight(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* z = x->right;

    // Perform rotation
    x->right = y;
    y->left = z;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation (counterclockwise)
struct TreeNode* rotateLeft(struct TreeNode* y) {
    struct TreeNode* x = y->right;
    struct TreeNode* z = x->left;

    // Perform rotation
    x->left = y;
    y->right = z;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return x;
}

// Function to insert a new node into the AVL tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    else // Duplicate values are not allowed
        return root;

    // Update height and balance factor
    updateHeight(root);

    // Check balance factor and perform rotations if needed
    int balance = getHeight(root->left) - getHeight(root->right);
    if (balance > 1) {
        if (value < root->left->value)
            return rotateRight(root);
        else {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (balance < -1) {
        if (value > root->right->value)
            return rotateLeft(root);
        else {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

// Function to traverse the AVL tree in-order
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->value);
    inOrderTraversal(root->right);
}

// Main function to test AVL tree insertion
int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("In-order traversal of AVL tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Clean up (free memory)
    // ...

    return 0;
}
