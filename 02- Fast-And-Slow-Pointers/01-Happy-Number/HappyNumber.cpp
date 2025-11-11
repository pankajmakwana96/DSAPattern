/**
 * Happy Number - Fast and Slow Pointers Approach
 * LeetCode: https://leetcode.com/problems/happy-number/
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class HappyNumber {
public:
    // Approach 1: Fast and Slow Pointers (Optimal - O(1) space)
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = getNext(slow);           // Move one step
            fast = getNext(getNext(fast));  // Move two steps

            // If fast reaches 1, it's a happy number
            if (fast == 1) {
                return true;
            }
        } while (slow != fast);  // Continue until they meet

        // If slow == fast and != 1, there's a cycle
        return false;
    }

    // Helper method: Calculate sum of squares of digits
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    // Approach 2: HashSet (Easier to understand - O(n) space)
    bool isHappy2(int n) {
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};

// Test cases
int main() {
    HappyNumber solution;

    // Test case 1: Happy number
    cout << "Test 1 (19): " << (solution.isHappy(19) ? "true" : "false") << endl; // true

    // Test case 2: Not happy number
    cout << "Test 2 (2): " << (solution.isHappy(2) ? "true" : "false") << endl; // false

    // Test case 3: Already 1
    cout << "Test 3 (1): " << (solution.isHappy(1) ? "true" : "false") << endl; // true

    // Test case 4: Another happy number
    cout << "Test 4 (7): " << (solution.isHappy(7) ? "true" : "false") << endl; // true

    // Test case 5: Small unhappy number
    cout << "Test 5 (4): " << (solution.isHappy(4) ? "true" : "false") << endl; // false

    // Test case 6: Larger happy number
    cout << "Test 6 (100): " << (solution.isHappy(100) ? "true" : "false") << endl; // true

    // Test case 7: Larger unhappy number
    cout << "Test 7 (116): " << (solution.isHappy(116) ? "true" : "false") << endl; // false

    return 0;
}
