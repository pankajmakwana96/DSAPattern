# Sort Colors

**LeetCode Link:** https://leetcode.com/problems/sort-colors/

**Difficulty:** Medium

**Pattern:** Two Pointers (Dutch National Flag)

## Problem Description

Given an array `nums` with `n` objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

**Example 1:**
```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Example 2:**
```
Input: nums = [2,0,1]
Output: [0,1,2]
```

## Approaches

### Approach 1: Three Pointers - Dutch National Flag (Optimal)

**Intuition:**
- Use three pointers: low, mid, and high
- low: boundary for 0s (everything before low is 0)
- mid: current element being examined
- high: boundary for 2s (everything after high is 2)
- Partition array into three sections: [0s | 1s | 2s]

**Algorithm:**
1. Initialize: low = 0, mid = 0, high = n-1
2. While mid <= high:
   - If nums[mid] == 0: swap with nums[low], increment both low and mid
   - If nums[mid] == 1: just increment mid
   - If nums[mid] == 2: swap with nums[high], decrement high (don't increment mid)
3. After the loop, array is sorted

**Why don't we increment mid when swapping with high?**
- The element swapped from high is unknown, so we need to examine it

**Time Complexity:** O(n) - Single pass
**Space Complexity:** O(1) - In-place sorting

### Approach 2: Two Pass - Counting Sort

**Intuition:**
- Count the number of 0s, 1s, and 2s
- Overwrite the array with counted values

**Algorithm:**
1. Count occurrences of 0, 1, and 2
2. Fill the array: first with 0s, then 1s, then 2s

**Time Complexity:** O(n) - Two passes
**Space Complexity:** O(1)

**Note:** Approach 1 is preferred as it's a one-pass solution.

### Approach 3: Standard Sorting

**Time Complexity:** O(n log n)
**Space Complexity:** O(1) or O(n) depending on the sort algorithm

**Note:** Not optimal and problem explicitly asks not to use library sort.

## Code Implementation

### Java Solution
See: `SortColors.java`

### C++ Solution
See: `SortColors.cpp`

## Key Takeaways

1. Dutch National Flag algorithm is efficient for partitioning problems
2. Three pointers help maintain invariants for three categories
3. Be careful about when to increment/decrement pointers
4. The algorithm maintains: [0...low-1] = 0, [low...mid-1] = 1, [high+1...n-1] = 2
5. The unknown region is [mid...high]

## Visual Example

```
Initial: [2,0,2,1,1,0]
         low,mid      high

Step 1: nums[mid]=2, swap with high, high--
[0,0,2,1,1,2]
 low,mid  high

Step 2: nums[mid]=0, swap with low, both++
[0,0,2,1,1,2]
   low,mid high

Step 3: nums[mid]=2, swap with high, high--
[0,0,1,1,2,2]
   low,mid
       high

Step 4: nums[mid]=1, mid++
[0,0,1,1,2,2]
   low  mid
       high

Step 5: nums[mid]=1, mid++
[0,0,1,1,2,2]
   low    mid,high

Done! (mid > high)
```

## Common Pitfalls

1. Incrementing mid after swapping with high (should not do this)
2. Not maintaining the invariants correctly
3. Off-by-one errors in pointer initialization
4. Forgetting to handle edge cases (empty array, single element)
