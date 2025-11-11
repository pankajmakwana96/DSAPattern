/**
 * Valid Word Abbreviation - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/valid-word-abbreviation/ (Premium)
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class ValidWordAbbreviation {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0; // Pointer for word
        int j = 0; // Pointer for abbr

        while (i < word.length() && j < abbr.length()) {
            char c = abbr[j];

            if (isdigit(c)) {
                // Check for leading zero
                if (c == '0') {
                    return false;
                }

                // Calculate the complete number
                int num = 0;
                while (j < abbr.length() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }

                // Skip 'num' characters in word
                i += num;
            } else {
                // Must match the character
                if (word[i] != c) {
                    return false;
                }
                i++;
                j++;
            }
        }

        // Both pointers should reach the end
        return i == word.length() && j == abbr.length();
    }
};

// Test cases
int main() {
    ValidWordAbbreviation solution;

    // Test case 1
    cout << "Test 1: " << (solution.validWordAbbreviation("internationalization", "i12iz4n") ? "true" : "false") << endl; // true

    // Test case 2
    cout << "Test 2: " << (solution.validWordAbbreviation("apple", "a2e") ? "true" : "false") << endl; // false

    // Test case 3: Leading zero
    cout << "Test 3: " << (solution.validWordAbbreviation("substitution", "s010n") ? "true" : "false") << endl; // false

    // Test case 4: Complete match
    cout << "Test 4: " << (solution.validWordAbbreviation("word", "word") ? "true" : "false") << endl; // true

    // Test case 5: All numbers
    cout << "Test 5: " << (solution.validWordAbbreviation("apple", "5") ? "true" : "false") << endl; // true

    // Test case 6: Number too large
    cout << "Test 6: " << (solution.validWordAbbreviation("apple", "a3e") ? "true" : "false") << endl; // false

    // Test case 7
    cout << "Test 7: " << (solution.validWordAbbreviation("internationalization", "i5a11o1") ? "true" : "false") << endl; // true

    // Test case 8
    cout << "Test 8: " << (solution.validWordAbbreviation("hi", "1") ? "true" : "false") << endl; // false

    // Test case 9
    cout << "Test 9: " << (solution.validWordAbbreviation("hi", "2i") ? "true" : "false") << endl; // false

    return 0;
}
