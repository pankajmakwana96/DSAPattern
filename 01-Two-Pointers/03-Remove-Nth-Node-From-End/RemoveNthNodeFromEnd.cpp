/**
 * Remove Nth Node From End of List - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class RemoveNthNodeFromEnd {
public:
    // Approach 1: One Pass with Two Pointers (Optimal)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        // +1 because we want slow to stop at the node BEFORE the one to delete
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete; // Free memory

        ListNode* result = dummy->next;
        delete dummy; // Free dummy node
        return result;
    }

    // Approach 2: Two Pass (Alternative)
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        // First pass: count the length
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        // Edge case: removing the head
        if (length == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Second pass: find the node before the one to remove
        int stepsToMove = length - n - 1;
        current = head;
        for (int i = 0; i < stepsToMove; i++) {
            current = current->next;
        }

        // Remove the node
        ListNode* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;

        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }

    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "[]" << endl;
        return;
    }

    cout << "[";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << ",";
        }
        current = current->next;
    }
    cout << "]" << endl;
}

// Helper function to delete the entire list
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test cases
int main() {
    RemoveNthNodeFromEnd solution;

    // Test case 1: [1,2,3,4,5], n = 2
    ListNode* test1 = createList({1, 2, 3, 4, 5});
    cout << "Test 1: ";
    ListNode* result1 = solution.removeNthFromEnd(test1, 2);
    printList(result1); // Expected: [1,2,3,5]
    deleteList(result1);

    // Test case 2: [1], n = 1
    ListNode* test2 = createList({1});
    cout << "Test 2: ";
    ListNode* result2 = solution.removeNthFromEnd(test2, 1);
    printList(result2); // Expected: []
    deleteList(result2);

    // Test case 3: [1,2], n = 1
    ListNode* test3 = createList({1, 2});
    cout << "Test 3: ";
    ListNode* result3 = solution.removeNthFromEnd(test3, 1);
    printList(result3); // Expected: [1]
    deleteList(result3);

    // Test case 4: [1,2], n = 2
    ListNode* test4 = createList({1, 2});
    cout << "Test 4: ";
    ListNode* result4 = solution.removeNthFromEnd(test4, 2);
    printList(result4); // Expected: [2]
    deleteList(result4);

    // Test case 5: [1,2,3,4,5], n = 5
    ListNode* test5 = createList({1, 2, 3, 4, 5});
    cout << "Test 5: ";
    ListNode* result5 = solution.removeNthFromEnd(test5, 5);
    printList(result5); // Expected: [2,3,4,5]
    deleteList(result5);

    return 0;
}
