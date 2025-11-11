/**
 * Count Substrings With K-Frequency Characters II
 * Time: O(n²), Space: O(1)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CountSubstringsKFrequency {
public:
    long long numberOfSubstrings(string s, int k) {
        long long count = 0;
        int n = s.length();

        for (int left = 0; left < n; left++) {
            vector<int> freq(26, 0);
            for (int right = left; right < n; right++) {
                freq[s[right] - 'a']++;

                bool hasKFreq = false;
                for (int f : freq) {
                    if (f >= k) {
                        hasKFreq = true;
                        break;
                    }
                }

                if (hasKFreq) {
                    count += n - right;
                    break;
                }
            }
        }

        return count;
    }
};

int main() {
    CountSubstringsKFrequency solution;
    cout << solution.numberOfSubstrings("abacb", 2) << endl;  // 10
    cout << solution.numberOfSubstrings("abcde", 1) << endl;  // 15
    return 0;
}
