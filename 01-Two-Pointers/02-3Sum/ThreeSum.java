/**
 * 3Sum - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/3sum/
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(1) excluding output space
 */

import java.util.*;

class ThreeSum {

    // Approach: Sort + Two Pointers (Optimal)
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        // Edge case
        if (nums == null || nums.length < 3) {
            return result;
        }

        // Sort the array
        Arrays.sort(nums);

        // Iterate through the array
        for (int i = 0; i < nums.length - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Early termination: if the smallest number is positive, no solution exists
            if (nums[i] > 0) {
                break;
            }

            int target = -nums[i];
            int left = i + 1;
            int right = nums.length - 1;

            // Two pointers approach
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    // Found a triplet
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers
                    left++;
                    right--;
                } else if (sum < target) {
                    // Sum is too small, move left pointer right
                    left++;
                } else {
                    // Sum is too large, move right pointer left
                    right--;
                }
            }
        }

        return result;
    }

    // Alternative: Using HashSet (Less optimal)
    // Time: O(n²), Space: O(n)
    public List<List<Integer>> threeSum2(int[] nums) {
        Set<List<Integer>> result = new HashSet<>();

        if (nums == null || nums.length < 3) {
            return new ArrayList<>(result);
        }

        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            Set<Integer> seen = new HashSet<>();
            int target = -nums[i];

            for (int j = i + 1; j < nums.length; j++) {
                int complement = target - nums[j];

                if (seen.contains(complement)) {
                    List<Integer> triplet = Arrays.asList(nums[i], complement, nums[j]);
                    result.add(triplet);
                }

                seen.add(nums[j]);
            }
        }

        return new ArrayList<>(result);
    }

    // Test cases
    public static void main(String[] args) {
        ThreeSum solution = new ThreeSum();

        // Test case 1
        int[] test1 = {-1, 0, 1, 2, -1, -4};
        System.out.println("Test 1: " + solution.threeSum(test1));
        // Expected: [[-1,-1,2],[-1,0,1]]

        // Test case 2
        int[] test2 = {0, 1, 1};
        System.out.println("Test 2: " + solution.threeSum(test2));
        // Expected: []

        // Test case 3
        int[] test3 = {0, 0, 0};
        System.out.println("Test 3: " + solution.threeSum(test3));
        // Expected: [[0,0,0]]

        // Test case 4
        int[] test4 = {-2, 0, 1, 1, 2};
        System.out.println("Test 4: " + solution.threeSum(test4));
        // Expected: [[-2,0,2],[-2,1,1]]

        // Test case 5
        int[] test5 = {-4, -1, -1, 0, 1, 2};
        System.out.println("Test 5: " + solution.threeSum(test5));
        // Expected: [[-1,-1,2],[-1,0,1]]
    }
}
