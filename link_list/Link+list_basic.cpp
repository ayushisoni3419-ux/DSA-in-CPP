#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Push Front (Insert at Beginning)
void pushFront(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Push Back (Insert at End)
void pushBack(Node* &head, int val) {
    Node* newNode = new Node(val);

    // If list is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert at the end
    temp->next = newNode;
}

// Print Linked List
void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    cout << "After Push Front:" << endl;
    pushFront(head, 30);
    pushFront(head, 20);
    pushFront(head, 10);
    print(head);

    cout << "\nAfter Push Back:" << endl;
    pushBack(head, 40);
    pushBack(head, 50);
    print(head);

    return 0;
}