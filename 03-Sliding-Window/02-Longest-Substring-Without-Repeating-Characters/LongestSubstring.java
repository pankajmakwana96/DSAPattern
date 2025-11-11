/**
 * Longest Substring Without Repeating Characters
 * LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(min(n, m)) where m is charset size
 */

import java.util.HashSet;
import java.util.HashMap;
import java.util.Set;
import java.util.Map;

class LongestSubstring {

    // Approach 1: Sliding Window with HashSet
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);

            // Shrink window until no duplicate
            while (set.contains(c)) {
                set.remove(s.charAt(left));
                left++;
            }

            // Add current character
            set.add(c);
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    // Approach 2: Optimized with HashMap (Jump left pointer)
    public int lengthOfLongestSubstring2(String s) {
        Map<Character, Integer> map = new HashMap<>();  // char -> index
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);

            // If character seen before and within current window
            if (map.containsKey(c) && map.get(c) >= left) {
                left = map.get(c) + 1;  // Jump left pointer
            }

            map.put(c, right);
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    // Approach 3: Using character array (for ASCII)
    public int lengthOfLongestSubstring3(String s) {
        int[] lastIndex = new int[128];  // ASCII characters
        for (int i = 0; i < 128; i++) {
            lastIndex[i] = -1;
        }

        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);

            // If character seen within current window
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }

            lastIndex[c] = right;
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    // Test cases
    public static void main(String[] args) {
        LongestSubstring solution = new LongestSubstring();

        // Test case 1: Mix of characters
        System.out.println("Test 1: " + solution.lengthOfLongestSubstring("abcabcbb"));
        // Expected: 3 ("abc")

        // Test case 2: All same characters
        System.out.println("Test 2: " + solution.lengthOfLongestSubstring("bbbbb"));
        // Expected: 1 ("b")

        // Test case 3: Complex case
        System.out.println("Test 3: " + solution.lengthOfLongestSubstring("pwwkew"));
        // Expected: 3 ("wke")

        // Test case 4: Empty string
        System.out.println("Test 4: " + solution.lengthOfLongestSubstring(""));
        // Expected: 0

        // Test case 5: Single character
        System.out.println("Test 5: " + solution.lengthOfLongestSubstring("a"));
        // Expected: 1

        // Test case 6: All unique
        System.out.println("Test 6: " + solution.lengthOfLongestSubstring("abcdefg"));
        // Expected: 7

        // Test case 7: With spaces and symbols
        System.out.println("Test 7: " + solution.lengthOfLongestSubstring("a b c a b c"));
        // Expected: 3 (" ab" or "a b")

        // Test case 8: Optimized approach
        System.out.println("Test 8 (HashMap): " + solution.lengthOfLongestSubstring2("abcabcbb"));
        // Expected: 3

        // Test case 9: Array approach
        System.out.println("Test 9 (Array): " + solution.lengthOfLongestSubstring3("pwwkew"));
        // Expected: 3
    }
}
