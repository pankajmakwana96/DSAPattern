/**
 * Reorder List - Three Phase Approach
 * LeetCode: https://leetcode.com/problems/reorder-list/
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
    ListNode(int x) : val(x), next(NULL) {}
};

class ReorderList {
public:
    // Optimal Approach: Find Middle + Reverse + Merge
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }

        // Phase 1: Find middle using fast-slow pointers
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Phase 2: Reverse second half
        ListNode *secondHalf = slow->next;
        slow->next = NULL;  // Split the list
        ListNode *reversedSecondHalf = reverseList(secondHalf);

        // Phase 3: Merge alternately
        mergeLists(head, reversedSecondHalf);
    }

    // Helper: Reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    // Helper: Merge two lists alternately
    void mergeLists(ListNode* first, ListNode* second) {
        while (second != NULL) {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }

    // Alternative Approach: Using Vector (O(n) space)
    void reorderList2(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }

        // Store all nodes in a vector for random access
        vector<ListNode*> nodes;
        ListNode *curr = head;
        while (curr != NULL) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int left = 0;
        int right = nodes.size() - 1;

        while (left < right) {
            nodes[left]->next = nodes[right];
            left++;

            if (left >= right) {
                break;
            }

            nodes[right]->next = nodes[left];
            right--;
        }

        nodes[left]->next = NULL;
    }
};

// Helper function to create a linked list from array
ListNode* createList(int values[], int size) {
    if (size == 0) {
        return NULL;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Helper function to delete list (free memory)
void deleteList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test cases
int main() {
    ReorderList solution;

    // Test case 1: Even length [1,2,3,4] -> [1,4,2,3]
    cout << "Test 1: Even length list" << endl;
    int arr1[] = {1, 2, 3, 4};
    ListNode* test1 = createList(arr1, 4);
    cout << "Before: ";
    printList(test1);
    solution.reorderList(test1);
    cout << "After:  ";
    printList(test1);
    cout << "Expected: 1 -> 4 -> 2 -> 3\n" << endl;
    deleteList(test1);

    // Test case 2: Odd length [1,2,3,4,5] -> [1,5,2,4,3]
    cout << "Test 2: Odd length list" << endl;
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode* test2 = createList(arr2, 5);
    cout << "Before: ";
    printList(test2);
    solution.reorderList(test2);
    cout << "After:  ";
    printList(test2);
    cout << "Expected: 1 -> 5 -> 2 -> 4 -> 3\n" << endl;
    deleteList(test2);

    // Test case 3: Two nodes [1,2] -> [1,2]
    cout << "Test 3: Two nodes" << endl;
    int arr3[] = {1, 2};
    ListNode* test3 = createList(arr3, 2);
    cout << "Before: ";
    printList(test3);
    solution.reorderList(test3);
    cout << "After:  ";
    printList(test3);
    cout << "Expected: 1 -> 2\n" << endl;
    deleteList(test3);

    // Test case 4: Three nodes [1,2,3] -> [1,3,2]
    cout << "Test 4: Three nodes" << endl;
    int arr4[] = {1, 2, 3};
    ListNode* test4 = createList(arr4, 3);
    cout << "Before: ";
    printList(test4);
    solution.reorderList(test4);
    cout << "After:  ";
    printList(test4);
    cout << "Expected: 1 -> 3 -> 2\n" << endl;
    deleteList(test4);

    // Test case 5: Single node [1] -> [1]
    cout << "Test 5: Single node" << endl;
    int arr5[] = {1};
    ListNode* test5 = createList(arr5, 1);
    cout << "Before: ";
    printList(test5);
    solution.reorderList(test5);
    cout << "After:  ";
    printList(test5);
    cout << "Expected: 1\n" << endl;
    deleteList(test5);

    // Test case 6: Longer list [1,2,3,4,5,6] -> [1,6,2,5,3,4]
    cout << "Test 6: Longer list" << endl;
    int arr6[] = {1, 2, 3, 4, 5, 6};
    ListNode* test6 = createList(arr6, 6);
    cout << "Before: ";
    printList(test6);
    solution.reorderList(test6);
    cout << "After:  ";
    printList(test6);
    cout << "Expected: 1 -> 6 -> 2 -> 5 -> 3 -> 4" << endl;
    deleteList(test6);

    return 0;
}
