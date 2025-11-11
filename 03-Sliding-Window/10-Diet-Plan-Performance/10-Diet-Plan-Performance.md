# Diet Plan Performance

**LeetCode Link:** https://leetcode.com/problems/diet-plan-performance/

**Difficulty:** Easy

**Pattern:** Fixed Sliding Window

## Problem Description

A dieter consumes `calories[i]` calories on the i-th day. Given integers `k`, `lower`, and `upper`:
- If sum of calories in k consecutive days < lower, lose 1 point
- If sum of calories in k consecutive days > upper, gain 1 point
- Otherwise, no change

Return total points after all days.

**Example:**
```
Input: calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
Output: 0
```

## Approach: Fixed Sliding Window

Calculate sum for each window of size k, compare with lower/upper.

**Time:** O(n), **Space:** O(1)
