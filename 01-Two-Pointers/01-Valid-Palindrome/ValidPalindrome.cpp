/**
 * Valid Palindrome - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/valid-palindrome/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class ValidPalindrome {
public:
    // Approach 1: Two Pointers (Optimal)
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric characters from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    // Approach 2: Filter and Compare
    // Time: O(n), Space: O(n)
    bool isPalindrome2(string s) {
        string filtered = "";

        // Filter and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        // Compare with reverse
        string reversed = filtered;
        reverse(reversed.begin(), reversed.end());

        return filtered == reversed;
    }
};

// Test cases
int main() {
    ValidPalindrome solution;

    // Test case 1
    string test1 = "A man, a plan, a canal: Panama";
    cout << "Test 1: " << (solution.isPalindrome(test1) ? "true" : "false") << endl; // true

    // Test case 2
    string test2 = "race a car";
    cout << "Test 2: " << (solution.isPalindrome(test2) ? "true" : "false") << endl; // false

    // Test case 3
    string test3 = " ";
    cout << "Test 3: " << (solution.isPalindrome(test3) ? "true" : "false") << endl; // true

    // Test case 4
    string test4 = "ab_a";
    cout << "Test 4: " << (solution.isPalindrome(test4) ? "true" : "false") << endl; // true

    // Test case 5
    string test5 = "0P";
    cout << "Test 5: " << (solution.isPalindrome(test5) ? "true" : "false") << endl; // false

    return 0;
}
