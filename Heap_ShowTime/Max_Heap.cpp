#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

public:

    // Insert element into Max Heap
    void insert(int value) {

        // Add element at the end
        heap.push_back(value);

        int i = heap.size() - 1;

        // Heapify Up
        while (i > 0) {

            int parent = (i - 1) / 2;

            // Max Heap property is satisfied
            if (heap[parent] >= heap[i])
                break;

            // Swap child and parent
            swap(heap[parent], heap[i]);

            // Move upward
            i = parent;
        }
    }

    // Return maximum element
    int peek() {

        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        return heap[0];
    }

    // Delete root element
    void deleteRoot() {

        if (heap.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        // Move last element to root
        heap[0] = heap.back();

        // Remove last element
        heap.pop_back();

        // Heapify will be added later
    }

    // Display heap
    void display() {

        for (int value : heap) {
            cout << value << " ";
        }

        cout << endl;
    }
};

int main() {

    MaxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);

    cout << "Max Heap: ";
    h.display();

    cout << "Maximum: " << h.peek() << endl;

    h.deleteRoot();

    cout << "After deleting root: ";
    h.display();

    return 0;
}