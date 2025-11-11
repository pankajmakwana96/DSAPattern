/**
 * Contains Duplicate II
 * Time: O(n), Space: O(min(n,k))
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class ContainsDuplicateII {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            if (window.count(nums[i])) {
                return true;
            }
            window.insert(nums[i]);
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};

int main() {
    ContainsDuplicateII solution;
    vector<int> test1 = {1, 2, 3, 1};
    cout << solution.containsNearbyDuplicate(test1, 3) << endl;  // 1 (true)
    return 0;
}
