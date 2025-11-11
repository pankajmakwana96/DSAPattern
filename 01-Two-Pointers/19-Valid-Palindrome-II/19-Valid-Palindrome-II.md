# Valid Palindrome II

**LeetCode Link:** https://leetcode.com/problems/valid-palindrome-ii/

**Difficulty:** Easy

**Pattern:** Two Pointers

## Problem Description

Given a string `s`, return `true` if the `s` can be palindrome after deleting at most one character from it.

**Example 1:**
```
Input: s = "aba"
Output: true
```

**Example 2:**
```
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
```

**Example 3:**
```
Input: s = "abc"
Output: false
```

## Approaches

### Approach: Two Pointers with One Skip (Optimal)

**Intuition:**
- Use normal palindrome checking with two pointers
- When mismatch is found, try skipping either left or right character
- If either skip results in a palindrome, return true
- Otherwise return false

**Key Insight:**
- At most one deletion means we get ONE chance to skip
- When we find a mismatch, we must skip either the left or right character
- We cannot skip both or skip multiple characters

**Algorithm:**
1. Use two pointers: left = 0, right = n-1
2. While left < right:
   - If s[left] == s[right]: move both pointers inward
   - If s[left] != s[right]:
     - Try skipping left: check if s[left+1...right] is palindrome
     - Try skipping right: check if s[left...right-1] is palindrome
     - Return true if either is palindrome
3. If no mismatch found, it's already a palindrome, return true

**Helper Function:**
```java
boolean isPalindrome(String s, int left, int right) {
    while (left < right) {
        if (s.charAt(left) != s.charAt(right)) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
```

**Time Complexity:** O(n) - At most, we check the string 3 times (original + two skips)
**Space Complexity:** O(1) - Only using pointers

## Code Implementation

### Java Solution
See: `ValidPalindromeII.java`

### C++ Solution
See: `ValidPalindromeII.cpp`

## Key Takeaways

1. Extends basic palindrome checking with one deletion allowance
2. When mismatch found, we have exactly two choices: skip left or skip right
3. Helper function for palindrome checking keeps code clean
4. We only get ONE skip, so after finding mismatch, we check both possibilities
5. This is a greedy approach - we check normal palindrome first

## Visual Example

```
Example 1: s = "abca"

Step 1: left=0, right=3
        'a' == 'a' ✓, move inward

Step 2: left=1, right=2
        'b' != 'c' ✗ MISMATCH!

        Option 1: Skip left ('b')
        Check "ca" → not palindrome

        Option 2: Skip right ('c')
        Check "ab" → not palindrome... wait, actually check "bc"
        Actually we check remaining: s[1...2] after skipping s[3]

Let me reconsider:
        left=1 ('b'), right=2 ('c')

        Option 1: Skip left, check s[2...2] = "c" → palindrome ✓
        OR
        Option 2: Skip right, check s[1...1] = "b" → palindrome ✓

Result: true (we can delete 'b' or 'c')
```

```
Example 2: s = "abc"

Step 1: left=0, right=2
        'a' != 'c' ✗ MISMATCH!

        Option 1: Skip left ('a')
        Check "bc" → not palindrome

        Option 2: Skip right ('c')
        Check "ab" → not palindrome

Result: false
```

## Detailed Example Walkthrough

**Input:** "racecar"
- Already a palindrome
- No mismatch found
- Return true

**Input:** "raceacar"
- left=0, right=7: 'r' == 'r' ✓
- left=1, right=6: 'a' == 'a' ✓
- left=2, right=5: 'c' == 'c' ✓
- left=3, right=4: 'e' != 'a' ✗
  - Skip left: Check "acar" from position 4-7? No, check s[4...4] = "a" → palindrome ✓
- Return true

**Input:** "abcdef"
- left=0, right=5: 'a' != 'f' ✗
  - Skip left: Check "bcdef" → not palindrome
  - Skip right: Check "abcde" → not palindrome
- Return false

## Edge Cases

1. Already a palindrome: "racecar" → true
2. Empty or single character: "" or "a" → true
3. Two characters same: "aa" → true
4. Two characters different: "ab" → true (delete one)
5. All same characters: "aaaa" → true
6. No valid deletion: "abc" → false

## Common Pitfalls

1. Trying to delete more than one character
2. Not checking both skip options (left and right)
3. Off-by-one errors in substring indices
4. Not handling the case where string is already a palindrome
5. Modifying the original string instead of just checking

## Variations

This problem teaches a pattern useful for:
- "At most k deletions" problems
- "At most k replacements" problems
- Palindrome with modifications
- String matching with errors

## Comparison with Valid Palindrome I

**Valid Palindrome I:**
- Ignore non-alphanumeric characters
- Case insensitive
- No deletions allowed

**Valid Palindrome II:**
- Consider all characters
- Case sensitive
- At most one deletion allowed

## Follow-up Questions

1. What if we can delete at most k characters? (Requires DP or recursion with memoization)
2. What if we can replace at most one character? (Similar approach)
3. What if we can insert at most one character? (Check if one substring of other is palindrome)
