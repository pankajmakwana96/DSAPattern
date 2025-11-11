/**
 * Reverse String - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/reverse-string/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ReverseString {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Swap characters
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    // Alternative: Using STL reverse
    void reverseString2(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

void printVector(const vector<char>& s) {
    cout << "[";
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if (i < s.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    ReverseString solution;

    vector<char> test1 = {'h','e','l','l','o'};
    solution.reverseString(test1);
    printVector(test1); // [o, l, l, e, h]

    vector<char> test2 = {'H','a','n','n','a','h'};
    solution.reverseString(test2);
    printVector(test2); // [h, a, n, n, a, H]

    vector<char> test3 = {'A'};
    solution.reverseString(test3);
    printVector(test3); // [A]

    vector<char> test4 = {'a','b'};
    solution.reverseString(test4);
    printVector(test4); // [b, a]

    return 0;
}
