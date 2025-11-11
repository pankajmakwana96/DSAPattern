/**
 * Sort Colors - Dutch National Flag Algorithm
 * LeetCode: https://leetcode.com/problems/sort-colors/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortColors {
public:
    // Approach 1: Dutch National Flag Algorithm (Optimal)
    // Three Pointers: low, mid, high
    void sortColors(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return;
        }

        int low = 0;      // Boundary for 0s
        int mid = 0;      // Current element
        int high = nums.size() - 1;  // Boundary for 2s

        // Invariants:
        // [0...low-1] contains 0s
        // [low...mid-1] contains 1s
        // [mid...high] is unknown (to be processed)
        // [high+1...n-1] contains 2s

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap with low boundary and move both pointers
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Already in correct position, just move mid
                mid++;
            } else { // nums[mid] == 2
                // Swap with high boundary
                // Don't increment mid as we need to examine the swapped element
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

    // Approach 2: Two Pass - Counting Sort
    void sortColors2(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // First pass: count occurrences
        for (int num : nums) {
            if (num == 0) count0++;
            else if (num == 1) count1++;
            else count2++;
        }

        // Second pass: overwrite array
        int index = 0;

        // Fill 0s
        while (count0-- > 0) {
            nums[index++] = 0;
        }

        // Fill 1s
        while (count1-- > 0) {
            nums[index++] = 1;
        }

        // Fill 2s
        while (count2-- > 0) {
            nums[index++] = 2;
        }
    }
};

// Helper function to print array
void printArray(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    SortColors solution;

    // Test case 1
    vector<int> test1 = {2, 0, 2, 1, 1, 0};
    solution.sortColors(test1);
    cout << "Test 1: ";
    printArray(test1);
    // Expected: [0, 0, 1, 1, 2, 2]

    // Test case 2
    vector<int> test2 = {2, 0, 1};
    solution.sortColors(test2);
    cout << "Test 2: ";
    printArray(test2);
    // Expected: [0, 1, 2]

    // Test case 3
    vector<int> test3 = {0};
    solution.sortColors(test3);
    cout << "Test 3: ";
    printArray(test3);
    // Expected: [0]

    // Test case 4
    vector<int> test4 = {1, 2, 0};
    solution.sortColors(test4);
    cout << "Test 4: ";
    printArray(test4);
    // Expected: [0, 1, 2]

    // Test case 5
    vector<int> test5 = {2, 2, 2, 1, 1, 0, 0};
    solution.sortColors(test5);
    cout << "Test 5: ";
    printArray(test5);
    // Expected: [0, 0, 1, 1, 2, 2, 2]

    // Test case 6: All same colors
    vector<int> test6 = {1, 1, 1, 1};
    solution.sortColors(test6);
    cout << "Test 6: ";
    printArray(test6);
    // Expected: [1, 1, 1, 1]

    return 0;
}
