#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front;
    int rear;

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return rear == 99;
    }

    // Insert an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = value;
    }

    // Remove an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << "Deleted Element: " << arr[front] << endl;
        front++;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Front Element: " << q.getFront() << endl;
    cout << "Rear Element: " << q.getRear() << endl;

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}