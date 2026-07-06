#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;      // Element found
        }
        else if (arr[mid] < key) {
            start = mid + 1; // Search right half
        }
        else {
            end = mid - 1;   // Search left half
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int index = binarySearch(arr, n, key);

    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";

    return 0;
}