/**
 * Longest Substring Without Repeating Characters
 * LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(min(n, m)) where m is charset size
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class LongestSubstring {
public:
    // Approach 1: Sliding Window with HashSet
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];

            // Shrink window until no duplicate
            while (charSet.find(c) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            // Add current character
            charSet.insert(c);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    // Approach 2: Optimized with HashMap (Jump left pointer)
    int lengthOfLongestSubstring2(string s) {
        unordered_map<char, int> charIndex;  // char -> index
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];

            // If character seen before and within current window
            if (charIndex.find(c) != charIndex.end() && charIndex[c] >= left) {
                left = charIndex[c] + 1;  // Jump left pointer
            }

            charIndex[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    // Approach 3: Using character array (for ASCII)
    int lengthOfLongestSubstring3(string s) {
        vector<int> lastIndex(128, -1);  // ASCII characters
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];

            // If character seen within current window
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }

            lastIndex[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// Test cases
int main() {
    LongestSubstring solution;

    // Test case 1: Mix of characters
    cout << "Test 1: " << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    // Expected: 3 ("abc")

    // Test case 2: All same characters
    cout << "Test 2: " << solution.lengthOfLongestSubstring("bbbbb") << endl;
    // Expected: 1 ("b")

    // Test case 3: Complex case
    cout << "Test 3: " << solution.lengthOfLongestSubstring("pwwkew") << endl;
    // Expected: 3 ("wke")

    // Test case 4: Empty string
    cout << "Test 4: " << solution.lengthOfLongestSubstring("") << endl;
    // Expected: 0

    // Test case 5: Single character
    cout << "Test 5: " << solution.lengthOfLongestSubstring("a") << endl;
    // Expected: 1

    // Test case 6: All unique
    cout << "Test 6: " << solution.lengthOfLongestSubstring("abcdefg") << endl;
    // Expected: 7

    // Test case 7: With spaces
    cout << "Test 7: " << solution.lengthOfLongestSubstring("a b c a b c") << endl;
    // Expected: 3

    // Test case 8: Optimized approach
    cout << "Test 8 (HashMap): " << solution.lengthOfLongestSubstring2("abcabcbb") << endl;
    // Expected: 3

    // Test case 9: Array approach
    cout << "Test 9 (Array): " << solution.lengthOfLongestSubstring3("pwwkew") << endl;
    // Expected: 3

    return 0;
}
