/**
 * Reorder List - Three Phase Approach
 * LeetCode: https://leetcode.com/problems/reorder-list/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

import java.util.ArrayList;
import java.util.List;

class ReorderList {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    // Optimal Approach: Find Middle + Reverse + Merge
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }

        // Phase 1: Find middle using fast-slow pointers
        ListNode slow = head;
        ListNode fast = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Phase 2: Reverse second half
        ListNode secondHalf = slow.next;
        slow.next = null;  // Split the list
        ListNode reversedSecondHalf = reverseList(secondHalf);

        // Phase 3: Merge alternately
        mergeLists(head, reversedSecondHalf);
    }

    // Helper: Reverse a linked list
    private ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    // Helper: Merge two lists alternately
    private void mergeLists(ListNode first, ListNode second) {
        while (second != null) {
            ListNode tmp1 = first.next;
            ListNode tmp2 = second.next;

            first.next = second;
            second.next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }

    // Alternative Approach: Using Stack (O(n) space)
    public void reorderList2(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }

        // Store all nodes in a list for random access
        List<ListNode> nodes = new ArrayList<>();
        ListNode curr = head;
        while (curr != null) {
            nodes.add(curr);
            curr = curr.next;
        }

        int left = 0;
        int right = nodes.size() - 1;

        while (left < right) {
            nodes.get(left).next = nodes.get(right);
            left++;

            if (left >= right) {
                break;
            }

            nodes.get(right).next = nodes.get(left);
            right--;
        }

        nodes.get(left).next = null;
    }

    // Helper method to create a linked list from array
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

    // Helper method to convert list to array for testing
    public static int[] listToArray(ListNode head) {
        List<Integer> result = new ArrayList<>();
        ListNode current = head;

        while (current != null) {
            result.add(current.val);
            current = current.next;
        }

        return result.stream().mapToInt(i -> i).toArray();
    }

    // Helper method to print list
    public static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val);
            if (current.next != null) {
                System.out.print(" -> ");
            }
            current = current.next;
        }
        System.out.println();
    }

    // Test cases
    public static void main(String[] args) {
        ReorderList solution = new ReorderList();

        // Test case 1: Even length [1,2,3,4] -> [1,4,2,3]
        System.out.println("Test 1: Even length list");
        ListNode test1 = createList(new int[]{1, 2, 3, 4});
        System.out.print("Before: ");
        printList(test1);
        solution.reorderList(test1);
        System.out.print("After:  ");
        printList(test1);
        System.out.println("Expected: 1 -> 4 -> 2 -> 3\n");

        // Test case 2: Odd length [1,2,3,4,5] -> [1,5,2,4,3]
        System.out.println("Test 2: Odd length list");
        ListNode test2 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Before: ");
        printList(test2);
        solution.reorderList(test2);
        System.out.print("After:  ");
        printList(test2);
        System.out.println("Expected: 1 -> 5 -> 2 -> 4 -> 3\n");

        // Test case 3: Two nodes [1,2] -> [1,2]
        System.out.println("Test 3: Two nodes");
        ListNode test3 = createList(new int[]{1, 2});
        System.out.print("Before: ");
        printList(test3);
        solution.reorderList(test3);
        System.out.print("After:  ");
        printList(test3);
        System.out.println("Expected: 1 -> 2\n");

        // Test case 4: Three nodes [1,2,3] -> [1,3,2]
        System.out.println("Test 4: Three nodes");
        ListNode test4 = createList(new int[]{1, 2, 3});
        System.out.print("Before: ");
        printList(test4);
        solution.reorderList(test4);
        System.out.print("After:  ");
        printList(test4);
        System.out.println("Expected: 1 -> 3 -> 2\n");

        // Test case 5: Single node [1] -> [1]
        System.out.println("Test 5: Single node");
        ListNode test5 = createList(new int[]{1});
        System.out.print("Before: ");
        printList(test5);
        solution.reorderList(test5);
        System.out.print("After:  ");
        printList(test5);
        System.out.println("Expected: 1\n");

        // Test case 6: Longer list [1,2,3,4,5,6] -> [1,6,2,5,3,4]
        System.out.println("Test 6: Longer list");
        ListNode test6 = createList(new int[]{1, 2, 3, 4, 5, 6});
        System.out.print("Before: ");
        printList(test6);
        solution.reorderList(test6);
        System.out.print("After:  ");
        printList(test6);
        System.out.println("Expected: 1 -> 6 -> 2 -> 5 -> 3 -> 4");
    }
}
