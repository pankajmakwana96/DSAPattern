/**
 * Find the Duplicate Number - Floyd's Cycle Detection on Array
 * LeetCode: https://leetcode.com/problems/find-the-duplicate-number/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

class FindDuplicateNumber {
public:
    // Approach 1: Floyd's Cycle Detection (Optimal)
    // Treats array as implicit linked list
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Find intersection point in the cycle
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];           // Move one step
            fast = nums[nums[fast]];     // Move two steps
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];           // Move one step
            fast = nums[fast];           // Move one step
        }

        return slow;  // The duplicate number
    }

    // Approach 2: HashSet (Violates O(1) space constraint)
    int findDuplicate2(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return num;
            }
            seen.insert(num);
        }
        return -1;  // Should never reach here
    }

    // Approach 3: Marking (Violates no modification constraint)
    int findDuplicate3(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]);
            if (nums[index] < 0) {
                return index;  // Already marked, found duplicate
            }
            nums[index] = -nums[index];  // Mark as visited
        }
        return -1;
    }
};

// Test cases
int main() {
    FindDuplicateNumber solution;

    // Test case 1
    vector<int> test1 = {1, 3, 4, 2, 2};
    cout << "Test 1: " << solution.findDuplicate(test1) << endl; // 2

    // Test case 2
    vector<int> test2 = {3, 1, 3, 4, 2};
    cout << "Test 2: " << solution.findDuplicate(test2) << endl; // 3

    // Test case 3: Minimum case
    vector<int> test3 = {1, 1};
    cout << "Test 3: " << solution.findDuplicate(test3) << endl; // 1

    // Test case 4: Multiple duplicates
    vector<int> test4 = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    cout << "Test 4: " << solution.findDuplicate(test4) << endl; // 9

    // Test case 5: Duplicate at end
    vector<int> test5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    cout << "Test 5: " << solution.findDuplicate(test5) << endl; // 9

    // Test case 6: All same
    vector<int> test6 = {2, 2, 2, 2, 2};
    cout << "Test 6: " << solution.findDuplicate(test6) << endl; // 2

    // Test case 7
    vector<int> test7 = {1, 4, 4, 2, 4};
    cout << "Test 7: " << solution.findDuplicate(test7) << endl; // 4

    return 0;
}
