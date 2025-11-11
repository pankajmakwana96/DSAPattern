# Find the Lexicographically Largest String From the Box II

**LeetCode Link:** https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-ii/

**Difficulty:** Hard

**Pattern:** Two Pointers + Greedy

## Problem Description

You are given a string `word`, and an integer `numFriends`.

Alice is organizing a game for her `numFriends` friends. There are multiple rounds in the game, where in each round:
- `word` is split into `numFriends` non-empty strings, such that no previous split has been made before.
- All the split words are put into a box.

Find the lexicographically largest string from all the strings put in the box after all the rounds.

**Constraints:**
- `1 <= word.length <= 5 * 10^3`
- `word` consists only of lowercase English letters
- `1 <= numFriends <= word.length`

## Approach: Greedy with Two Pointers

**Intuition:**
- We want to maximize the lexicographic value
- Greedily select the largest possible prefix at each step
- Use two pointers to track current position and search for best substring

**Key Observations:**
1. To get lexicographically largest, we want largest characters early
2. Once we pick a starting point, we need to check all possible endpoints
3. Compare substrings and track the maximum
4. Need to consider all possible ways to split the string

**Algorithm:**
1. Generate all possible splits of the string into numFriends parts
2. For each split, extract all substrings
3. Track the lexicographically largest substring seen
4. Use greedy approach: at each position, try to maximize

**Time Complexity:** O(n²) or O(n³) depending on implementation
**Space Complexity:** O(n)

## Simplified Approach

If we're looking for the largest substring without complex splitting constraints:

```java
public String largestSubstring(String word) {
    String maxStr = "";

    // Try all possible substrings
    for (int i = 0; i < word.length(); i++) {
        for (int j = i + 1; j <= word.length(); j++) {
            String substr = word.substring(i, j);
            if (substr.compareTo(maxStr) > 0) {
                maxStr = substr;
            }
        }
    }

    return maxStr;
}
```

## Key Takeaways

1. Greedy approach for lexicographic problems
2. Need to consider all valid splits
3. String comparison in Java: use compareTo()
4. Two pointers help explore all substrings
5. May need dynamic programming for complex constraints

## Common Pitfalls

1. Not considering all possible splits
2. Incorrect string comparison
3. Missing edge cases (single character, entire string)
4. Time limit exceeded with brute force
5. Not handling empty splits correctly

**Note:** This is a complex problem that may require combination of multiple techniques including DP, greedy, and two pointers. The exact approach depends on the specific constraints and requirements.
