# Valid Word Abbreviation

**LeetCode Link:** https://leetcode.com/problems/valid-word-abbreviation/ (Premium)

**Difficulty:** Easy

**Pattern:** Two Pointers

## Problem Description

A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):
- "s10n" ("s ubstitutio n")
- "sub4u4" ("sub stit u tion")
- "12" ("substitution")
- "su3i1u2on" ("su bst i t u ti on")
- "substitution" (no substrings replaced)

The following are not valid abbreviations:
- "s55n" (both "5"s are adjacent)
- "s010n" (has leading zeros)
- "s0ubstitution" (replaces an empty string)

Given a string `word` and an abbreviation `abbr`, return whether the abbreviation is valid for the word.

**Example 1:**
```
Input: word = "internationalization", abbr = "i12iz4n"
Output: true
Explanation: The word "internationalization" can be abbreviated as "i12iz4n"
("i nternational iz atio n").
```

**Example 2:**
```
Input: word = "apple", abbr = "a2e"
Output: false
Explanation: The word "apple" cannot be abbreviated as "a2e".
```

## Approaches

### Approach 1: Two Pointers (Optimal)

**Intuition:**
- Use two pointers: one for word, one for abbreviation
- When encountering a digit in abbr, calculate the full number and skip that many characters in word
- When encountering a letter in abbr, it must match the current character in word
- Check for leading zeros in numbers

**Algorithm:**
1. Initialize two pointers: i for word, j for abbr
2. While both pointers are within bounds:
   - If abbr[j] is a digit:
     - Check for leading zero (invalid)
     - Calculate the complete number
     - Skip that many characters in word
   - Else (abbr[j] is a letter):
     - Match with word[i]
     - Move both pointers
3. Both pointers should reach the end for valid abbreviation

**Time Complexity:** O(n + m) where n = word length, m = abbr length
**Space Complexity:** O(1)

## Code Implementation

### Java Solution
See: `ValidWordAbbreviation.java`

### C++ Solution
See: `ValidWordAbbreviation.cpp`

## Key Takeaways

1. Two pointers technique for matching patterns
2. Handle number parsing carefully (multi-digit numbers)
3. Check for leading zeros in abbreviation numbers
4. Edge cases: empty string, single character, all numbers

## Common Pitfalls

1. Not checking for leading zeros
2. Integer overflow when parsing large numbers
3. Not handling multi-digit numbers correctly
4. Off-by-one errors in pointer movements
