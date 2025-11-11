# Reverse Words in a String

**LeetCode Link:** https://leetcode.com/problems/reverse-words-in-a-string/

**Difficulty:** Medium

**Pattern:** Two Pointers

## Problem Description

Given an input string `s`, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in `s` will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

**Note:**
- `s` may contain leading or trailing spaces or multiple spaces between two words.
- The returned string should only have a single space separating the words. Do not include any extra spaces.

**Example 1:**
```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

**Example 2:**
```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

**Example 3:**
```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space.
```

## Approaches

### Approach 1: Built-in Functions (Simple)

**Intuition:**
- Split string by spaces
- Filter out empty strings
- Reverse the array
- Join with single space

**Time Complexity:** O(n)
**Space Complexity:** O(n)

### Approach 2: Two Pointers - In-Place (Optimal for character arrays)

**Intuition:**
- Reverse the entire string
- Reverse each word individually
- Remove extra spaces

**Algorithm:**
1. Convert to character array (for in-place manipulation)
2. Reverse entire array
3. Reverse each word
4. Clean up extra spaces

**Time Complexity:** O(n)
**Space Complexity:** O(1) for true in-place (if input is char array), O(n) for immutable strings

### Approach 3: Manual Parsing with Two Pointers

**Intuition:**
- Use two pointers to identify word boundaries
- Build result from right to left

**Time Complexity:** O(n)
**Space Complexity:** O(n)

## Code Implementation

### Java Solution
See: `ReverseWordsInString.java`

### C++ Solution
See: `ReverseWordsInString.cpp`

## Key Takeaways

1. String reversal problems often benefit from two pointers technique
2. In-place string manipulation requires character array in Java (strings are immutable)
3. Handle edge cases: leading/trailing spaces, multiple spaces between words
4. Two-step reversal (reverse all, then reverse each word) is a classic technique
5. StringBuilder is efficient for string construction in Java

## Visual Example

```
Input: "the sky is blue"

Step 1: Reverse entire string
"eulb si yks eht"

Step 2: Reverse each word
"blue is sky the"

Result: "blue is sky the"
```

## Common Pitfalls

1. Not handling multiple spaces correctly
2. Not trimming leading/trailing spaces
3. Off-by-one errors when identifying word boundaries
4. Forgetting that strings are immutable in Java
