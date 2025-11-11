/**
 * Strobogrammatic Number - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/strobogrammatic-number/ (Premium)
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class StrobogrammaticNumber {
public:
    bool isStrobogrammatic(string num) {
        // Map of valid strobogrammatic pairs
        unordered_map<char, char> validPairs = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };

        int left = 0;
        int right = num.length() - 1;

        while (left <= right) {
            char leftChar = num[left];
            char rightChar = num[right];

            // Check if leftChar is a valid strobogrammatic digit
            if (validPairs.find(leftChar) == validPairs.end()) {
                return false;
            }

            // Check if the pair is valid
            if (validPairs[leftChar] != rightChar) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    // Alternative: Without using map
    bool isStrobogrammatic2(string num) {
        int left = 0;
        int right = num.length() - 1;

        while (left <= right) {
            char l = num[left];
            char r = num[right];

            if (!isValidPair(l, r)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

private:
    bool isValidPair(char left, char right) {
        if (left == '0' && right == '0') return true;
        if (left == '1' && right == '1') return true;
        if (left == '6' && right == '9') return true;
        if (left == '8' && right == '8') return true;
        if (left == '9' && right == '6') return true;
        return false;
    }
};

// Test cases
int main() {
    StrobogrammaticNumber solution;

    // Test case 1
    cout << "Test 1: " << (solution.isStrobogrammatic("69") ? "true" : "false") << endl; // true

    // Test case 2
    cout << "Test 2: " << (solution.isStrobogrammatic("88") ? "true" : "false") << endl; // true

    // Test case 3
    cout << "Test 3: " << (solution.isStrobogrammatic("962") ? "true" : "false") << endl; // false

    // Test case 4
    cout << "Test 4: " << (solution.isStrobogrammatic("1") ? "true" : "false") << endl; // true

    // Test case 5
    cout << "Test 5: " << (solution.isStrobogrammatic("2") ? "true" : "false") << endl; // false

    // Test case 6
    cout << "Test 6: " << (solution.isStrobogrammatic("818") ? "true" : "false") << endl; // true

    // Test case 7
    cout << "Test 7: " << (solution.isStrobogrammatic("96") ? "true" : "false") << endl; // false

    // Test case 8
    cout << "Test 8: " << (solution.isStrobogrammatic("11") ? "true" : "false") << endl; // true

    // Test case 9
    cout << "Test 9: " << (solution.isStrobogrammatic("25") ? "true" : "false") << endl; // false

    return 0;
}
