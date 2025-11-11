/**
 * Minimum Size Subarray Sum
 * LeetCode: https://leetcode.com/problems/minimum-size-subarray-sum/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class MinimumSizeSubarraySum {
public:
    // Optimal Approach: Shrinking Sliding Window
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            // Expand window
            sum += nums[right];

            // Shrink window while condition met
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};

// Test cases
int main() {
    MinimumSizeSubarraySum solution;

    // Test case 1: Normal case
    vector<int> test1 = {2, 3, 1, 2, 4, 3};
    cout << "Test 1: " << solution.minSubArrayLen(7, test1) << endl;
    // Expected: 2

    // Test case 2: Single element sufficient
    vector<int> test2 = {1, 4, 4};
    cout << "Test 2: " << solution.minSubArrayLen(4, test2) << endl;
    // Expected: 1

    // Test case 3: No valid subarray
    vector<int> test3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test 3: " << solution.minSubArrayLen(11, test3) << endl;
    // Expected: 0

    // Test case 4: Entire array needed
    vector<int> test4 = {1, 2, 3, 4, 5};
    cout << "Test 4: " << solution.minSubArrayLen(15, test4) << endl;
    // Expected: 5

    // Test case 5: Optimal window in middle
    vector<int> test5 = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
    cout << "Test 5: " << solution.minSubArrayLen(15, test5) << endl;
    // Expected: 2

    // Test case 6: All elements same
    vector<int> test6 = {2, 2, 2, 2, 2};
    cout << "Test 6: " << solution.minSubArrayLen(6, test6) << endl;
    // Expected: 3

    // Test case 7: Target equals single element
    vector<int> test7 = {1, 2, 3, 4, 5};
    cout << "Test 7: " << solution.minSubArrayLen(5, test7) << endl;
    // Expected: 1

    // Test case 8: Large numbers
    vector<int> test8 = {12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
    cout << "Test 8: " << solution.minSubArrayLen(213, test8) << endl;
    // Expected: 8

    return 0;
}
