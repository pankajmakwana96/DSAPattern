# Subarrays with K Different Integers

**LeetCode Link:** https://leetcode.com/problems/subarrays-with-k-different-integers/

**Difficulty:** Hard

**Pattern:** Sliding Window (Exactly K = At Most K - At Most K-1)

## Problem Description

Given an integer array `nums` and an integer `k`, return the number of good subarrays of `nums`. A good array is an array where the number of different integers in that array is exactly `k`.

**Example:**
```
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
```

## Approach: AtMost(K) - AtMost(K-1)

Exactly K = AtMost K - AtMost (K-1)

**Time:** O(n), **Space:** O(k)
