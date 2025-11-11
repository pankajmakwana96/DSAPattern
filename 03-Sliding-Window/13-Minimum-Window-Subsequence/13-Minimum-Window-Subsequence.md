# Minimum Window Subsequence

**LeetCode Link:** https://leetcode.com/problems/minimum-window-subsequence/

**Difficulty:** Hard

**Pattern:** Two Pointers (Advanced)

## Problem Description

Given strings `s` and `t`, find the minimum (contiguous) substring `w` of `s`, such that `t` is a subsequence of `w`. If there is no such window, return empty string.

**Example:**
```
Input: s = "abcdebdde", t = "bde"
Output: "bcde"
```

## Approach: Two Pointers with Forward/Backward

1. Forward scan to match all chars of t
2. Backward scan to minimize window
3. Track minimum window found

**Time:** O(m * n), **Space:** O(1)
