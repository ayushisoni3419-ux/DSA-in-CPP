#include <iostream>
#include <cmath>
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

// 1. Diameter of Binary Tree
// Returns height and updates diameter using reference
int diameter(Node* root, int& ans) {

    if (root == NULL)
        return 0;

    int leftHeight = diameter(root->left, ans);
    int rightHeight = diameter(root->right, ans);

    // Diameter passing through current node
    ans = max(ans, leftHeight + rightHeight);

    // Return height of current subtree
    return max(leftHeight, rightHeight) + 1;
}

// 2. Check Balanced Binary Tree
// Returns height if balanced, otherwise -1
int checkHeight(Node* root) {

    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left);

    if (leftHeight == -1)
        return -1;

    int rightHeight = checkHeight(root->right);

    if (rightHeight == -1)
        return -1;

    // If height difference is greater than 1,
    // tree is not balanced
    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

// 3. Check if Two Trees are Identical
bool areIdentical(Node* root1, Node* root2) {

    // Both trees are empty
    if (root1 == NULL && root2 == NULL)
        return true;

    // One tree is empty and the other is not
    if (root1 == NULL || root2 == NULL)
        return false;

    // Data values are different
    if (root1->data != root2->data)
        return false;

    // Check left and right subtrees
    return areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

int main() {

    // -------------------------
    // First Binary Tree
    // -------------------------

    Node* root1 = new Node(10);

    root1->left = new Node(20);
    root1->right = new Node(30);

    root1->left->left = new Node(40);
    root1->left->right = new Node(50);

    root1->right->left = new Node(60);
    root1->right->right = new Node(70);


    // -------------------------
    // Second Binary Tree
    // -------------------------

    Node* root2 = new Node(10);

    root2->left = new Node(20);
    root2->right = new Node(30);

    root2->left->left = new Node(40);
    root2->left->right = new Node(50);

    root2->right->left = new Node(60);
    root2->right->right = new Node(70);


    // -------------------------
    // Diameter
    // -------------------------

    int diameterValue = 0;

    diameter(root1, diameterValue);

    cout << "Diameter: "
         << diameterValue << endl;


    // -------------------------
    // Balanced Tree
    // -------------------------

    cout << "Balanced: "
         << (isBalanced(root1) ? "Yes" : "No")
         << endl;


    // -------------------------
    // Identical Trees
    // -------------------------

    cout << "Identical Trees: "
         << (areIdentical(root1, root2) ? "Yes" : "No")
         << endl;


    return 0;
}