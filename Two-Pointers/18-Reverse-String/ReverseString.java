/**
 * Reverse String - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/reverse-string/
 *
 * Write a function that reverses a string. The input string is given as an array
 * of characters s. You must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

import java.util.Arrays;

class ReverseString {

    // Two Pointers from Both Ends
    public void reverseString(char[] s) {
        int left = 0;
        int right = s.length - 1;

        while (left < right) {
            // Swap characters
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }
    }

    // Alternative: Using XOR swap (bit manipulation)
    public void reverseString2(char[] s) {
        int left = 0;
        int right = s.length - 1;

        while (left < right) {
            // XOR swap (no temp variable needed)
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];

            left++;
            right--;
        }
    }

    // Test cases
    public static void main(String[] args) {
        ReverseString solution = new ReverseString();

        char[] test1 = {'h','e','l','l','o'};
        solution.reverseString(test1);
        System.out.println(Arrays.toString(test1)); // [o, l, l, e, h]

        char[] test2 = {'H','a','n','n','a','h'};
        solution.reverseString(test2);
        System.out.println(Arrays.toString(test2)); // [h, a, n, n, a, H]

        char[] test3 = {'A'};
        solution.reverseString(test3);
        System.out.println(Arrays.toString(test3)); // [A]

        char[] test4 = {'a','b'};
        solution.reverseString(test4);
        System.out.println(Arrays.toString(test4)); // [b, a]
    }
}
