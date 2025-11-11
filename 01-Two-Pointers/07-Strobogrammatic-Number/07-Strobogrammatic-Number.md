# Strobogrammatic Number

**LeetCode Link:** https://leetcode.com/problems/strobogrammatic-number/ (Premium)

**Difficulty:** Easy

**Pattern:** Two Pointers

## Problem Description

Given a string `num` which represents an integer, return `true` if `num` is a strobogrammatic number.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

**Example 1:**
```
Input: num = "69"
Output: true
```

**Example 2:**
```
Input: num = "88"
Output: true
```

**Example 3:**
```
Input: num = "962"
Output: false
```

**Example 4:**
```
Input: num = "1"
Output: true
```

## Valid Strobogrammatic Pairs

When rotated 180 degrees:
- 0 → 0
- 1 → 1
- 6 → 9
- 8 → 8
- 9 → 6

All other digits (2, 3, 4, 5, 7) are invalid.

## Approaches

### Approach: Two Pointers (Optimal)

**Intuition:**
- Use two pointers from both ends
- Check if each pair forms a valid strobogrammatic pair
- For middle element (odd length), it must be 0, 1, or 8

**Algorithm:**
1. Create a map of valid pairs: 0-0, 1-1, 6-9, 8-8, 9-6
2. Use two pointers: left = 0, right = n-1
3. While left <= right:
   - Check if num[left] and num[right] form a valid pair
   - Move pointers toward center
4. Return true if all pairs are valid

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Code Implementation

See: `StrobogrammaticNumber.java` and `StrobogrammaticNumber.cpp`

## Key Takeaways

1. Two pointers from both ends for symmetry checking
2. Use hashmap/array for quick pair lookups
3. Handle middle element in odd-length numbers
4. Only 5 valid digits: 0, 1, 6, 8, 9
