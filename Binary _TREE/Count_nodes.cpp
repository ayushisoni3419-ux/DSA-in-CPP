#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root){
    if(root == NULL)
        return 0;

    return max(height(root->left),
               height(root->right)) + 1;
}

int countNodes(Node* root){
    if(root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

int countLeaf(Node* root){
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left)
         + countLeaf(root->right);
}

int sum(Node* root){
    if(root == NULL)
        return 0;

    return root->data
         + sum(root->left)
         + sum(root->right);
}

int maximum(Node* root){
    if(root == NULL)
        return INT_MIN;

    return max(root->data,
           max(maximum(root->left),
               maximum(root->right)));
}

int main(){

    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->left = new Node(60);
    root->right->right = new Node(70);

    cout << "Height            : " << height(root) << endl;
    cout << "Total Nodes       : " << countNodes(root) << endl;
    cout << "Leaf Nodes        : " << countLeaf(root) << endl;
    cout << "Sum of Nodes      : " << sum(root) << endl;
    cout << "Maximum Node Value: " << maximum(root) << endl;

    return 0;
}