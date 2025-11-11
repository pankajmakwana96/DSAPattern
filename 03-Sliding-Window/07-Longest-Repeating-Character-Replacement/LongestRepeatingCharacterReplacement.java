/**
 * Longest Repeating Character Replacement
 * LeetCode: https://leetcode.com/problems/longest-repeating-character-replacement/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class LongestRepeatingCharacterReplacement {

    public int characterReplacement(String s, int k) {
        int[] freq = new int[26];
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            // Add character to window
            freq[s.charAt(right) - 'A']++;
            maxFreq = Math.max(maxFreq, freq[s.charAt(right) - 'A']);

            // Check if window is valid
            int windowSize = right - left + 1;
            int changesNeeded = windowSize - maxFreq;

            // Shrink if too many changes needed
            if (changesNeeded > k) {
                freq[s.charAt(left) - 'A']--;
                left++;
            }

            // Update maximum
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    // Test cases
    public static void main(String[] args) {
        LongestRepeatingCharacterReplacement solution = new LongestRepeatingCharacterReplacement();

        System.out.println("Test 1: " + solution.characterReplacement("ABAB", 2));  // 4
        System.out.println("Test 2: " + solution.characterReplacement("AABABBA", 1));  // 4
        System.out.println("Test 3: " + solution.characterReplacement("AAAA", 0));  // 4
        System.out.println("Test 4: " + solution.characterReplacement("ABCDE", 1));  // 2
    }
}
