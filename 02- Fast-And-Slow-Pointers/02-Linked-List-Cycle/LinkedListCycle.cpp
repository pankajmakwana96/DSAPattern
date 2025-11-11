/**
 * Linked List Cycle - Fast and Slow Pointers (Floyd's Algorithm)
 * LeetCode: https://leetcode.com/problems/linked-list-cycle/
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

class LinkedListCycle {
public:
    // Approach 1: Fast and Slow Pointers (Optimal)
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move one step
            fast = fast->next->next;    // Move two steps

            if (slow == fast) {
                return true;            // Cycle detected
            }
        }

        return false;                    // No cycle
    }

    // Approach 2: HashSet (Alternative)
    bool hasCycle2(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode *current = head;
        while (current != NULL) {
            if (visited.count(current)) {
                return true;            // Found a cycle
            }
            visited.insert(current);
            current = current->next;
        }

        return false;                    // No cycle
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
    LinkedListCycle solution;

    // Test case 1: Cycle at position 1
    int arr1[] = {3, 2, 0, -4};
    ListNode* test1 = createCycleList(arr1, 4, 1);
    cout << "Test 1 (cycle at pos 1): " << (solution.hasCycle(test1) ? "true" : "false") << endl; // true

    // Test case 2: Cycle at position 0
    int arr2[] = {1, 2};
    ListNode* test2 = createCycleList(arr2, 2, 0);
    cout << "Test 2 (cycle at pos 0): " << (solution.hasCycle(test2) ? "true" : "false") << endl; // true

    // Test case 3: No cycle
    int arr3[] = {1, 2, 3, 4};
    ListNode* test3 = createCycleList(arr3, 4, -1);
    cout << "Test 3 (no cycle): " << (solution.hasCycle(test3) ? "true" : "false") << endl; // false

    // Test case 4: Single node no cycle
    ListNode* test4 = new ListNode(1);
    cout << "Test 4 (single node): " << (solution.hasCycle(test4) ? "true" : "false") << endl; // false

    // Test case 5: Single node with cycle
    ListNode* test5 = new ListNode(1);
    test5->next = test5;
    cout << "Test 5 (single node cycle): " << (solution.hasCycle(test5) ? "true" : "false") << endl; // true

    // Test case 6: Empty list
    cout << "Test 6 (empty): " << (solution.hasCycle(NULL) ? "true" : "false") << endl; // false

    // Note: Memory cleanup omitted for brevity (would cause issues with cycles)

    return 0;
}
