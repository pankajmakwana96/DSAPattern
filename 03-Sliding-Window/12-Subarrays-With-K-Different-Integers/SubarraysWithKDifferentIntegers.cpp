/**
 * Subarrays with K Different Integers
 * Time: O(n), Space: O(k)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SubarraysWithKDifferentIntegers {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
};

int main() {
    SubarraysWithKDifferentIntegers solution;
    vector<int> test = {1, 2, 1, 2, 3};
    cout << solution.subarraysWithKDistinct(test, 2) << endl;  // 7
    return 0;
}
