# Count Substrings With K-Frequency Characters II

**LeetCode Link:** https://leetcode.com/problems/count-substrings-with-k-frequency-characters-ii/

**Difficulty:** Hard

**Pattern:** Sliding Window (Count)

## Problem Description

Given a string `s` and an integer `k`, return the total number of substrings of `s` where at least one character appears at least `k` times.

**Example:**
```
Input: s = "abacb", k = 2
Output: 10
```

## Approach: Sliding Window with Frequency

Count subarrays where max frequency >= k

**Time:** O(n), **Space:** O(26) = O(1)
