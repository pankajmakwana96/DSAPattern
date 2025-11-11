/**
 * Minimum Window Subsequence
 * Time: O(m * n), Space: O(1)
 */

#include <iostream>
#include <string>
#include <climits>

using namespace std;

class MinimumWindowSubsequence {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        int start = -1, minLen = INT_MAX;

        for (int i = 0; i < m; i++) {
            if (s[i] == t[0]) {
                int sIdx = i, tIdx = 0;

                while (sIdx < m && tIdx < n) {
                    if (s[sIdx] == t[tIdx]) {
                        tIdx++;
                    }
                    sIdx++;
                }

                if (tIdx == n) {
                    int end = sIdx - 1;
                    tIdx--;
                    sIdx--;
                    while (tIdx >= 0) {
                        if (s[sIdx] == t[tIdx]) {
                            tIdx--;
                        }
                        sIdx--;
                    }
                    sIdx++;

                    if (end - sIdx + 1 < minLen) {
                        minLen = end - sIdx + 1;
                        start = sIdx;
                    }
                }
            }
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};

int main() {
    MinimumWindowSubsequence solution;
    cout << solution.minWindow("abcdebdde", "bde") << endl;  // "bcde"
    return 0;
}
