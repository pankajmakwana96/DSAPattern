/**
 * Maximum Average Subarray I
 * LeetCode: https://leetcode.com/problems/maximum-average-subarray-i/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class MaximumAverageSubarray {
public:
    // Optimal Approach: Fixed-Size Sliding Window
    double findMaxAverage(vector<int>& nums, int k) {
        // Calculate sum of first K elements
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        double maxSum = windowSum;

        // Slide window from index k to end
        for (int i = k; i < nums.size(); i++) {
            // Remove leftmost element, add rightmost element
            windowSum = windowSum - nums[i - k] + nums[i];
            maxSum = max(maxSum, windowSum);
        }

        // Return average
        return maxSum / k;
    }

    // Alternative: Using long to avoid potential overflow
    double findMaxAverage2(vector<int>& nums, int k) {
        long long windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        long long maxSum = windowSum;

        for (int i = k; i < nums.size(); i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            maxSum = max(maxSum, windowSum);
        }

        return static_cast<double>(maxSum) / k;
    }
};

// Test cases
int main() {
    MaximumAverageSubarray solution;

    // Set precision for output
    cout << fixed << setprecision(5);

    // Test case 1: Normal case
    vector<int> test1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "Test 1: " << solution.findMaxAverage(test1, k1) << endl;
    // Expected: 12.75000

    // Test case 2: Single element
    vector<int> test2 = {5};
    int k2 = 1;
    cout << "Test 2: " << solution.findMaxAverage(test2, k2) << endl;
    // Expected: 5.00000

    // Test case 3: All negative numbers
    vector<int> test3 = {-1, -2, -3, -4, -5};
    int k3 = 2;
    cout << "Test 3: " << solution.findMaxAverage(test3, k3) << endl;
    // Expected: -1.50000

    // Test case 4: K equals array length
    vector<int> test4 = {1, 2, 3, 4, 5};
    int k4 = 5;
    cout << "Test 4: " << solution.findMaxAverage(test4, k4) << endl;
    // Expected: 3.00000

    // Test case 5: Mix of positive and negative
    vector<int> test5 = {0, 4, 0, 3, 2};
    int k5 = 1;
    cout << "Test 5: " << solution.findMaxAverage(test5, k5) << endl;
    // Expected: 4.00000

    // Test case 6: Larger window
    vector<int> test6 = {8, 2, 6, 4, 1, 9, 3, 5};
    int k6 = 3;
    cout << "Test 6: " << solution.findMaxAverage(test6, k6) << endl;
    // Expected: 5.66667 or 6.33333

    return 0;
}
