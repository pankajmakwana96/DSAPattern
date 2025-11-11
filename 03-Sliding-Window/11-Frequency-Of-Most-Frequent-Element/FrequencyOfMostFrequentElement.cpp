/**
 * Frequency of the Most Frequent Element
 * Time: O(n log n), Space: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FrequencyOfMostFrequentElement {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, maxFreq = 1;
        long long sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            long long target = (long long)nums[right] * (right - left + 1);

            while (target - sum > k) {
                sum -= nums[left];
                left++;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};

int main() {
    FrequencyOfMostFrequentElement solution;
    vector<int> test = {1, 2, 4};
    cout << solution.maxFrequency(test, 5) << endl;  // 3
    return 0;
}
