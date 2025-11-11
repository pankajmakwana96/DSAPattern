/**
 * Linked List Cycle II - Floyd's Algorithm (Find Cycle Entry)
 * LeetCode: https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListCycleII {
public:
    // Approach 1: Floyd's Algorithm (Optimal - O(1) space)
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Detect if cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected, proceed to Phase 2
                break;
            }
        }

        // No cycle found
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // Phase 2: Find cycle entry point
        slow = head;  // Reset slow to head
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;  // or fast, they're equal (cycle entry)
    }

    // Approach 2: Hash Set (Alternative - O(n) space)
    ListNode *detectCycle2(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode *current = head;
        while (current != NULL) {
            if (visited.count(current)) {
                return current;  // First revisited node is cycle entry
            }
            visited.insert(current);
            current = current->next;
        }

        return NULL;  // No cycle
    }
};

// Helper function to create a cycle for testing
ListNode* createCycleList(int values[], int size, int pos) {
    if (size == 0) {
        return NULL;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    ListNode* cycleNode = NULL;

    if (pos == 0) {
        cycleNode = head;
    }

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(values[i]);
        current = current->next;

        if (i == pos) {
            cycleNode = current;
        }
    }

    // Create cycle if pos is valid
    if (pos >= 0 && cycleNode != NULL) {
        current->next = cycleNode;
    }

    return head;
}

// Test cases
int main() {
    LinkedListCycleII solution;

    // Test case 1: Cycle at position 1
    int arr1[] = {3, 2, 0, -4};
    ListNode* test1 = createCycleList(arr1, 4, 1);
    ListNode* result1 = solution.detectCycle(test1);
    cout << "Test 1: Cycle entry value = " << (result1 != NULL ? to_string(result1->val) : "null") << endl; // 2

    // Test case 2: Cycle at position 0 (entire list)
    int arr2[] = {1, 2};
    ListNode* test2 = createCycleList(arr2, 2, 0);
    ListNode* result2 = solution.detectCycle(test2);
    cout << "Test 2: Cycle entry value = " << (result2 != NULL ? to_string(result2->val) : "null") << endl; // 1

    // Test case 3: No cycle
    int arr3[] = {1, 2, 3, 4};
    ListNode* test3 = createCycleList(arr3, 4, -1);
    ListNode* result3 = solution.detectCycle(test3);
    cout << "Test 3: Cycle entry value = " << (result3 != NULL ? to_string(result3->val) : "null") << endl; // null

    // Test case 4: Single node, no cycle
    ListNode* test4 = new ListNode(1);
    ListNode* result4 = solution.detectCycle(test4);
    cout << "Test 4: Cycle entry value = " << (result4 != NULL ? to_string(result4->val) : "null") << endl; // null
    delete test4;

    // Test case 5: Single node, self cycle
    ListNode* test5 = new ListNode(1);
    test5->next = test5;
    ListNode* result5 = solution.detectCycle(test5);
    cout << "Test 5: Cycle entry value = " << (result5 != NULL ? to_string(result5->val) : "null") << endl; // 1

    // Note: Memory cleanup omitted for brevity (would cause issues with cycles)

    return 0;
}
