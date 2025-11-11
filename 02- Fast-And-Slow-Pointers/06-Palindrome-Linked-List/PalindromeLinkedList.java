/**
 * Palindrome Linked List - Fast-Slow Pointers + Reverse
 * LeetCode: https://leetcode.com/problems/palindrome-linked-list/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

import java.util.ArrayList;
import java.util.List;

class PalindromeLinkedList {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    // Approach 1: Fast-Slow + Reverse (Optimal O(1) space)
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }

        // Step 1: Find middle using fast-slow pointers
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Step 2: Reverse second half
        ListNode secondHalf = reverseList(slow);

        // Step 3: Compare first half and reversed second half
        ListNode p1 = head;
        ListNode p2 = secondHalf;

        while (p2 != null) {  // p2 is shorter or equal length
            if (p1.val != p2.val) {
                return false;
            }
            p1 = p1.next;
            p2 = p2.next;
        }

        // Optional Step 4: Restore list (uncomment if needed)
        // reverseList(secondHalf);

        return true;
    }

    // Helper method: Reverse linked list
    private ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;

        while (current != null) {
            ListNode nextTemp = current.next;
            current.next = prev;
            prev = current;
            current = nextTemp;
        }

        return prev;
    }

    // Approach 2: Copy to ArrayList (O(n) space)
    public boolean isPalindrome2(ListNode head) {
        List<Integer> values = new ArrayList<>();

        // Copy to array
        ListNode current = head;
        while (current != null) {
            values.add(current.val);
            current = current.next;
        }

        // Check palindrome with two pointers
        int left = 0;
        int right = values.size() - 1;

        while (left < right) {
            if (!values.get(left).equals(values.get(right))) {
                return false;
            }
            left++;
            right--;
        }

        return true;
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

    // Test cases
    public static void main(String[] args) {
        PalindromeLinkedList solution = new PalindromeLinkedList();

        // Test case 1: Palindrome (even length)
        ListNode test1 = createList(new int[]{1, 2, 2, 1});
        System.out.println("Test 1 [1,2,2,1]: " + solution.isPalindrome(test1)); // true

        // Test case 2: Not palindrome
        ListNode test2 = createList(new int[]{1, 2});
        System.out.println("Test 2 [1,2]: " + solution.isPalindrome(test2)); // false

        // Test case 3: Single node
        ListNode test3 = createList(new int[]{1});
        System.out.println("Test 3 [1]: " + solution.isPalindrome(test3)); // true

        // Test case 4: Palindrome (odd length)
        ListNode test4 = createList(new int[]{1, 2, 3, 2, 1});
        System.out.println("Test 4 [1,2,3,2,1]: " + solution.isPalindrome(test4)); // true

        // Test case 5: All same
        ListNode test5 = createList(new int[]{1, 1, 1, 1});
        System.out.println("Test 5 [1,1,1,1]: " + solution.isPalindrome(test5)); // true

        // Test case 6: Not palindrome (odd length)
        ListNode test6 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.println("Test 6 [1,2,3,4,5]: " + solution.isPalindrome(test6)); // false
    }
}
