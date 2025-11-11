/**
 * Circular Array Loop - Fast and Slow Pointers
 * LeetCode: https://leetcode.com/problems/circular-array-loop/
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class CircularArrayLoop {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Skip if already visited (marked as 0)
            if (nums[i] == 0) continue;

            int slow = i, fast = i;
            bool isForward = nums[i] > 0;

            while (true) {
                // Move slow one step
                slow = getNext(nums, slow, isForward);
                if (slow == -1) break;

                // Move fast two steps
                fast = getNext(nums, fast, isForward);
                if (fast == -1) break;
                fast = getNext(nums, fast, isForward);
                if (fast == -1) break;

                // Cycle found
                if (slow == fast) {
                    // Check if cycle length > 1
                    if (slow == getNext(nums, slow, isForward)) {
                        break;  // Single element cycle, invalid
                    }
                    return true;
                }
            }

            // Mark all elements in this path as visited (set to 0)
            slow = i;
            int val = nums[i];
            while (nums[slow] != 0 && ((nums[slow] > 0) == (val > 0))) {
                int next = getNext(nums, slow, val > 0);
                nums[slow] = 0;  // Mark as visited
                slow = next;
                if (slow == -1) break;
            }
        }

        return false;
    }

private:
    // Helper method: Get next index in same direction
    int getNext(vector<int>& nums, int index, bool isForward) {
        int n = nums.size();

        // Check direction
        bool direction = nums[index] > 0;
        if (direction != isForward) {
            return -1;  // Direction changed, invalid
        }

        // Calculate next index (circular)
        int next = (index + nums[index]) % n;
        if (next < 0) {
            next += n;  // Handle negative wraparound
        }

        // Check for single element cycle
        if (next == index) {
            return -1;  // Single element cycle, invalid
        }

        return next;
    }
};

// Test cases
int main() {
    CircularArrayLoop solution;

    // Test case 1: Valid cycle
    vector<int> test1 = {2, -1, 1, 2, 2};
    cout << "Test 1: " << (solution.circularArrayLoop(test1) ? "true" : "false") << endl; // true

    // Test case 2: Single element cycle
    vector<int> test2 = {-1, 2};
    cout << "Test 2: " << (solution.circularArrayLoop(test2) ? "true" : "false") << endl; // false

    // Test case 3: Direction change
    vector<int> test3 = {-2, 1, -1, -2, -2};
    cout << "Test 3: " << (solution.circularArrayLoop(test3) ? "true" : "false") << endl; // false

    // Test case 4: All forward
    vector<int> test4 = {1, 1, 1, 1, 1};
    cout << "Test 4: " << (solution.circularArrayLoop(test4) ? "true" : "false") << endl; // true

    // Test case 5: No cycle
    vector<int> test5 = {-1, -2, -3, -4, -5};
    cout << "Test 5: " << (solution.circularArrayLoop(test5) ? "true" : "false") << endl; // false

    // Test case 6: Single element
    vector<int> test6 = {1};
    cout << "Test 6: " << (solution.circularArrayLoop(test6) ? "true" : "false") << endl; // false

    return 0;
}
