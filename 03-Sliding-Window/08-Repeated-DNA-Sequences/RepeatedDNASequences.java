/**
 * Repeated DNA Sequences
 * LeetCode: https://leetcode.com/problems/repeated-dna-sequences/
 * Time: O(n), Space: O(n)
 */

import java.util.*;

class RepeatedDNASequences {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<String> seen = new HashSet<>();
        Set<String> repeated = new HashSet<>();

        for (int i = 0; i <= s.length() - 10; i++) {
            String sequence = s.substring(i, i + 10);
            if (seen.contains(sequence)) {
                repeated.add(sequence);
            }
            seen.add(sequence);
        }

        return new ArrayList<>(repeated);
    }

    public static void main(String[] args) {
        RepeatedDNASequences solution = new RepeatedDNASequences();
        System.out.println(solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
        // ["AAAAACCCCC","CCCCCAAAAA"]
    }
}
