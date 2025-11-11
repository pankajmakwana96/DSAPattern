/**
 * Sliding Window Maximum
 * LeetCode: https://leetcode.com/problems/sliding-window-maximum/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(k)
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Arrays;

class SlidingWindowMaximum {

    // Optimal Approach: Monotonic Decreasing Deque
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return new int[0];
        }

        int n = nums.length;
        int[] result = new int[n - k + 1];
        Deque<Integer> deque = new ArrayDeque<>();  // stores indices

        for (int i = 0; i < n; i++) {
            // Remove indices outside current window
            while (!deque.isEmpty() && deque.peekFirst() < i - k + 1) {
                deque.pollFirst();
            }

            // Remove indices with smaller values from back
            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) {
                deque.pollLast();
            }

            // Add current index
            deque.offerLast(i);

            // Add max to result (window is complete)
            if (i >= k - 1) {
                result[i - k + 1] = nums[deque.peekFirst()];
            }
        }

        return result;
    }

    // Test cases
    public static void main(String[] args) {
        SlidingWindowMaximum solution = new SlidingWindowMaximum();

        // Test case 1: Normal case
        int[] test1 = {1, 3, -1, -3, 5, 3, 6, 7};
        System.out.println("Test 1: " + Arrays.toString(solution.maxSlidingWindow(test1, 3)));
        // Expected: [3, 3, 5, 5, 6, 7]

        // Test case 2: Single element
        int[] test2 = {1};
        System.out.println("Test 2: " + Arrays.toString(solution.maxSlidingWindow(test2, 1)));
        // Expected: [1]

        // Test case 3: K equals array length
        int[] test3 = {1, 3, 1, 2, 0, 5};
        System.out.println("Test 3: " + Arrays.toString(solution.maxSlidingWindow(test3, 6)));
        // Expected: [5]

        // Test case 4: Decreasing array
        int[] test4 = {9, 8, 7, 6, 5, 4};
        System.out.println("Test 4: " + Arrays.toString(solution.maxSlidingWindow(test4, 3)));
        // Expected: [9, 8, 7, 6]

        // Test case 5: Increasing array
        int[] test5 = {1, 2, 3, 4, 5, 6};
        System.out.println("Test 5: " + Arrays.toString(solution.maxSlidingWindow(test5, 3)));
        // Expected: [3, 4, 5, 6]

        // Test case 6: All same
        int[] test6 = {5, 5, 5, 5, 5};
        System.out.println("Test 6: " + Arrays.toString(solution.maxSlidingWindow(test6, 2)));
        // Expected: [5, 5, 5, 5]
    }
}
