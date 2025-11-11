/**
 * Reverse Words in a String - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class ReverseWordsInString {

    // Approach 1: Using Built-in Functions (Most Practical)
    public String reverseWords(String s) {
        // Trim and split by one or more spaces
        String[] words = s.trim().split("\\s+");

        // Reverse the array
        int left = 0, right = words.length - 1;
        while (left < right) {
            String temp = words[left];
            words[left] = words[right];
            words[right] = temp;
            left++;
            right--;
        }

        // Join with single space
        return String.join(" ", words);
    }

    // Approach 2: Using StringBuilder (More Efficient)
    public String reverseWords2(String s) {
        // Trim the string
        s = s.trim();

        StringBuilder result = new StringBuilder();
        int end = s.length();

        // Iterate from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            // Skip spaces
            if (s.charAt(i) == ' ') {
                if (i + 1 < end) {
                    // Extract word and add to result
                    if (result.length() > 0) {
                        result.append(' ');
                    }
                    result.append(s.substring(i + 1, end));
                }
                // Skip multiple spaces
                while (i >= 0 && s.charAt(i) == ' ') {
                    i--;
                }
                end = i + 1;
                i++; // Compensate for the loop decrement
            }
        }

        // Add the first word
        if (end > 0) {
            if (result.length() > 0) {
                result.append(' ');
            }
            result.append(s.substring(0, end));
        }

        return result.toString();
    }

    // Approach 3: Two Pointers with Character Array
    public String reverseWords3(String s) {
        // Convert to character array and clean spaces
        char[] chars = cleanSpaces(s.toCharArray());

        // Reverse the entire array
        reverse(chars, 0, chars.length - 1);

        // Reverse each word
        reverseEachWord(chars);

        return new String(chars);
    }

    // Helper: Clean extra spaces
    private char[] cleanSpaces(char[] chars) {
        int n = chars.length;
        int i = 0, j = 0;

        while (j < n) {
            // Skip leading spaces
            while (j < n && chars[j] == ' ') j++;

            // Copy word characters
            while (j < n && chars[j] != ' ') {
                chars[i++] = chars[j++];
            }

            // Skip trailing spaces
            while (j < n && chars[j] == ' ') j++;

            // Add single space between words
            if (j < n) {
                chars[i++] = ' ';
            }
        }

        // Create array with cleaned size
        char[] result = new char[i];
        System.arraycopy(chars, 0, result, 0, i);
        return result;
    }

    // Helper: Reverse array section
    private void reverse(char[] chars, int left, int right) {
        while (left < right) {
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
    }

    // Helper: Reverse each word in the array
    private void reverseEachWord(char[] chars) {
        int start = 0;
        for (int i = 0; i <= chars.length; i++) {
            if (i == chars.length || chars[i] == ' ') {
                reverse(chars, start, i - 1);
                start = i + 1;
            }
        }
    }

    // Test cases
    public static void main(String[] args) {
        ReverseWordsInString solution = new ReverseWordsInString();

        // Test case 1
        String test1 = "the sky is blue";
        System.out.println("Test 1: \"" + solution.reverseWords(test1) + "\"");
        // Expected: "blue is sky the"

        // Test case 2
        String test2 = "  hello world  ";
        System.out.println("Test 2: \"" + solution.reverseWords(test2) + "\"");
        // Expected: "world hello"

        // Test case 3
        String test3 = "a good   example";
        System.out.println("Test 3: \"" + solution.reverseWords(test3) + "\"");
        // Expected: "example good a"

        // Test case 4
        String test4 = "  Bob    Loves  Alice   ";
        System.out.println("Test 4: \"" + solution.reverseWords(test4) + "\"");
        // Expected: "Alice Loves Bob"

        // Test case 5
        String test5 = "single";
        System.out.println("Test 5: \"" + solution.reverseWords(test5) + "\"");
        // Expected: "single"
    }
}
