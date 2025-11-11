# Contains Duplicate II

**LeetCode Link:** https://leetcode.com/problems/contains-duplicate-ii/

**Difficulty:** Easy

**Pattern:** Fixed Sliding Window

## Problem Description

Given an integer array `nums` and an integer `k`, return true if there are two distinct indices `i` and `j` in the array such that `nums[i] == nums[j]` and `abs(i - j) <= k`.

**Example 1:**
```
Input: nums = [1,2,3,1], k = 3
Output: true
```

**Example 2:**
```
Input: nums = [1,0,1,1], k = 1
Output: true
```

## Approach: Sliding Window with HashSet

Maintain window of size k+1, check for duplicates in window.

**Time:** O(n), **Space:** O(min(n,k))
