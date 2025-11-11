/**
 * Sliding Window Maximum
 * LeetCode: https://leetcode.com/problems/sliding-window-maximum/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(k)
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class SlidingWindowMaximum {
public:
    // Optimal Approach: Monotonic Decreasing Deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) {
            return {};
        }

        int n = nums.size();
        vector<int> result;
        deque<int> dq;  // stores indices

        for (int i = 0; i < n; i++) {
            // Remove indices outside current window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove indices with smaller values from back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // Add max to result (window is complete)
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    SlidingWindowMaximum solution;

    // Test case 1: Normal case
    vector<int> test1 = {1, 3, -1, -3, 5, 3, 6, 7};
    cout << "Test 1: ";
    printVector(solution.maxSlidingWindow(test1, 3));
    // Expected: [3, 3, 5, 5, 6, 7]

    // Test case 2: Single element
    vector<int> test2 = {1};
    cout << "Test 2: ";
    printVector(solution.maxSlidingWindow(test2, 1));
    // Expected: [1]

    // Test case 3: K equals array length
    vector<int> test3 = {1, 3, 1, 2, 0, 5};
    cout << "Test 3: ";
    printVector(solution.maxSlidingWindow(test3, 6));
    // Expected: [5]

    // Test case 4: Decreasing array
    vector<int> test4 = {9, 8, 7, 6, 5, 4};
    cout << "Test 4: ";
    printVector(solution.maxSlidingWindow(test4, 3));
    // Expected: [9, 8, 7, 6]

    // Test case 5: Increasing array
    vector<int> test5 = {1, 2, 3, 4, 5, 6};
    cout << "Test 5: ";
    printVector(solution.maxSlidingWindow(test5, 3));
    // Expected: [3, 4, 5, 6]

    // Test case 6: All same
    vector<int> test6 = {5, 5, 5, 5, 5};
    cout << "Test 6: ";
    printVector(solution.maxSlidingWindow(test6, 2));
    // Expected: [5, 5, 5, 5]

    return 0;
}
