/**
 * Repeated DNA Sequences
 * Time: O(n), Space: O(n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class RepeatedDNASequences {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen, repeated;

        for (int i = 0; i <= (int)s.length() - 10; i++) {
            string sequence = s.substr(i, 10);
            if (seen.count(sequence)) {
                repeated.insert(sequence);
            }
            seen.insert(sequence);
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};

int main() {
    RepeatedDNASequences solution;
    auto result = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (const auto& seq : result) {
        cout << seq << " ";
    }
    cout << endl;
    return 0;
}
