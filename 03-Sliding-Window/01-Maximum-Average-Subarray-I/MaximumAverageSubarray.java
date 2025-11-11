/**
 * Maximum Average Subarray I
 * LeetCode: https://leetcode.com/problems/maximum-average-subarray-i/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class MaximumAverageSubarray {

    // Optimal Approach: Fixed-Size Sliding Window
    public double findMaxAverage(int[] nums, int k) {
        // Calculate sum of first K elements
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        double maxSum = windowSum;

        // Slide window from index k to end
        for (int i = k; i < nums.length; i++) {
            // Remove leftmost element, add rightmost element
            windowSum = windowSum - nums[i - k] + nums[i];
            maxSum = Math.max(maxSum, windowSum);
        }

        // Return average
        return maxSum / k;
    }

    // Alternative: Using long to avoid potential overflow
    public double findMaxAverage2(int[] nums, int k) {
        long windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        long maxSum = windowSum;

        for (int i = k; i < nums.length; i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            maxSum = Math.max(maxSum, windowSum);
        }

        return (double) maxSum / k;
    }

    // Test cases
    public static void main(String[] args) {
        MaximumAverageSubarray solution = new MaximumAverageSubarray();

        // Test case 1: Normal case
        int[] test1 = {1, 12, -5, -6, 50, 3};
        int k1 = 4;
        System.out.println("Test 1: " + solution.findMaxAverage(test1, k1));
        // Expected: 12.75 (subarray [12,-5,-6,50])

        // Test case 2: Single element
        int[] test2 = {5};
        int k2 = 1;
        System.out.println("Test 2: " + solution.findMaxAverage(test2, k2));
        // Expected: 5.0

        // Test case 3: All negative numbers
        int[] test3 = {-1, -2, -3, -4, -5};
        int k3 = 2;
        System.out.println("Test 3: " + solution.findMaxAverage(test3, k3));
        // Expected: -1.5 (subarray [-1,-2])

        // Test case 4: K equals array length
        int[] test4 = {1, 2, 3, 4, 5};
        int k4 = 5;
        System.out.println("Test 4: " + solution.findMaxAverage(test4, k4));
        // Expected: 3.0

        // Test case 5: Mix of positive and negative
        int[] test5 = {0, 4, 0, 3, 2};
        int k5 = 1;
        System.out.println("Test 5: " + solution.findMaxAverage(test5, k5));
        // Expected: 4.0

        // Test case 6: Larger window
        int[] test6 = {8, 2, 6, 4, 1, 9, 3, 5};
        int k6 = 3;
        System.out.println("Test 6: " + solution.findMaxAverage(test6, k6));
        // Expected: 6.0 (subarray [4,1,9] or [1,9,3])
    }
}
