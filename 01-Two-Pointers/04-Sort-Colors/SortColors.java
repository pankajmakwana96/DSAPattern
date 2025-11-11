/**
 * Sort Colors - Dutch National Flag Algorithm
 * LeetCode: https://leetcode.com/problems/sort-colors/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

import java.util.Arrays;

class SortColors {

    // Approach 1: Dutch National Flag Algorithm (Optimal)
    // Three Pointers: low, mid, high
    public void sortColors(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return;
        }

        int low = 0;      // Boundary for 0s
        int mid = 0;      // Current element
        int high = nums.length - 1;  // Boundary for 2s

        // Invariants:
        // [0...low-1] contains 0s
        // [low...mid-1] contains 1s
        // [mid...high] is unknown (to be processed)
        // [high+1...n-1] contains 2s

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap with low boundary and move both pointers
                swap(nums, low, mid);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Already in correct position, just move mid
                mid++;
            } else { // nums[mid] == 2
                // Swap with high boundary
                // Don't increment mid as we need to examine the swapped element
                swap(nums, mid, high);
                high--;
            }
        }
    }

    // Approach 2: Two Pass - Counting Sort
    public void sortColors2(int[] nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // First pass: count occurrences
        for (int num : nums) {
            if (num == 0) count0++;
            else if (num == 1) count1++;
            else count2++;
        }

        // Second pass: overwrite array
        int index = 0;

        // Fill 0s
        while (count0-- > 0) {
            nums[index++] = 0;
        }

        // Fill 1s
        while (count1-- > 0) {
            nums[index++] = 1;
        }

        // Fill 2s
        while (count2-- > 0) {
            nums[index++] = 2;
        }
    }

    // Helper method to swap elements
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Test cases
    public static void main(String[] args) {
        SortColors solution = new SortColors();

        // Test case 1
        int[] test1 = {2, 0, 2, 1, 1, 0};
        solution.sortColors(test1);
        System.out.println("Test 1: " + Arrays.toString(test1));
        // Expected: [0, 0, 1, 1, 2, 2]

        // Test case 2
        int[] test2 = {2, 0, 1};
        solution.sortColors(test2);
        System.out.println("Test 2: " + Arrays.toString(test2));
        // Expected: [0, 1, 2]

        // Test case 3
        int[] test3 = {0};
        solution.sortColors(test3);
        System.out.println("Test 3: " + Arrays.toString(test3));
        // Expected: [0]

        // Test case 4
        int[] test4 = {1, 2, 0};
        solution.sortColors(test4);
        System.out.println("Test 4: " + Arrays.toString(test4));
        // Expected: [0, 1, 2]

        // Test case 5
        int[] test5 = {2, 2, 2, 1, 1, 0, 0};
        solution.sortColors(test5);
        System.out.println("Test 5: " + Arrays.toString(test5));
        // Expected: [0, 0, 1, 1, 2, 2, 2]

        // Test case 6: All same colors
        int[] test6 = {1, 1, 1, 1};
        solution.sortColors(test6);
        System.out.println("Test 6: " + Arrays.toString(test6));
        // Expected: [1, 1, 1, 1]
    }
}
