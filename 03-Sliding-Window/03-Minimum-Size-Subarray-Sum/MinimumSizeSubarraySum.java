/**
 * Minimum Size Subarray Sum
 * LeetCode: https://leetcode.com/problems/minimum-size-subarray-sum/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class MinimumSizeSubarraySum {

    // Optimal Approach: Shrinking Sliding Window
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0, sum = 0, minLen = Integer.MAX_VALUE;

        for (int right = 0; right < nums.length; right++) {
            // Expand window
            sum += nums[right];

            // Shrink window while condition met
            while (sum >= target) {
                minLen = Math.min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }

    // Test cases
    public static void main(String[] args) {
        MinimumSizeSubarraySum solution = new MinimumSizeSubarraySum();

        // Test case 1: Normal case
        int[] test1 = {2, 3, 1, 2, 4, 3};
        System.out.println("Test 1: " + solution.minSubArrayLen(7, test1));
        // Expected: 2 ([4,3])

        // Test case 2: Single element sufficient
        int[] test2 = {1, 4, 4};
        System.out.println("Test 2: " + solution.minSubArrayLen(4, test2));
        // Expected: 1 ([4])

        // Test case 3: No valid subarray
        int[] test3 = {1, 1, 1, 1, 1, 1, 1, 1};
        System.out.println("Test 3: " + solution.minSubArrayLen(11, test3));
        // Expected: 0

        // Test case 4: Entire array needed
        int[] test4 = {1, 2, 3, 4, 5};
        System.out.println("Test 4: " + solution.minSubArrayLen(15, test4));
        // Expected: 5

        // Test case 5: First element works
        int[] test5 = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
        System.out.println("Test 5: " + solution.minSubArrayLen(15, test5));
        // Expected: 2

        // Test case 6: All elements same
        int[] test6 = {2, 2, 2, 2, 2};
        System.out.println("Test 6: " + solution.minSubArrayLen(6, test6));
        // Expected: 3

        // Test case 7: Target equals single element
        int[] test7 = {1, 2, 3, 4, 5};
        System.out.println("Test 7: " + solution.minSubArrayLen(5, test7));
        // Expected: 1

        // Test case 8: Large numbers
        int[] test8 = {12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
        System.out.println("Test 8: " + solution.minSubArrayLen(213, test8));
        // Expected: 8
    }
}
