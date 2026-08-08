#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Insert a value into BST
Node* insert(Node* root, int value) {

    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search for a value in BST
bool search(Node* root, int key) {

    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Find minimum value
Node* findMin(Node* root) {

    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Find maximum value
Node* findMax(Node* root) {

    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

int main() {

    Node* root = NULL;

    // Creating BST using insertion
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Search
    int key = 60;

    if (search(root, key))
        cout << key << " found in BST" << endl;
    else
        cout << key << " not found in BST" << endl;

    // Minimum
    Node* minimum = findMin(root);

    if (minimum != NULL)
        cout << "Minimum value: "
             << minimum->data << endl;

    // Maximum
    Node* maximum = findMax(root);

    if (maximum != NULL)
        cout << "Maximum value: "
             << maximum->data << endl;

    return 0;
}