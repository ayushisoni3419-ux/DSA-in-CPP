#include <iostream>
using namespace std;

// Create Node
class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Insert at Head
void insertAtHead(Node* &head, int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Print Linked List
void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;

    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    cout << "Linked List: ";
    printList(head);

    return 0;
}