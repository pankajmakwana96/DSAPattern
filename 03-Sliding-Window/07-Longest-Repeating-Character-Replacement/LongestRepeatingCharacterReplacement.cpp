/**
 * Longest Repeating Character Replacement
 * LeetCode: https://leetcode.com/problems/longest-repeating-character-replacement/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LongestRepeatingCharacterReplacement {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int windowSize = right - left + 1;
            int changesNeeded = windowSize - maxFreq;

            if (changesNeeded > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    LongestRepeatingCharacterReplacement solution;

    cout << "Test 1: " << solution.characterReplacement("ABAB", 2) << endl;  // 4
    cout << "Test 2: " << solution.characterReplacement("AABABBA", 1) << endl;  // 4
    cout << "Test 3: " << solution.characterReplacement("AAAA", 0) << endl;  // 4
    cout << "Test 4: " << solution.characterReplacement("ABCDE", 1) << endl;  // 2

    return 0;
}
