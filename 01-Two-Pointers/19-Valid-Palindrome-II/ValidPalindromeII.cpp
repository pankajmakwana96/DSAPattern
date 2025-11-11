/**
 * Valid Palindrome II - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/valid-palindrome-ii/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

class ValidPalindromeII {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Try deleting either left or right character
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }

private:
    // Helper method to check if substring is palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    ValidPalindromeII solution;

    cout << (solution.validPalindrome("aba") ? "true" : "false") << endl; // true
    cout << (solution.validPalindrome("abca") ? "true" : "false") << endl; // true
    cout << (solution.validPalindrome("abc") ? "true" : "false") << endl; // false
    cout << (solution.validPalindrome("racecar") ? "true" : "false") << endl; // true
    cout << (solution.validPalindrome("deeee") ? "true" : "false") << endl; // true

    return 0;
}
