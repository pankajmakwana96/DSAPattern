/**
 * Squares of a Sorted Array - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/squares-of-a-sorted-array/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) for the output array
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SquaresOfSortedArray {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0;
        int right = n - 1;
        int index = n - 1; // Fill from the end

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[index] = leftSquare;
                left++;
            } else {
                result[index] = rightSquare;
                right--;
            }
            index--;
        }

        return result;
    }

    // Alternative: Square and Sort
    vector<int> sortedSquares2(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    SquaresOfSortedArray solution;

    vector<int> test1 = {-4,-1,0,3,10};
    printVector(solution.sortedSquares(test1)); // [0,1,9,16,100]

    vector<int> test2 = {-7,-3,2,3,11};
    printVector(solution.sortedSquares(test2)); // [4,9,9,49,121]

    vector<int> test3 = {-5,-3,-2,-1};
    printVector(solution.sortedSquares(test3)); // [1,4,9,25]

    vector<int> test4 = {1,2,3,4,5};
    printVector(solution.sortedSquares(test4)); // [1,4,9,16,25]

    return 0;
}
