/**
 * Count Subarrays With Fixed Bounds - Three Pointers Approach
 * LeetCode: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CountSubarraysFixedBounds {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int lastMin = -1;      // Last position where we saw minK
        int lastMax = -1;      // Last position where we saw maxK
        int lastInvalid = -1;  // Last position of element outside [minK, maxK]

        for (int i = 0; i < nums.size(); i++) {
            // Check if current element is outside valid range
            if (nums[i] < minK || nums[i] > maxK) {
                lastInvalid = i;
            }

            // Update last positions of minK and maxK
            if (nums[i] == minK) {
                lastMin = i;
            }

            if (nums[i] == maxK) {
                lastMax = i;
            }

            // Count valid subarrays ending at position i
            // We need both minK and maxK to appear after lastInvalid
            // Number of valid starting positions: from (lastInvalid+1) to min(lastMin, lastMax)
            count += max(0, min(lastMin, lastMax) - lastInvalid);
        }

        return count;
    }
};

// Test cases
int main() {
    CountSubarraysFixedBounds solution;

    // Test case 1
    vector<int> test1 = {1, 3, 5, 2, 7, 5};
    cout << "Test 1: " << solution.countSubarrays(test1, 1, 5) << endl; // 2

    // Test case 2
    vector<int> test2 = {1, 1, 1, 1};
    cout << "Test 2: " << solution.countSubarrays(test2, 1, 1) << endl; // 10

    // Test case 3
    vector<int> test3 = {1, 3, 5, 2, 7, 5};
    cout << "Test 3: " << solution.countSubarrays(test3, 1, 6) << endl; // 0 (no 6)

    // Test case 4
    vector<int> test4 = {1, 2, 3, 4, 5};
    cout << "Test 4: " << solution.countSubarrays(test4, 1, 5) << endl; // 1

    // Test case 5
    vector<int> test5 = {5, 5, 1, 5, 1};
    cout << "Test 5: " << solution.countSubarrays(test5, 1, 5) << endl; // 7

    // Test case 6: Array with invalid elements
    vector<int> test6 = {1, 3, 5, 2, 10, 1, 5};
    cout << "Test 6: " << solution.countSubarrays(test6, 1, 5) << endl; // 3

    return 0;
}
