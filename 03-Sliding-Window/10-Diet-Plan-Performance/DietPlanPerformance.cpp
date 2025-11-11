/**
 * Diet Plan Performance
 * Time: O(n), Space: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class DietPlanPerformance {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int points = 0, sum = 0;

        for (int i = 0; i < k; i++) {
            sum += calories[i];
        }

        if (sum < lower) points--;
        else if (sum > upper) points++;

        for (int i = k; i < calories.size(); i++) {
            sum = sum - calories[i - k] + calories[i];
            if (sum < lower) points--;
            else if (sum > upper) points++;
        }

        return points;
    }
};

int main() {
    DietPlanPerformance solution;
    vector<int> test = {1, 2, 3, 4, 5};
    cout << solution.dietPlanPerformance(test, 1, 3, 3) << endl;  // 0
    return 0;
}
