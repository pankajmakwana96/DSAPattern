/**
 * Maximum Twin Sum of a Linked List - Fast-Slow + Reverse
 * LeetCode: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class MaximumTwinSum {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public int pairSum(ListNode head) {
        // Step 1: Find middle using fast-slow pointers
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Step 2: Reverse second half
        ListNode secondHalf = reverseList(slow);

        // Step 3: Calculate maximum twin sum
        int maxSum = 0;
        ListNode first = head;
        ListNode second = secondHalf;

        while (second != null) {
            int twinSum = first.val + second.val;
            maxSum = Math.max(maxSum, twinSum);
            first = first.next;
            second = second.next;
        }

        return maxSum;
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
        MaximumTwinSum solution = new MaximumTwinSum();

        // Test case 1
        ListNode test1 = createList(new int[]{5, 4, 2, 1});
        System.out.println("Test 1 [5,4,2,1]: " + solution.pairSum(test1)); // 6

        // Test case 2
        ListNode test2 = createList(new int[]{4, 2, 2, 3});
        System.out.println("Test 2 [4,2,2,3]: " + solution.pairSum(test2)); // 7

        // Test case 3
        ListNode test3 = createList(new int[]{1, 100000});
        System.out.println("Test 3 [1,100000]: " + solution.pairSum(test3)); // 100001

        // Test case 4: All same
        ListNode test4 = createList(new int[]{5, 5, 5, 5});
        System.out.println("Test 4 [5,5,5,5]: " + solution.pairSum(test4)); // 10

        // Test case 5: Increasing
        ListNode test5 = createList(new int[]{1, 2, 3, 4});
        System.out.println("Test 5 [1,2,3,4]: " + solution.pairSum(test5)); // 5

        // Test case 6: Large list
        ListNode test6 = createList(new int[]{10, 20, 30, 40, 50, 60});
        System.out.println("Test 6 [10,20,30,40,50,60]: " + solution.pairSum(test6)); // 70
    }
}
