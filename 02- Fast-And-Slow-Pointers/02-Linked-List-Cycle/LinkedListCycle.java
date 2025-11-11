/**
 * Linked List Cycle - Fast and Slow Pointers (Floyd's Algorithm)
 * LeetCode: https://leetcode.com/problems/linked-list-cycle/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

import java.util.HashSet;
import java.util.Set;

class LinkedListCycle {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    // Approach 1: Fast and Slow Pointers (Optimal)
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;           // Move one step
            fast = fast.next.next;      // Move two steps

            if (slow == fast) {
                return true;            // Cycle detected
            }
        }

        return false;                    // No cycle
    }

    // Approach 2: HashSet (Alternative)
    public boolean hasCycle2(ListNode head) {
        Set<ListNode> visited = new HashSet<>();

        ListNode current = head;
        while (current != null) {
            if (visited.contains(current)) {
                return true;            // Found a cycle
            }
            visited.add(current);
            current = current.next;
        }

        return false;                    // No cycle
    }

    // Helper method to create a cycle for testing
    public static ListNode createCycleList(int[] values, int pos) {
        if (values == null || values.length == 0) {
            return null;
        }

        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        ListNode cycleNode = null;

        for (int i = 0; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;

            if (i == pos) {
                cycleNode = current;
            }
        }

        // Create cycle if pos is valid
        if (pos >= 0 && cycleNode != null) {
            current.next = cycleNode;
        }

        return dummy.next;
    }

    // Test cases
    public static void main(String[] args) {
        LinkedListCycle solution = new LinkedListCycle();

        // Test case 1: Cycle at position 1
        ListNode test1 = createCycleList(new int[]{3, 2, 0, -4}, 1);
        System.out.println("Test 1 (cycle at pos 1): " + solution.hasCycle(test1)); // true

        // Test case 2: Cycle at position 0
        ListNode test2 = createCycleList(new int[]{1, 2}, 0);
        System.out.println("Test 2 (cycle at pos 0): " + solution.hasCycle(test2)); // true

        // Test case 3: No cycle
        ListNode test3 = createCycleList(new int[]{1, 2, 3, 4}, -1);
        System.out.println("Test 3 (no cycle): " + solution.hasCycle(test3)); // false

        // Test case 4: Single node no cycle
        ListNode test4 = new ListNode(1);
        System.out.println("Test 4 (single node): " + solution.hasCycle(test4)); // false

        // Test case 5: Single node with cycle
        ListNode test5 = new ListNode(1);
        test5.next = test5;
        System.out.println("Test 5 (single node cycle): " + solution.hasCycle(test5)); // true

        // Test case 6: Empty list
        System.out.println("Test 6 (empty): " + solution.hasCycle(null)); // false
    }
}
