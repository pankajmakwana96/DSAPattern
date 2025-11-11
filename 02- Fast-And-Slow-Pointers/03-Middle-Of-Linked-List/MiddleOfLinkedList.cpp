/**
 * Middle of the Linked List - Fast and Slow Pointers
 * LeetCode: https://leetcode.com/problems/middle-of-the-linked-list/
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

class MiddleOfLinkedList {
public:
    // Approach 1: Fast and Slow Pointers (Optimal)
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move one step
            fast = fast->next->next;    // Move two steps
        }

        return slow;  // When fast reaches end, slow is at middle
    }

    // Approach 2: Two Pass (Alternative)
    ListNode* middleNode2(ListNode* head) {
        // First pass: count nodes
        int count = 0;
        ListNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }

        // Second pass: move to middle
        int middle = count / 2;
        current = head;
        for (int i = 0; i < middle; i++) {
            current = current->next;
        }

        return current;
    }
};

// Helper function to create linked list from vector
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

// Helper function to print linked list
void printList(ListNode* head) {
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

// Helper function to delete list
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test cases
int main() {
    MiddleOfLinkedList solution;

    // Test case 1: Odd length list
    ListNode* test1 = createList({1, 2, 3, 4, 5});
    cout << "Test 1 [1,2,3,4,5]: ";
    ListNode* result1 = solution.middleNode(test1);
    printList(result1); // [3,4,5]
    deleteList(test1);

    // Test case 2: Even length list (return second middle)
    ListNode* test2 = createList({1, 2, 3, 4, 5, 6});
    cout << "Test 2 [1,2,3,4,5,6]: ";
    ListNode* result2 = solution.middleNode(test2);
    printList(result2); // [4,5,6]
    deleteList(test2);

    // Test case 3: Single node
    ListNode* test3 = createList({1});
    cout << "Test 3 [1]: ";
    ListNode* result3 = solution.middleNode(test3);
    printList(result3); // [1]
    deleteList(test3);

    // Test case 4: Two nodes
    ListNode* test4 = createList({1, 2});
    cout << "Test 4 [1,2]: ";
    ListNode* result4 = solution.middleNode(test4);
    printList(result4); // [2]
    deleteList(test4);

    // Test case 5: Three nodes
    ListNode* test5 = createList({1, 2, 3});
    cout << "Test 5 [1,2,3]: ";
    ListNode* result5 = solution.middleNode(test5);
    printList(result5); // [2,3]
    deleteList(test5);

    return 0;
}
