#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

public:

    // Insert element and Heapify Up
    void insert(int value) {
        heap.push_back(value);

        int i = heap.size() - 1;

        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] >= heap[i])
                break;

            swap(heap[parent], heap[i]);

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

    // Heapify Down
    void heapify(int i) {
        int n = heap.size();

        while (true) {
            int largest = i;

            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);

            i = largest;
        }
    }

    // Delete root element
    void deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapify(0);
    }

    // Display heap
    void display() {
        for (int value : heap)
            cout << value << " ";

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
    h.insert(60);

    cout << "Max Heap: ";
    h.display();

    cout << "Maximum: " << h.peek() << endl;

    h.deleteRoot();

    cout << "After deleting root: ";
    h.display();

    cout << "New maximum: " << h.peek() << endl;

    return 0;
}