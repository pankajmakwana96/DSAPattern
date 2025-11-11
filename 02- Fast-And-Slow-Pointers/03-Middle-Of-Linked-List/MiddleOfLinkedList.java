/**
 * Middle of the Linked List - Fast and Slow Pointers
 * LeetCode: https://leetcode.com/problems/middle-of-the-linked-list/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class MiddleOfLinkedList {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    // Approach 1: Fast and Slow Pointers (Optimal)
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;           // Move one step
            fast = fast.next.next;      // Move two steps
        }

        return slow;  // When fast reaches end, slow is at middle
    }

    // Approach 2: Two Pass (Alternative)
    public ListNode middleNode2(ListNode head) {
        // First pass: count nodes
        int count = 0;
        ListNode current = head;
        while (current != null) {
            count++;
            current = current.next;
        }

        // Second pass: move to middle
        int middle = count / 2;
        current = head;
        for (int i = 0; i < middle; i++) {
            current = current.next;
        }

        return current;
    }

    // Helper method to create linked list from array
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

    // Helper method to print linked list
    public static void printList(ListNode head) {
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
        MiddleOfLinkedList solution = new MiddleOfLinkedList();

        // Test case 1: Odd length list
        ListNode test1 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Test 1 [1,2,3,4,5]: ");
        printList(solution.middleNode(test1)); // [3,4,5]

        // Test case 2: Even length list (return second middle)
        ListNode test2 = createList(new int[]{1, 2, 3, 4, 5, 6});
        System.out.print("Test 2 [1,2,3,4,5,6]: ");
        printList(solution.middleNode(test2)); // [4,5,6]

        // Test case 3: Single node
        ListNode test3 = createList(new int[]{1});
        System.out.print("Test 3 [1]: ");
        printList(solution.middleNode(test3)); // [1]

        // Test case 4: Two nodes
        ListNode test4 = createList(new int[]{1, 2});
        System.out.print("Test 4 [1,2]: ");
        printList(solution.middleNode(test4)); // [2]

        // Test case 5: Three nodes
        ListNode test5 = createList(new int[]{1, 2, 3});
        System.out.print("Test 5 [1,2,3]: ");
        printList(solution.middleNode(test5)); // [2,3]
    }
}
