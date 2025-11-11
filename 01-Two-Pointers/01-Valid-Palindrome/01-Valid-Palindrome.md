# Valid Palindrome

**LeetCode Link:** https://leetcode.com/problems/valid-palindrome/

**Difficulty:** Easy

**Pattern:** Two Pointers

## Problem Description

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

**Example 1:**
```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

**Example 2:**
```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

## Approaches

### Approach 1: Two Pointers (Optimal)

**Intuition:**
- Use two pointers, one starting from the beginning and one from the end
- Skip non-alphanumeric characters
- Compare characters at both pointers (case-insensitive)
- Move pointers towards each other
- If all comparisons match, it's a palindrome

**Algorithm:**
1. Initialize left pointer at start (0) and right pointer at end (n-1)
2. While left < right:
   - Skip non-alphanumeric characters from left
   - Skip non-alphanumeric characters from right
   - Compare characters (convert to lowercase)
   - If they don't match, return false
   - Move both pointers
3. Return true if all characters matched

**Time Complexity:** O(n) - Single pass through the string
**Space Complexity:** O(1) - Only using two pointers

### Approach 2: Filter and Compare (Alternative)

**Intuition:**
- First, filter the string to keep only alphanumeric characters and convert to lowercase
- Then compare the filtered string with its reverse

**Time Complexity:** O(n)
**Space Complexity:** O(n) - For storing filtered string

**Note:** Approach 1 is preferred as it uses O(1) space.

## Code Implementation

### Java Solution
See: `ValidPalindrome.java`

### C++ Solution
See: `ValidPalindrome.cpp`

## Key Takeaways

1. Two pointers technique is efficient for palindrome problems
2. In-place comparison saves space
3. Remember to handle edge cases: special characters, case sensitivity
4. Character validation can be done with built-in functions: `isalnum()`, `tolower()`
