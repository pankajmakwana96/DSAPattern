# Longest Repeating Character Replacement

**LeetCode Link:** https://leetcode.com/problems/longest-repeating-character-replacement/

**Difficulty:** Medium

**Pattern:** Sliding Window with Frequency Count

## Problem Description

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

**Example 1:**
```
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
```

**Example 2:**
```
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA". The substring "BBBB" has the longest repeating letters, which is 4.
```

## Approach: Sliding Window with Max Frequency

**Intuition:**
- Window is valid if: windowSize - maxFreq <= k
- maxFreq = most frequent character in current window
- Characters to change = windowSize - maxFreq
- If changes needed > k, shrink window

**Algorithm:**
1. Track frequency of each character in window
2. Track max frequency in current window
3. If windowSize - maxFreq > k, shrink from left
4. Update maximum window size

**Time Complexity:** O(n)
**Space Complexity:** O(26) = O(1)

## Visual Example

```
s = "AABABBA", k = 1

Window: "AA" → size=2, maxFreq=2, changes=0 ✓
Window: "AAB" → size=3, maxFreq=2, changes=1 ✓
Window: "AABA" → size=4, maxFreq=3, changes=1 ✓
Window: "AABAB" → size=5, maxFreq=3, changes=2 ✗ (> k)
        Shrink: "ABAB" → size=4, maxFreq=2, changes=2 ✗
        Shrink: "BAB" → size=3, maxFreq=2, changes=1 ✓
Window: "BABB" → size=4, maxFreq=3, changes=1 ✓ (maxLen=4)
Window: "BABBA" → size=5, maxFreq=3, changes=2 ✗

Result: 4
```

## Key Formula

**Valid Window:** `windowSize - maxFrequency <= k`

Where:
- windowSize = right - left + 1
- maxFrequency = count of most frequent char in window
- k = allowed replacements

## Code Implementation

See: `LongestRepeatingCharacterReplacement.java` and `LongestRepeatingCharacterReplacement.cpp`
