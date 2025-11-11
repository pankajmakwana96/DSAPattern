/**
 * Happy Number - Fast and Slow Pointers Approach
 * LeetCode: https://leetcode.com/problems/happy-number/
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

import java.util.HashSet;
import java.util.Set;

class HappyNumber {

    // Approach 1: Fast and Slow Pointers (Optimal - O(1) space)
    public boolean isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = getNext(slow);           // Move one step
            fast = getNext(getNext(fast));  // Move two steps

            // If fast reaches 1, it's a happy number
            if (fast == 1) {
                return true;
            }
        } while (slow != fast);  // Continue until they meet

        // If slow == fast and != 1, there's a cycle
        return false;
    }

    // Helper method: Calculate sum of squares of digits
    private int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    // Approach 2: HashSet (Easier to understand - O(n) space)
    public boolean isHappy2(int n) {
        Set<Integer> seen = new HashSet<>();

        while (n != 1 && !seen.contains(n)) {
            seen.add(n);
            n = getNext(n);
        }

        return n == 1;
    }

    // Test cases
    public static void main(String[] args) {
        HappyNumber solution = new HappyNumber();

        // Test case 1: Happy number
        System.out.println("Test 1 (19): " + solution.isHappy(19)); // true

        // Test case 2: Not happy number
        System.out.println("Test 2 (2): " + solution.isHappy(2)); // false

        // Test case 3: Already 1
        System.out.println("Test 3 (1): " + solution.isHappy(1)); // true

        // Test case 4: Another happy number
        System.out.println("Test 4 (7): " + solution.isHappy(7)); // true

        // Test case 5: Small unhappy number
        System.out.println("Test 5 (4): " + solution.isHappy(4)); // false

        // Test case 6: Larger happy number
        System.out.println("Test 6 (100): " + solution.isHappy(100)); // true

        // Test case 7: Larger unhappy number
        System.out.println("Test 7 (116): " + solution.isHappy(116)); // false
    }
}
