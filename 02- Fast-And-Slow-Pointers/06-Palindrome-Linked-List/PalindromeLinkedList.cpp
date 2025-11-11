/**
 * Palindrome Linked List - Fast-Slow Pointers + Reverse
 * LeetCode: https://leetcode.com/problems/palindrome-linked-list/
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

class PalindromeLinkedList {
public:
    // Approach 1: Fast-Slow + Reverse (Optimal O(1) space)
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Step 1: Find middle using fast-slow pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow);

        // Step 3: Compare first half and reversed second half
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;

        while (p2 != nullptr) {  // p2 is shorter or equal length
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Optional Step 4: Restore list (uncomment if needed)
        // reverseList(secondHalf);

        return true;
    }

    // Helper method: Reverse linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }

        return prev;
    }

    // Approach 2: Copy to Vector (O(n) space)
    bool isPalindrome2(ListNode* head) {
        vector<int> values;

        // Copy to vector
        ListNode* current = head;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }

        // Check palindrome with two pointers
        int left = 0;
        int right = values.size() - 1;

        while (left < right) {
            if (values[left] != values[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
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
    PalindromeLinkedList solution;

    // Test case 1: Palindrome (even length)
    ListNode* test1 = createList({1, 2, 2, 1});
    cout << "Test 1 [1,2,2,1]: " << (solution.isPalindrome(test1) ? "true" : "false") << endl; // true
    deleteList(test1);

    // Test case 2: Not palindrome
    ListNode* test2 = createList({1, 2});
    cout << "Test 2 [1,2]: " << (solution.isPalindrome(test2) ? "true" : "false") << endl; // false
    deleteList(test2);

    // Test case 3: Single node
    ListNode* test3 = createList({1});
    cout << "Test 3 [1]: " << (solution.isPalindrome(test3) ? "true" : "false") << endl; // true
    deleteList(test3);

    // Test case 4: Palindrome (odd length)
    ListNode* test4 = createList({1, 2, 3, 2, 1});
    cout << "Test 4 [1,2,3,2,1]: " << (solution.isPalindrome(test4) ? "true" : "false") << endl; // true
    deleteList(test4);

    // Test case 5: All same
    ListNode* test5 = createList({1, 1, 1, 1});
    cout << "Test 5 [1,1,1,1]: " << (solution.isPalindrome(test5) ? "true" : "false") << endl; // true
    deleteList(test5);

    // Test case 6: Not palindrome (odd length)
    ListNode* test6 = createList({1, 2, 3, 4, 5});
    cout << "Test 6 [1,2,3,4,5]: " << (solution.isPalindrome(test6) ? "true" : "false") << endl; // false
    deleteList(test6);

    return 0;
}
