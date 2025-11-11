/**
 * Valid Palindrome - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/valid-palindrome/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class ValidPalindrome {

    // Approach 1: Two Pointers (Optimal)
    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return true;
        }

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }

            // Skip non-alphanumeric characters from right
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }

            // Compare characters (case-insensitive)
            if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    // Approach 2: Filter and Compare
    // Time: O(n), Space: O(n)
    public boolean isPalindrome2(String s) {
        StringBuilder filtered = new StringBuilder();

        // Filter and convert to lowercase
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                filtered.append(Character.toLowerCase(c));
            }
        }

        // Compare with reverse
        String filteredStr = filtered.toString();
        String reversed = filtered.reverse().toString();

        return filteredStr.equals(reversed);
    }

    // Test cases
    public static void main(String[] args) {
        ValidPalindrome solution = new ValidPalindrome();

        // Test case 1
        String test1 = "A man, a plan, a canal: Panama";
        System.out.println("Test 1: " + solution.isPalindrome(test1)); // true

        // Test case 2
        String test2 = "race a car";
        System.out.println("Test 2: " + solution.isPalindrome(test2)); // false

        // Test case 3
        String test3 = " ";
        System.out.println("Test 3: " + solution.isPalindrome(test3)); // true

        // Test case 4
        String test4 = "ab_a";
        System.out.println("Test 4: " + solution.isPalindrome(test4)); // true

        // Test case 5
        String test5 = "0P";
        System.out.println("Test 5: " + solution.isPalindrome(test5)); // false
    }
}
