# Squares of a Sorted Array

**LeetCode Link:** https://leetcode.com/problems/squares-of-a-sorted-array/

**Difficulty:** Easy

**Pattern:** Two Pointers

## Problem Description

Given an integer array `nums` sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

**Example 1:**
```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

**Example 2:**
```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

**Follow up:** Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

## Approaches

### Approach 1: Square and Sort (Straightforward)

**Intuition:**
- Square each element
- Sort the resulting array

**Algorithm:**
1. Iterate through array and square each element
2. Sort the array
3. Return result

**Time Complexity:** O(n log n) - due to sorting
**Space Complexity:** O(1) or O(n) depending on sorting algorithm

### Approach 2: Two Pointers from Both Ends (Optimal)

**Intuition:**
- The array is sorted, so the largest absolute values are at the ends
- After squaring, the largest squares will be at either end (most negative or most positive)
- Use two pointers from both ends and fill result array from right to left
- Compare squares at both ends and take the larger one

**Algorithm:**
1. Create result array of same size
2. Initialize left = 0, right = n-1
3. Fill result from end (index = n-1) to beginning:
   - Compare nums[left]² and nums[right]²
   - Place larger square at current index
   - Move corresponding pointer
   - Decrement index
4. Return result

**Time Complexity:** O(n) - Single pass
**Space Complexity:** O(n) - For output array (O(1) if output doesn't count)

**Why fill from right to left?**
- We can easily identify the largest square (from either end)
- But we cannot easily identify the smallest square without additional comparisons
- So we fill from largest to smallest

## Code Implementation

### Java Solution
See: `SquaresOfSortedArray.java`

### C++ Solution
See: `SquaresOfSortedArray.cpp`

## Key Takeaways

1. Two pointers from both ends work when extremes are important
2. Filling result array from largest to smallest is a key insight
3. Negative numbers when squared become positive and may be large
4. This problem demonstrates how sorting can be avoided with clever use of two pointers
5. The input being sorted is crucial to the O(n) solution

## Visual Example

```
Input: [-4, -1, 0, 3, 10]
        L              R

Step 1: Compare (-4)² = 16 and (10)² = 100
        100 is larger, place at result[4]
        Move R left
        Result: [_, _, _, _, 100]

Step 2: Compare (-4)² = 16 and (3)² = 9
        16 is larger, place at result[3]
        Move L right
        Result: [_, _, _, 16, 100]

Step 3: Compare (-1)² = 1 and (3)² = 9
        9 is larger, place at result[2]
        Move R left
        Result: [_, _, 9, 16, 100]

Step 4: Compare (-1)² = 1 and (0)² = 0
        1 is larger, place at result[1]
        Move L right
        Result: [_, 1, 9, 16, 100]

Step 5: Only 0 remains
        Place at result[0]
        Result: [0, 1, 9, 16, 100]
```

## Edge Cases

1. All negative numbers: [-5, -4, -3, -2, -1] → [1, 4, 9, 16, 25]
2. All positive numbers: [1, 2, 3, 4, 5] → [1, 4, 9, 16, 25]
3. Mix with zero: [-3, 0, 3] → [0, 9, 9]
4. Single element: [5] → [25]

## Common Pitfalls

1. Trying to fill result array from left to right (harder to identify minimum)
2. Forgetting that negative numbers become positive when squared
3. Not handling zero correctly
4. Off-by-one errors in pointer movements
5. Not comparing absolute values/squares correctly
