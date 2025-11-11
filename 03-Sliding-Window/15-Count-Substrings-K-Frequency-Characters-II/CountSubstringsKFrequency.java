/**
 * Count Substrings With K-Frequency Characters II
 * Time: O(n), Space: O(1)
 */

class CountSubstringsKFrequency {
    public long numberOfSubstrings(String s, int k) {
        long count = 0;
        int n = s.length();

        for (int left = 0; left < n; left++) {
            int[] freq = new int[26];
            for (int right = left; right < n; right++) {
                freq[s.charAt(right) - 'a']++;

                boolean hasKFreq = false;
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

    public static void main(String[] args) {
        CountSubstringsKFrequency solution = new CountSubstringsKFrequency();
        System.out.println(solution.numberOfSubstrings("abacb", 2));  // 10
        System.out.println(solution.numberOfSubstrings("abcde", 1));  // 15
    }
}
