/**
 * Count Subarrays With Fixed Bounds - Three Pointers Approach
 * LeetCode: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class CountSubarraysFixedBounds {

    public long countSubarrays(int[] nums, int minK, int maxK) {
        long count = 0;
        int lastMin = -1;      // Last position where we saw minK
        int lastMax = -1;      // Last position where we saw maxK
        int lastInvalid = -1;  // Last position of element outside [minK, maxK]

        for (int i = 0; i < nums.length; i++) {
            // Check if current element is outside valid range
            if (nums[i] < minK || nums[i] > maxK) {
                lastInvalid = i;
            }

            // Update last positions of minK and maxK
            if (nums[i] == minK) {
                lastMin = i;
            }

            if (nums[i] == maxK) {
                lastMax = i;
            }

            // Count valid subarrays ending at position i
            // We need both minK and maxK to appear after lastInvalid
            // Number of valid starting positions: from (lastInvalid+1) to min(lastMin, lastMax)
            count += Math.max(0, Math.min(lastMin, lastMax) - lastInvalid);
        }

        return count;
    }

    // Test cases
    public static void main(String[] args) {
        CountSubarraysFixedBounds solution = new CountSubarraysFixedBounds();

        // Test case 1
        int[] test1 = {1, 3, 5, 2, 7, 5};
        System.out.println("Test 1: " + solution.countSubarrays(test1, 1, 5)); // 2

        // Test case 2
        int[] test2 = {1, 1, 1, 1};
        System.out.println("Test 2: " + solution.countSubarrays(test2, 1, 1)); // 10

        // Test case 3
        int[] test3 = {1, 3, 5, 2, 7, 5};
        System.out.println("Test 3: " + solution.countSubarrays(test3, 1, 6)); // 0 (no 6)

        // Test case 4
        int[] test4 = {1, 2, 3, 4, 5};
        System.out.println("Test 4: " + solution.countSubarrays(test4, 1, 5)); // 1

        // Test case 5
        int[] test5 = {5, 5, 1, 5, 1};
        System.out.println("Test 5: " + solution.countSubarrays(test5, 1, 5)); // 7

        // Test case 6: Array with invalid elements
        int[] test6 = {1, 3, 5, 2, 10, 1, 5};
        System.out.println("Test 6: " + solution.countSubarrays(test6, 1, 5)); // 3
    }
}
