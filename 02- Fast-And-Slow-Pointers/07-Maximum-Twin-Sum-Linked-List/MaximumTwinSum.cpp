/**
 * Maximum Twin Sum of a Linked List - Fast-Slow + Reverse
 * LeetCode: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MaximumTwinSum {
public:
    int pairSum(ListNode* head) {
        // Step 1: Find middle using fast-slow pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow);

        // Step 3: Calculate maximum twin sum
        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = secondHalf;

        while (second != nullptr) {
            int twinSum = first->val + second->val;
            maxSum = max(maxSum, twinSum);
            first = first->next;
            second = second->next;
        }

        return maxSum;
    }

private:
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
    MaximumTwinSum solution;

    // Test case 1
    ListNode* test1 = createList({5, 4, 2, 1});
    cout << "Test 1 [5,4,2,1]: " << solution.pairSum(test1) << endl; // 6
    deleteList(test1);

    // Test case 2
    ListNode* test2 = createList({4, 2, 2, 3});
    cout << "Test 2 [4,2,2,3]: " << solution.pairSum(test2) << endl; // 7
    deleteList(test2);

    // Test case 3
    ListNode* test3 = createList({1, 100000});
    cout << "Test 3 [1,100000]: " << solution.pairSum(test3) << endl; // 100001
    deleteList(test3);

    // Test case 4: All same
    ListNode* test4 = createList({5, 5, 5, 5});
    cout << "Test 4 [5,5,5,5]: " << solution.pairSum(test4) << endl; // 10
    deleteList(test4);

    // Test case 5: Increasing
    ListNode* test5 = createList({1, 2, 3, 4});
    cout << "Test 5 [1,2,3,4]: " << solution.pairSum(test5) << endl; // 5
    deleteList(test5);

    // Test case 6: Large list
    ListNode* test6 = createList({10, 20, 30, 40, 50, 60});
    cout << "Test 6 [10,20,30,40,50,60]: " << solution.pairSum(test6) << endl; // 70
    deleteList(test6);

    return 0;
}
