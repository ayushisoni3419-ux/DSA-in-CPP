```cpp
#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// ==================== SLIDING WINDOW ====================

int minSubarray(vector<int>& arr, int k) {

    int start = 0;
    int sum = 0;
    int minLen = INT_MAX;

    for(int end = 0; end < arr.size(); end++) {

        sum += arr[end];

        while(sum >= k) {

            minLen = min(minLen, end - start + 1);

            sum -= arr[start];
            start++;
        }
    }

    if(minLen == INT_MAX)
        return 0;

    return minLen;
}


// ==================== LINKED LIST ====================

struct ListNode {

    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

ListNode* reverseList(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL) {

        ListNode* next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(ListNode* head) {

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// ==================== BINARY TREE ====================

struct TreeNode {

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode* root) {

    if(root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}


// ==================== MAIN ====================

int main() {

    // Sliding Window
    vector<int> arr = {1, 2, 3, 4, 5, 6, 77};
    int k = 23;

    cout << "Minimum Subarray Length: ";
    cout << minSubarray(arr, k) << endl;


    // Linked List
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original Linked List: ";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List: ";
    printList(head);
    cout << endl;


    // Binary Tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
```
