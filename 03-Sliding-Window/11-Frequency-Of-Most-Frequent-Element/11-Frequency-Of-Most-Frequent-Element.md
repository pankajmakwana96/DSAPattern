# Frequency of the Most Frequent Element

**LeetCode Link:** https://leetcode.com/problems/frequency-of-the-most-frequent-element/

**Difficulty:** Medium

**Pattern:** Sliding Window with Sorting

## Problem Description

The frequency of an element is the number of times it occurs in an array. You are given an integer array `nums` and an integer `k`. In one operation, you can choose an index and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most `k` operations.

**Example:**
```
Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment first element three times and second element two times to make nums = [4,4,4].
```

## Approach: Sort + Sliding Window

1. Sort array
2. Use sliding window to track elements we can make equal
3. Cost to make all equal to rightmost = sum needed - current sum
4. If cost > k, shrink window

**Time:** O(n log n), **Space:** O(1)
