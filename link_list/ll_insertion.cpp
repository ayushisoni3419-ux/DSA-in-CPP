#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at Beginning (Push Front)
void pushFront(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at End (Push Back)
void pushBack(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at Any Position (1-based indexing)
void insertAtPosition(Node* &head, int val, int pos) {

    if (pos == 1) {
        pushFront(head, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid Position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
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

    // Insert at Beginning
    pushFront(head, 20);
    pushFront(head, 10);

    // Insert at End
    pushBack(head, 40);
    pushBack(head, 50);

    // Insert at Position
    insertAtPosition(head, 30, 3);

    cout << "Linked List:" << endl;
    print(head);

    return 0;
}