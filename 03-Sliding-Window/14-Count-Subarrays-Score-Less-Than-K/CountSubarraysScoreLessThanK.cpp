/**
 * Count Subarrays With Score Less Than K
 * Time: O(n), Space: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class CountSubarraysScoreLessThanK {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0, sum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
};

int main() {
    CountSubarraysScoreLessThanK solution;
    vector<int> test = {2, 1, 4, 3, 5};
    cout << solution.countSubarrays(test, 10) << endl;  // 6
    return 0;
}
