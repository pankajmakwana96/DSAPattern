/**
 * Linked List Cycle II - Floyd's Algorithm (Find Cycle Entry)
 * LeetCode: https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

import java.util.HashSet;
import java.util.Set;

class LinkedListCycleII {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    // Approach 1: Floyd's Algorithm (Optimal - O(1) space)
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;

        // Phase 1: Detect if cycle exists
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                // Cycle detected, proceed to Phase 2
                break;
            }
        }

        // No cycle found
        if (fast == null || fast.next == null) {
            return null;
        }

        // Phase 2: Find cycle entry point
        slow = head;  // Reset slow to head
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }

        return slow;  // or fast, they're equal (cycle entry)
    }

    // Approach 2: Hash Set (Alternative - O(n) space)
    public ListNode detectCycle2(ListNode head) {
        Set<ListNode> visited = new HashSet<>();

        ListNode current = head;
        while (current != null) {
            if (visited.contains(current)) {
                return current;  // First revisited node is cycle entry
            }
            visited.add(current);
            current = current.next;
        }

        return null;  // No cycle
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
        LinkedListCycleII solution = new LinkedListCycleII();

        // Test case 1: Cycle at position 1
        ListNode test1 = createCycleList(new int[]{3, 2, 0, -4}, 1);
        ListNode result1 = solution.detectCycle(test1);
        System.out.println("Test 1: Cycle entry value = " + (result1 != null ? result1.val : "null")); // 2

        // Test case 2: Cycle at position 0 (entire list)
        ListNode test2 = createCycleList(new int[]{1, 2}, 0);
        ListNode result2 = solution.detectCycle(test2);
        System.out.println("Test 2: Cycle entry value = " + (result2 != null ? result2.val : "null")); // 1

        // Test case 3: No cycle
        ListNode test3 = createCycleList(new int[]{1, 2, 3, 4}, -1);
        ListNode result3 = solution.detectCycle(test3);
        System.out.println("Test 3: Cycle entry value = " + (result3 != null ? result3.val : "null")); // null

        // Test case 4: Single node, no cycle
        ListNode test4 = new ListNode(1);
        ListNode result4 = solution.detectCycle(test4);
        System.out.println("Test 4: Cycle entry value = " + (result4 != null ? result4.val : "null")); // null

        // Test case 5: Single node, self cycle
        ListNode test5 = new ListNode(1);
        test5.next = test5;
        ListNode result5 = solution.detectCycle(test5);
        System.out.println("Test 5: Cycle entry value = " + (result5 != null ? result5.val : "null")); // 1
    }
}
