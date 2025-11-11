# Minimum Number of Moves to Make Palindrome

**LeetCode Link:** https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/

**Difficulty:** Hard

**Pattern:** Two Pointers + Greedy

## Problem Description

You are given a string `s` consisting only of lowercase English letters.

In one move, you can select any two adjacent characters of `s` and swap them.

Return the minimum number of moves needed to make `s` a palindrome.

**Note:** The input will be generated such that `s` can always be converted to a palindrome.

**Example 1:**
```
Input: s = "aabb"
Output: 2
Explanation:
We can obtain two palindromes from s, "abba" and "baab".
- We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
- We can obtain "baab" from s in 2 moves: "aabb" -> "baab".
Thus, the minimum number of moves needed to make s a palindrome is 2.
```

**Example 2:**
```
Input: s = "letelt"
Output: 2
Explanation:
One of the palindromes we can obtain from s in 2 moves is "lettel".
One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
```

## Approach: Greedy Two Pointers

**Intuition:**
- Use two pointers from both ends
- For each position, find the matching character and swap it to the correct position
- Count the number of swaps
- Special case: odd-length strings with a unique middle character

**Key Observations:**
1. We can greedily match characters from both ends
2. For each left position, find its match on the right
3. Swap the match to the correct position counting moves
4. If a character has no pair, it must be the middle character (odd length)

**Algorithm:**
1. Convert string to character array for easier swapping
2. Use left and right pointers
3. While left < right:
   - Find matching character for s[left] starting from right
   - If found at k:
     - Swap from k to right position (count swaps)
     - Move both pointers inward
   - If not found (unique character):
     - It's the middle character
     - Swap to middle position
4. Return total swap count

**Time Complexity:** O(n²) - For each position, may scan and swap
**Space Complexity:** O(n) - Character array

## Pseudocode

```java
public int minMovesToMakePalindrome(String s) {
    char[] chars = s.toCharArray();
    int moves = 0;
    int left = 0, right = chars.length - 1;

    while (left < right) {
        int k = right;

        // Find matching character for chars[left]
        while (k > left && chars[k] != chars[left]) {
            k--;
        }

        if (k == left) {
            // No match found - middle character
            // Swap to center
            swap(chars, left, left + 1);
            moves++;
        } else {
            // Match found at k, bring it to right position
            while (k < right) {
                swap(chars, k, k + 1);
                k++;
                moves++;
            }
            left++;
            right--;
        }
    }

    return moves;
}
```

## Visual Example

```
s = "aabb"

Initial: a a b b
         L     R

Step 1: Find match for 'a' at L
  Found at R-1, need to move to R
  Swap: a a b b -> a b a b -> a b b a
  Moves = 2
  L++, R--

Now: a b b a
       L R

Done (L >= R)

Total moves = 2
```

## Key Takeaways

1. Greedy matching from both ends works
2. Handle middle character specially in odd-length strings
3. Count adjacent swaps to bring character to position
4. Each swap is one move
5. Problem guarantees a solution exists

## Common Pitfalls

1. Not handling the middle character case
2. Not counting swaps correctly
3. Infinite loop if not moving pointers properly
4. Off-by-one errors in swap counting
5. Not converting to char array in languages with immutable strings
