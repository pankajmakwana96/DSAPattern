/**
 * Append Characters to String to Make Subsequence - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

class AppendCharactersToMakeSubsequence {
public:
    int appendCharacters(string s, string t) {
        int i = 0; // Pointer for s
        int j = 0; // Pointer for t

        // Try to match characters from t in s
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                j++; // Found a match
            }
            i++; // Always move forward in s
        }

        // Number of characters from t that weren't matched
        return t.length() - j;
    }

    // Alternative: More explicit version
    int appendCharacters2(string s, string t) {
        int matched = 0;

        for (int i = 0; i < s.length() && matched < t.length(); i++) {
            if (s[i] == t[matched]) {
                matched++;
            }
        }

        return t.length() - matched;
    }
};

// Test cases
int main() {
    AppendCharactersToMakeSubsequence solution;

    // Test case 1
    cout << "Test 1: " << solution.appendCharacters("coaching", "coding") << endl; // 4

    // Test case 2
    cout << "Test 2: " << solution.appendCharacters("abcde", "a") << endl; // 0

    // Test case 3
    cout << "Test 3: " << solution.appendCharacters("z", "abcde") << endl; // 5

    // Test case 4: Empty t
    cout << "Test 4: " << solution.appendCharacters("hello", "") << endl; // 0

    // Test case 5: t is complete subsequence
    cout << "Test 5: " << solution.appendCharacters("abcde", "ace") << endl; // 0

    // Test case 6: Partial match
    cout << "Test 6: " << solution.appendCharacters("abc", "abcd") << endl; // 1

    // Test case 7: No match
    cout << "Test 7: " << solution.appendCharacters("xyz", "abc") << endl; // 3

    // Test case 8
    cout << "Test 8: " << solution.appendCharacters("leetcode", "code") << endl; // 0

    return 0;
}
