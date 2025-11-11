/**
 * 3Sum - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/3sum/
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(1) excluding output space
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class ThreeSum {
public:
    // Approach: Sort + Two Pointers (Optimal)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // Edge case
        if (nums.size() < 3) {
            return result;
        }

        // Sort the array
        sort(nums.begin(), nums.end());

        // Iterate through the array
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Early termination: if the smallest number is positive, no solution exists
            if (nums[i] > 0) {
                break;
            }

            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            // Two pointers approach
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers
                    left++;
                    right--;
                } else if (sum < target) {
                    // Sum is too small, move left pointer right
                    left++;
                } else {
                    // Sum is too large, move right pointer left
                    right--;
                }
            }
        }

        return result;
    }

    // Alternative: Using HashSet (Less optimal)
    // Time: O(n²), Space: O(n)
    vector<vector<int>> threeSum2(vector<int>& nums) {
        set<vector<int>> resultSet;

        if (nums.size() < 3) {
            return vector<vector<int>>();
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            set<int> seen;
            int target = -nums[i];

            for (int j = i + 1; j < nums.size(); j++) {
                int complement = target - nums[j];

                if (seen.count(complement)) {
                    vector<int> triplet = {nums[i], complement, nums[j]};
                    resultSet.insert(triplet);
                }

                seen.insert(nums[j]);
            }
        }

        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};

// Helper function to print results
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    ThreeSum solution;

    // Test case 1
    vector<int> test1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test 1: ";
    printResult(solution.threeSum(test1));
    // Expected: [[-1,-1,2],[-1,0,1]]

    // Test case 2
    vector<int> test2 = {0, 1, 1};
    cout << "Test 2: ";
    printResult(solution.threeSum(test2));
    // Expected: []

    // Test case 3
    vector<int> test3 = {0, 0, 0};
    cout << "Test 3: ";
    printResult(solution.threeSum(test3));
    // Expected: [[0,0,0]]

    // Test case 4
    vector<int> test4 = {-2, 0, 1, 1, 2};
    cout << "Test 4: ";
    printResult(solution.threeSum(test4));
    // Expected: [[-2,0,2],[-2,1,1]]

    // Test case 5
    vector<int> test5 = {-4, -1, -1, 0, 1, 2};
    cout << "Test 5: ";
    printResult(solution.threeSum(test5));
    // Expected: [[-1,-1,2],[-1,0,1]]

    return 0;
}
