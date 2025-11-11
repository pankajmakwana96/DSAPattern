/**
 * Minimum Window Subsequence
 * Time: O(m * n), Space: O(1)
 */

class MinimumWindowSubsequence {
    public String minWindow(String s, String t) {
        int m = s.length(), n = t.length();
        int start = -1, minLen = Integer.MAX_VALUE;

        for (int i = 0; i < m; i++) {
            if (s.charAt(i) == t.charAt(0)) {
                int sIdx = i, tIdx = 0;

                // Forward: match all of t
                while (sIdx < m && tIdx < n) {
                    if (s.charAt(sIdx) == t.charAt(tIdx)) {
                        tIdx++;
                    }
                    sIdx++;
                }

                if (tIdx == n) {
                    // Backward: minimize window
                    int end = sIdx - 1;
                    tIdx--;
                    sIdx--;
                    while (tIdx >= 0) {
                        if (s.charAt(sIdx) == t.charAt(tIdx)) {
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

        return start == -1 ? "" : s.substring(start, start + minLen);
    }

    public static void main(String[] args) {
        MinimumWindowSubsequence solution = new MinimumWindowSubsequence();
        System.out.println(solution.minWindow("abcdebdde", "bde"));  // "bcde"
    }
}
