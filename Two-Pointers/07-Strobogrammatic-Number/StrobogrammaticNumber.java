/**
 * Strobogrammatic Number - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/strobogrammatic-number/ (Premium)
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

import java.util.HashMap;
import java.util.Map;

class StrobogrammaticNumber {

    public boolean isStrobogrammatic(String num) {
        // Map of valid strobogrammatic pairs
        Map<Character, Character> map = new HashMap<>();
        map.put('0', '0');
        map.put('1', '1');
        map.put('6', '9');
        map.put('8', '8');
        map.put('9', '6');

        int left = 0;
        int right = num.length() - 1;

        while (left <= right) {
            char leftChar = num.charAt(left);
            char rightChar = num.charAt(right);

            // Check if leftChar is a valid strobogrammatic digit
            if (!map.containsKey(leftChar)) {
                return false;
            }

            // Check if the pair is valid
            if (map.get(leftChar) != rightChar) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    // Alternative: Using array for faster lookup
    public boolean isStrobogrammatic2(String num) {
        int left = 0;
        int right = num.length() - 1;

        while (left <= right) {
            char l = num.charAt(left);
            char r = num.charAt(right);

            if (!isValidPair(l, r)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    private boolean isValidPair(char left, char right) {
        if (left == '0' && right == '0') return true;
        if (left == '1' && right == '1') return true;
        if (left == '6' && right == '9') return true;
        if (left == '8' && right == '8') return true;
        if (left == '9' && right == '6') return true;
        return false;
    }

    // Test cases
    public static void main(String[] args) {
        StrobogrammaticNumber solution = new StrobogrammaticNumber();

        // Test case 1
        System.out.println("Test 1: " + solution.isStrobogrammatic("69")); // true

        // Test case 2
        System.out.println("Test 2: " + solution.isStrobogrammatic("88")); // true

        // Test case 3
        System.out.println("Test 3: " + solution.isStrobogrammatic("962")); // false

        // Test case 4
        System.out.println("Test 4: " + solution.isStrobogrammatic("1")); // true

        // Test case 5
        System.out.println("Test 5: " + solution.isStrobogrammatic("2")); // false

        // Test case 6
        System.out.println("Test 6: " + solution.isStrobogrammatic("818")); // true

        // Test case 7
        System.out.println("Test 7: " + solution.isStrobogrammatic("96")); // false (6 must pair with 9)

        // Test case 8
        System.out.println("Test 8: " + solution.isStrobogrammatic("11")); // true

        // Test case 9
        System.out.println("Test 9: " + solution.isStrobogrammatic("25")); // false
    }
}
