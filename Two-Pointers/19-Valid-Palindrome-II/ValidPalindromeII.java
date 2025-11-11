/**
 * Valid Palindrome II - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/valid-palindrome-ii/
 *
 * Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class ValidPalindromeII {

    public boolean validPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                // Try deleting either left or right character
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }

    // Helper method to check if substring is palindrome
    private boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    // Test cases
    public static void main(String[] args) {
        ValidPalindromeII solution = new ValidPalindromeII();

        System.out.println(solution.validPalindrome("aba")); // true (already palindrome)
        System.out.println(solution.validPalindrome("abca")); // true (delete 'c' or 'b')
        System.out.println(solution.validPalindrome("abc")); // false
        System.out.println(solution.validPalindrome("racecar")); // true
        System.out.println(solution.validPalindrome("deeee")); // true
        System.out.println(solution.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"));
        // true (delete middle 'a')
    }
}
