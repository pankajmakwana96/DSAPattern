# Count Subarrays With Score Less Than K

**LeetCode Link:** https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

**Difficulty:** Medium

**Pattern:** Sliding Window (Count)

## Problem Description

The score of an array is defined as the product of its sum and its length. Given a positive integer array `nums` and an integer `k`, return the number of non-empty subarrays where: sum(subarray) * length(subarray) < k

**Example:**
```
Input: nums = [2,1,4,3,5], k = 10
Output: 6
```

## Approach: Sliding Window

For each valid window ending at right, all subarrays ending at right within window are valid.

**Time:** O(n), **Space:** O(1)
