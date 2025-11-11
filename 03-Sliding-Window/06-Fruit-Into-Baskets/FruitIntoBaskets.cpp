/**
 * Fruit Into Baskets
 * LeetCode: https://leetcode.com/problems/fruit-into-baskets/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class FruitIntoBaskets {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;

            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    FruitIntoBaskets solution;

    vector<int> test1 = {1, 2, 1};
    cout << "Test 1: " << solution.totalFruit(test1) << endl;  // 3

    vector<int> test2 = {0, 1, 2, 2};
    cout << "Test 2: " << solution.totalFruit(test2) << endl;  // 3

    vector<int> test3 = {1, 2, 3, 2, 2};
    cout << "Test 3: " << solution.totalFruit(test3) << endl;  // 4

    vector<int> test4 = {1, 1, 1, 1};
    cout << "Test 4: " << solution.totalFruit(test4) << endl;  // 4

    return 0;
}
