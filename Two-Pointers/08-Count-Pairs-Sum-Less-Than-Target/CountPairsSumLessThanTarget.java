/**
 * Count Pairs Whose Sum is Less than Target - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */

import java.util.Arrays;

class CountPairsSumLessThanTarget {

    // Approach 1: Sort + Two Pointers (Optimal)
    public int countPairs(int[] nums, int target) {
        // Sort the array
        Arrays.sort(nums);

        int left = 0;
        int right = nums.length - 1;
        int count = 0;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum < target) {
                // All pairs (left, left+1), ..., (left, right) are valid
                count += (right - left);
                left++;
            } else {
                // Sum is too large, decrease it
                right--;
            }
        }

        return count;
    }

    // Approach 2: Brute Force (For comparison)
    // Time: O(n²), Space: O(1)
    public int countPairs2(int[] nums, int target) {
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] < target) {
                    count++;
                }
            }
        }

        return count;
    }

    // Test cases
    public static void main(String[] args) {
        CountPairsSumLessThanTarget solution = new CountPairsSumLessThanTarget();

        // Test case 1
        int[] test1 = {-1, 1, 2, 3, 1};
        System.out.println("Test 1: " + solution.countPairs(test1, 2)); // 3

        // Test case 2
        int[] test2 = {-6, 2, 5, -2, -7, -1, 3};
        System.out.println("Test 2: " + solution.countPairs(test2, -2)); // 10

        // Test case 3
        int[] test3 = {1, 2, 3, 4, 5};
        System.out.println("Test 3: " + solution.countPairs(test3, 5)); // 2

        // Test case 4
        int[] test4 = {-1, -2, -3};
        System.out.println("Test 4: " + solution.countPairs(test4, -4)); // 2

        // Test case 5: All pairs valid
        int[] test5 = {1, 2, 3};
        System.out.println("Test 5: " + solution.countPairs(test5, 10)); // 3

        // Test case 6: No pairs valid
        int[] test6 = {5, 6, 7};
        System.out.println("Test 6: " + solution.countPairs(test6, 5)); // 0
    }
}
