#include <iostream>
#include <queue>
using namespace std;

// Node class for Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to perform Level Order Traversal
void levelOrder(Node* root) {

    // If tree is empty
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        // Get the front node
        Node* current = q.front();
        q.pop();

        // Print current node
        cout << current->data << " ";

        // Add left child to queue
        if (current->left != NULL) {
            q.push(current->left);
        }

        // Add right child to queue
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {

    // Creating the Binary Tree
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->left = new Node(60);
    root->right->right = new Node(70);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}