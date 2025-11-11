/**
 * Squares of a Sorted Array - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/squares-of-a-sorted-array/
 *
 * Given an integer array nums sorted in non-decreasing order,
 * return an array of the squares of each number sorted in non-decreasing order.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) for the output array
 */

import java.util.Arrays;

class SquaresOfSortedArray {

    // Approach: Two Pointers from Both Ends (Optimal)
    // Since array is sorted, largest squares are at the ends (negative or positive extremes)
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        int left = 0;
        int right = n - 1;
        int index = n - 1; // Fill from the end

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[index] = leftSquare;
                left++;
            } else {
                result[index] = rightSquare;
                right--;
            }
            index--;
        }

        return result;
    }

    // Alternative: Square and Sort
    // Time: O(n log n), Space: O(1)
    public int[] sortedSquares2(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] = nums[i] * nums[i];
        }
        Arrays.sort(nums);
        return nums;
    }

    // Test cases
    public static void main(String[] args) {
        SquaresOfSortedArray solution = new SquaresOfSortedArray();

        System.out.println(Arrays.toString(solution.sortedSquares(new int[]{-4,-1,0,3,10}))); // [0,1,9,16,100]
        System.out.println(Arrays.toString(solution.sortedSquares(new int[]{-7,-3,2,3,11}))); // [4,9,9,49,121]
        System.out.println(Arrays.toString(solution.sortedSquares(new int[]{-5,-3,-2,-1}))); // [1,4,9,25]
        System.out.println(Arrays.toString(solution.sortedSquares(new int[]{1,2,3,4,5}))); // [1,4,9,16,25]
    }
}
