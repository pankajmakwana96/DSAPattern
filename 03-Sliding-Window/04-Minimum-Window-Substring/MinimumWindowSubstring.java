/**
 * Minimum Window Substring
 * LeetCode: https://leetcode.com/problems/minimum-window-substring/
 *
 * Time Complexity: O(m + n)
 * Space Complexity: O(n)
 */

import java.util.HashMap;
import java.util.Map;

class MinimumWindowSubstring {

    public String minWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }

        // Build frequency map of t
        Map<Character, Integer> required = new HashMap<>();
        for (char c : t.toCharArray()) {
            required.put(c, required.getOrDefault(c, 0) + 1);
        }

        // Sliding window
        Map<Character, Integer> window = new HashMap<>();
        int left = 0, right = 0;
        int have = 0, need = required.size();  // unique chars matched
        int minLen = Integer.MAX_VALUE, resultStart = 0;

        while (right < s.length()) {
            // Expand window
            char c = s.charAt(right);
            window.put(c, window.getOrDefault(c, 0) + 1);

            // Check if this char completes a requirement
            if (required.containsKey(c) &&
                window.get(c).intValue() == required.get(c).intValue()) {
                have++;
            }

            // Shrink window while valid
            while (have == need) {
                // Update result
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    resultStart = left;
                }

                // Shrink from left
                char leftChar = s.charAt(left);
                window.put(leftChar, window.get(leftChar) - 1);

                if (required.containsKey(leftChar) &&
                    window.get(leftChar) < required.get(leftChar)) {
                    have--;
                }

                left++;
            }

            right++;
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(resultStart, resultStart + minLen);
    }

    // Test cases
    public static void main(String[] args) {
        MinimumWindowSubstring solution = new MinimumWindowSubstring();

        // Test case 1: Normal case
        System.out.println("Test 1: '" + solution.minWindow("ADOBECODEBANC", "ABC") + "'");
        // Expected: "BANC"

        // Test case 2: Single character
        System.out.println("Test 2: '" + solution.minWindow("a", "a") + "'");
        // Expected: "a"

        // Test case 3: Not possible
        System.out.println("Test 3: '" + solution.minWindow("a", "aa") + "'");
        // Expected: ""

        // Test case 4: t longer than s
        System.out.println("Test 4: '" + solution.minWindow("ab", "abc") + "'");
        // Expected: ""

        // Test case 5: Entire string needed
        System.out.println("Test 5: '" + solution.minWindow("abc", "abc") + "'");
        // Expected: "abc"

        // Test case 6: Multiple occurrences
        System.out.println("Test 6: '" + solution.minWindow("aa", "aa") + "'");
        // Expected: "aa"

        // Test case 7: Complex case
        System.out.println("Test 7: '" + solution.minWindow("ABAACBAB", "ABC") + "'");
        // Expected: "ACB" or "BAC" or similar

        // Test case 8: t has duplicates
        System.out.println("Test 8: '" + solution.minWindow("aaaaaaaaaa", "aaaa") + "'");
        // Expected: "aaaa"
    }
}
