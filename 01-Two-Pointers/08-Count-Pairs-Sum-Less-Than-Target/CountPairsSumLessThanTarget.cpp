/**
 * Count Pairs Whose Sum is Less than Target - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CountPairsSumLessThanTarget {
public:
    // Approach 1: Sort + Two Pointers (Optimal)
    int countPairs(vector<int>& nums, int target) {
        // Sort the array
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int count = 0;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum < target) {
                // All pairs (left, left+1), ..., (left, right) are valid
                count += (right - left);
                left++;
            } else {
                // Sum is too large, decrease it
                right--;
            }
        }

        return count;
    }

    // Approach 2: Brute Force (For comparison)
    // Time: O(n²), Space: O(1)
    int countPairs2(vector<int>& nums, int target) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] < target) {
                    count++;
                }
            }
        }

        return count;
    }
};

// Test cases
int main() {
    CountPairsSumLessThanTarget solution;

    // Test case 1
    vector<int> test1 = {-1, 1, 2, 3, 1};
    cout << "Test 1: " << solution.countPairs(test1, 2) << endl; // 3

    // Test case 2
    vector<int> test2 = {-6, 2, 5, -2, -7, -1, 3};
    cout << "Test 2: " << solution.countPairs(test2, -2) << endl; // 10

    // Test case 3
    vector<int> test3 = {1, 2, 3, 4, 5};
    cout << "Test 3: " << solution.countPairs(test3, 5) << endl; // 2

    // Test case 4
    vector<int> test4 = {-1, -2, -3};
    cout << "Test 4: " << solution.countPairs(test4, -4) << endl; // 2

    // Test case 5: All pairs valid
    vector<int> test5 = {1, 2, 3};
    cout << "Test 5: " << solution.countPairs(test5, 10) << endl; // 3

    // Test case 6: No pairs valid
    vector<int> test6 = {5, 6, 7};
    cout << "Test 6: " << solution.countPairs(test6, 5) << endl; // 0

    return 0;
}
