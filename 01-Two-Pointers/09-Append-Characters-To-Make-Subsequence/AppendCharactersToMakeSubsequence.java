/**
 * Append Characters to String to Make Subsequence - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class AppendCharactersToMakeSubsequence {

    public int appendCharacters(String s, String t) {
        int i = 0; // Pointer for s
        int j = 0; // Pointer for t

        // Try to match characters from t in s
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                j++; // Found a match
            }
            i++; // Always move forward in s
        }

        // Number of characters from t that weren't matched
        return t.length() - j;
    }

    // Alternative: More explicit version
    public int appendCharacters2(String s, String t) {
        int matched = 0;

        for (int i = 0; i < s.length() && matched < t.length(); i++) {
            if (s.charAt(i) == t.charAt(matched)) {
                matched++;
            }
        }

        return t.length() - matched;
    }

    // Test cases
    public static void main(String[] args) {
        AppendCharactersToMakeSubsequence solution = new AppendCharactersToMakeSubsequence();

        // Test case 1
        System.out.println("Test 1: " + solution.appendCharacters("coaching", "coding")); // 4

        // Test case 2
        System.out.println("Test 2: " + solution.appendCharacters("abcde", "a")); // 0

        // Test case 3
        System.out.println("Test 3: " + solution.appendCharacters("z", "abcde")); // 5

        // Test case 4: Empty t
        System.out.println("Test 4: " + solution.appendCharacters("hello", "")); // 0

        // Test case 5: t is complete subsequence
        System.out.println("Test 5: " + solution.appendCharacters("abcde", "ace")); // 0

        // Test case 6: Partial match
        System.out.println("Test 6: " + solution.appendCharacters("abc", "abcd")); // 1

        // Test case 7: No match
        System.out.println("Test 7: " + solution.appendCharacters("xyz", "abc")); // 3

        // Test case 8
        System.out.println("Test 8: " + solution.appendCharacters("leetcode", "code")); // 0
    }
}
