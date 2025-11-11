/**
 * Minimum Window Substring
 * LeetCode: https://leetcode.com/problems/minimum-window-substring/
 *
 * Time Complexity: O(m + n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class MinimumWindowSubstring {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }

        // Build frequency map of t
        unordered_map<char, int> required;
        for (char c : t) {
            required[c]++;
        }

        // Sliding window
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int have = 0, need = required.size();  // unique chars matched
        int minLen = INT_MAX, resultStart = 0;

        while (right < s.length()) {
            // Expand window
            char c = s[right];
            window[c]++;

            // Check if this char completes a requirement
            if (required.find(c) != required.end() && window[c] == required[c]) {
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
                char leftChar = s[left];
                window[leftChar]--;

                if (required.find(leftChar) != required.end() &&
                    window[leftChar] < required[leftChar]) {
                    have--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(resultStart, minLen);
    }
};

// Test cases
int main() {
    MinimumWindowSubstring solution;

    // Test case 1: Normal case
    cout << "Test 1: '" << solution.minWindow("ADOBECODEBANC", "ABC") << "'" << endl;
    // Expected: "BANC"

    // Test case 2: Single character
    cout << "Test 2: '" << solution.minWindow("a", "a") << "'" << endl;
    // Expected: "a"

    // Test case 3: Not possible
    cout << "Test 3: '" << solution.minWindow("a", "aa") << "'" << endl;
    // Expected: ""

    // Test case 4: t longer than s
    cout << "Test 4: '" << solution.minWindow("ab", "abc") << "'" << endl;
    // Expected: ""

    // Test case 5: Entire string needed
    cout << "Test 5: '" << solution.minWindow("abc", "abc") << "'" << endl;
    // Expected: "abc"

    // Test case 6: Multiple occurrences
    cout << "Test 6: '" << solution.minWindow("aa", "aa") << "'" << endl;
    // Expected: "aa"

    // Test case 7: Complex case
    cout << "Test 7: '" << solution.minWindow("ABAACBAB", "ABC") << "'" << endl;
    // Expected: "ACB" or similar

    // Test case 8: t has duplicates
    cout << "Test 8: '" << solution.minWindow("aaaaaaaaaa", "aaaa") << "'" << endl;
    // Expected: "aaaa"

    return 0;
}
