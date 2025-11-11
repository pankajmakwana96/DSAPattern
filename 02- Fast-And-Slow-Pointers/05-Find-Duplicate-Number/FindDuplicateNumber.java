/**
 * Find the Duplicate Number - Floyd's Cycle Detection on Array
 * LeetCode: https://leetcode.com/problems/find-the-duplicate-number/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

import java.util.HashSet;
import java.util.Set;

class FindDuplicateNumber {

    // Approach 1: Floyd's Cycle Detection (Optimal)
    // Treats array as implicit linked list
    public int findDuplicate(int[] nums) {
        // Phase 1: Find intersection point in the cycle
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];           // Move one step
            fast = nums[nums[fast]];     // Move two steps
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];           // Move one step
            fast = nums[fast];           // Move one step
        }

        return slow;  // The duplicate number
    }

    // Approach 2: HashSet (Violates O(1) space constraint)
    public int findDuplicate2(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (seen.contains(num)) {
                return num;
            }
            seen.add(num);
        }
        return -1;  // Should never reach here
    }

    // Approach 3: Marking (Violates no modification constraint)
    public int findDuplicate3(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int index = Math.abs(nums[i]);
            if (nums[index] < 0) {
                return index;  // Already marked, found duplicate
            }
            nums[index] = -nums[index];  // Mark as visited
        }
        return -1;
    }

    // Test cases
    public static void main(String[] args) {
        FindDuplicateNumber solution = new FindDuplicateNumber();

        // Test case 1
        int[] test1 = {1, 3, 4, 2, 2};
        System.out.println("Test 1: " + solution.findDuplicate(test1)); // 2

        // Test case 2
        int[] test2 = {3, 1, 3, 4, 2};
        System.out.println("Test 2: " + solution.findDuplicate(test2)); // 3

        // Test case 3: Minimum case
        int[] test3 = {1, 1};
        System.out.println("Test 3: " + solution.findDuplicate(test3)); // 1

        // Test case 4: Multiple duplicates
        int[] test4 = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
        System.out.println("Test 4: " + solution.findDuplicate(test4)); // 9

        // Test case 5: Duplicate at end
        int[] test5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
        System.out.println("Test 5: " + solution.findDuplicate(test5)); // 9

        // Test case 6: All same
        int[] test6 = {2, 2, 2, 2, 2};
        System.out.println("Test 6: " + solution.findDuplicate(test6)); // 2

        // Test case 7
        int[] test7 = {1, 4, 4, 2, 4};
        System.out.println("Test 7: " + solution.findDuplicate(test7)); // 4
    }
}
