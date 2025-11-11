/**
 * Valid Word Abbreviation - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/valid-word-abbreviation/ (Premium)
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(1)
 */

class ValidWordAbbreviation {

    public boolean validWordAbbreviation(String word, String abbr) {
        int i = 0; // Pointer for word
        int j = 0; // Pointer for abbr

        while (i < word.length() && j < abbr.length()) {
            char c = abbr.charAt(j);

            if (Character.isDigit(c)) {
                // Check for leading zero
                if (c == '0') {
                    return false;
                }

                // Calculate the complete number
                int num = 0;
                while (j < abbr.length() && Character.isDigit(abbr.charAt(j))) {
                    num = num * 10 + (abbr.charAt(j) - '0');
                    j++;
                }

                // Skip 'num' characters in word
                i += num;
            } else {
                // Must match the character
                if (word.charAt(i) != c) {
                    return false;
                }
                i++;
                j++;
            }
        }

        // Both pointers should reach the end
        return i == word.length() && j == abbr.length();
    }

    // Test cases
    public static void main(String[] args) {
        ValidWordAbbreviation solution = new ValidWordAbbreviation();

        // Test case 1
        System.out.println("Test 1: " +
            solution.validWordAbbreviation("internationalization", "i12iz4n")); // true

        // Test case 2
        System.out.println("Test 2: " +
            solution.validWordAbbreviation("apple", "a2e")); // false

        // Test case 3: Leading zero
        System.out.println("Test 3: " +
            solution.validWordAbbreviation("substitution", "s010n")); // false

        // Test case 4: Complete match
        System.out.println("Test 4: " +
            solution.validWordAbbreviation("word", "word")); // true

        // Test case 5: All numbers
        System.out.println("Test 5: " +
            solution.validWordAbbreviation("apple", "5")); // true

        // Test case 6: Number too large
        System.out.println("Test 6: " +
            solution.validWordAbbreviation("apple", "a3e")); // false

        // Test case 7
        System.out.println("Test 7: " +
            solution.validWordAbbreviation("internationalization", "i5a11o1")); // true

        // Test case 8: Adjacent numbers (valid)
        System.out.println("Test 8: " +
            solution.validWordAbbreviation("hi", "1")); // false

        // Test case 9
        System.out.println("Test 9: " +
            solution.validWordAbbreviation("hi", "2i")); // false
    }
}
