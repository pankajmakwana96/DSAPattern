/**
 * Remove Nth Node From End of List - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class RemoveNthNodeFromEnd {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    // Approach 1: One Pass with Two Pointers (Optimal)
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Create dummy node to handle edge cases
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode fast = dummy;
        ListNode slow = dummy;

        // Move fast pointer n+1 steps ahead
        // +1 because we want slow to stop at the node BEFORE the one to delete
        for (int i = 0; i <= n; i++) {
            fast = fast.next;
        }

        // Move both pointers until fast reaches the end
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        // Remove the nth node from end
        slow.next = slow.next.next;

        return dummy.next;
    }

    // Approach 2: Two Pass (Alternative)
    public ListNode removeNthFromEnd2(ListNode head, int n) {
        // First pass: count the length
        int length = 0;
        ListNode current = head;
        while (current != null) {
            length++;
            current = current.next;
        }

        // Edge case: removing the head
        if (length == n) {
            return head.next;
        }

        // Second pass: find the node before the one to remove
        int stepsToMove = length - n - 1;
        current = head;
        for (int i = 0; i < stepsToMove; i++) {
            current = current.next;
        }

        // Remove the node
        current.next = current.next.next;

        return head;
    }

    // Helper method to create a linked list from an array
    public static ListNode createList(int[] values) {
        if (values == null || values.length == 0) {
            return null;
        }

        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        for (int val : values) {
            current.next = new ListNode(val);
            current = current.next;
        }

        return dummy.next;
    }

    // Helper method to print the linked list
    public static void printList(ListNode head) {
        if (head == null) {
            System.out.println("[]");
            return;
        }

        System.out.print("[");
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val);
            if (current.next != null) {
                System.out.print(",");
            }
            current = current.next;
        }
        System.out.println("]");
    }

    // Test cases
    public static void main(String[] args) {
        RemoveNthNodeFromEnd solution = new RemoveNthNodeFromEnd();

        // Test case 1: [1,2,3,4,5], n = 2
        ListNode test1 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Test 1: ");
        printList(solution.removeNthFromEnd(test1, 2)); // Expected: [1,2,3,5]

        // Test case 2: [1], n = 1
        ListNode test2 = createList(new int[]{1});
        System.out.print("Test 2: ");
        printList(solution.removeNthFromEnd(test2, 1)); // Expected: []

        // Test case 3: [1,2], n = 1
        ListNode test3 = createList(new int[]{1, 2});
        System.out.print("Test 3: ");
        printList(solution.removeNthFromEnd(test3, 1)); // Expected: [1]

        // Test case 4: [1,2], n = 2
        ListNode test4 = createList(new int[]{1, 2});
        System.out.print("Test 4: ");
        printList(solution.removeNthFromEnd(test4, 2)); // Expected: [2]

        // Test case 5: [1,2,3,4,5], n = 5
        ListNode test5 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Test 5: ");
        printList(solution.removeNthFromEnd(test5, 5)); // Expected: [2,3,4,5]
    }
}
