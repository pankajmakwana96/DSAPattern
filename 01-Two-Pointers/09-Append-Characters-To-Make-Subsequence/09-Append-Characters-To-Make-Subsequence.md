# Append Characters to String to Make Subsequence

**LeetCode Link:** https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

**Difficulty:** Medium

**Pattern:** Two Pointers

## Problem Description

You are given two strings `s` and `t` consisting only of lowercase English letters.

Return the minimum number of characters that need to be appended to the end of `s` so that `t` becomes a subsequence of `s`.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

**Example 1:**
```
Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
```

**Example 2:**
```
Input: s = "abcde", t = "a"
Output: 0
Explanation: t is already a subsequence of s ("abcde").
```

**Example 3:**
```
Input: s = "z", t = "abcde"
Output: 5
Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
Now, t is a subsequence of s ("zabcde").
```

## Approaches

### Approach: Two Pointers Matching (Optimal)

**Intuition:**
- Use two pointers to match characters from t in s
- Traverse s and try to match as many characters of t as possible in order
- The unmatched suffix of t needs to be appended to s

**Algorithm:**
1. Initialize i = 0 (pointer for s), j = 0 (pointer for t)
2. While i < s.length():
   - If s[i] == t[j]:
     - Match found, increment j
   - Always increment i (move forward in s)
3. Return t.length() - j (unmatched characters in t)

**Time Complexity:** O(n) where n is length of s
**Space Complexity:** O(1)

**Why this works:**
- We greedily match characters from t in s
- Since we traverse s left to right, we maintain the subsequence order
- Any character in t that we couldn't match must be appended

## Code Implementation

### Java Solution
See: `AppendCharactersToMakeSubsequence.java`

### C++ Solution
See: `AppendCharactersToMakeSubsequence.cpp`

## Key Takeaways

1. Subsequence matching can be done with two pointers in linear time
2. Greedy matching works because we only care about order, not position
3. The answer is simply the unmatched portion of the target string
4. One pointer traverses completely, other tracks progress

## Visual Example

```
s = "coaching", t = "coding"

i=0, j=0: s[0]='c', t[0]='c' → match, j=1
i=1, j=1: s[1]='o', t[1]='o' → match, j=2
i=2, j=2: s[2]='a', t[2]='d' → no match
i=3, j=2: s[3]='c', t[2]='d' → no match
i=4, j=2: s[4]='h', t[2]='d' → no match
i=5, j=2: s[5]='i', t[2]='d' → no match
i=6, j=2: s[6]='n', t[2]='d' → no match
i=7, j=2: s[7]='g', t[2]='d' → no match

j=2, t.length()=6
Need to append: 6-2 = 4 characters ("ding")
```

## Edge Cases

1. t is already a subsequence of s → return 0
2. No characters of t in s → return t.length()
3. s is empty → return t.length()
4. t is empty → return 0

## Common Pitfalls

1. Forgetting that it's a subsequence, not substring
2. Trying to match characters out of order
3. Not handling edge cases (empty strings)
4. Incrementing wrong pointer
