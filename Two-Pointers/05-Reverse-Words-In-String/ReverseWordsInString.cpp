/**
 * Reverse Words in a String - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

class ReverseWordsInString {
public:
    // Approach 1: Using stringstream (Most Practical in C++)
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract words
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the words
        reverse(words.begin(), words.end());

        // Join with single space
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }

    // Approach 2: Manual Parsing from Right to Left
    string reverseWords2(string s) {
        string result;
        int n = s.length();
        int end = n;

        // Iterate from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Skip spaces
            if (s[i] == ' ') {
                if (i + 1 < end) {
                    // Extract word and add to result
                    if (!result.empty()) {
                        result += ' ';
                    }
                    result += s.substr(i + 1, end - i - 1);
                }
                // Skip multiple spaces
                while (i >= 0 && s[i] == ' ') {
                    i--;
                }
                end = i + 1;
                i++; // Compensate for the loop decrement
            }
        }

        // Add the first word
        if (end > 0) {
            if (!result.empty()) {
                result += ' ';
            }
            result += s.substr(0, end);
        }

        return result;
    }

    // Approach 3: In-Place with Two Pointers
    string reverseWords3(string s) {
        // Remove extra spaces
        cleanSpaces(s);

        // Reverse the entire string
        reverse(s.begin(), s.end());

        // Reverse each word
        reverseEachWord(s);

        return s;
    }

private:
    // Helper: Clean extra spaces
    void cleanSpaces(string& s) {
        int i = 0, j = 0;
        int n = s.length();

        while (j < n) {
            // Skip leading spaces
            while (j < n && s[j] == ' ') j++;

            // Copy word characters
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }

            // Skip trailing spaces
            while (j < n && s[j] == ' ') j++;

            // Add single space between words
            if (j < n) {
                s[i++] = ' ';
            }
        }

        // Resize string to cleaned length
        s.resize(i);
    }

    // Helper: Reverse each word in the string
    void reverseEachWord(string& s) {
        int start = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
    }
};

// Test cases
int main() {
    ReverseWordsInString solution;

    // Test case 1
    string test1 = "the sky is blue";
    cout << "Test 1: \"" << solution.reverseWords(test1) << "\"" << endl;
    // Expected: "blue is sky the"

    // Test case 2
    string test2 = "  hello world  ";
    cout << "Test 2: \"" << solution.reverseWords(test2) << "\"" << endl;
    // Expected: "world hello"

    // Test case 3
    string test3 = "a good   example";
    cout << "Test 3: \"" << solution.reverseWords(test3) << "\"" << endl;
    // Expected: "example good a"

    // Test case 4
    string test4 = "  Bob    Loves  Alice   ";
    cout << "Test 4: \"" << solution.reverseWords(test4) << "\"" << endl;
    // Expected: "Alice Loves Bob"

    // Test case 5
    string test5 = "single";
    cout << "Test 5: \"" << solution.reverseWords(test5) << "\"" << endl;
    // Expected: "single"

    return 0;
}
