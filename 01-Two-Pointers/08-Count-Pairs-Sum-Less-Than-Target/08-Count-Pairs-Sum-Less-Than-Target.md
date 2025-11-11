# Count Pairs Whose Sum is Less than Target

**LeetCode Link:** https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/

**Difficulty:** Easy

**Pattern:** Two Pointers

## Problem Description

Given a 0-indexed integer array `nums` of length `n` and an integer `target`, return the number of pairs `(i, j)` where `0 <= i < j < n` and `nums[i] + nums[j] < target`.

**Example 1:**
```
Input: nums = [-1,1,2,3,1], target = 2
Output: 3
Explanation: There are 3 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
- (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target
- (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
```

**Example 2:**
```
Input: nums = [-6,2,5,-2,-7,-1,3], target = -2
Output: 10
```

## Approaches

### Approach 1: Brute Force

**Intuition:**
- Check all possible pairs using nested loops
- Count pairs where sum < target

**Algorithm:**
1. Use two nested loops (i, j where i < j)
2. If nums[i] + nums[j] < target, increment count
3. Return count

**Time Complexity:** O(n²)
**Space Complexity:** O(1)

### Approach 2: Sort + Two Pointers (Optimal)

**Intuition:**
- Sort the array first
- Use two pointers from both ends
- If sum < target, all pairs between left and right are valid
- This is because array is sorted, so if nums[left] + nums[right] < target, then nums[left] + nums[k] < target for all k between left and right

**Algorithm:**
1. Sort the array
2. Initialize left = 0, right = n-1, count = 0
3. While left < right:
   - If nums[left] + nums[right] < target:
     - All pairs (left, left+1), (left, left+2), ..., (left, right) are valid
     - count += (right - left)
     - left++
   - Else:
     - right--
4. Return count

**Time Complexity:** O(n log n) - Due to sorting
**Space Complexity:** O(1) or O(n) depending on sorting algorithm

**Why (right - left) pairs?**
- If nums[left] + nums[right] < target, then:
  - nums[left] + nums[right] < target
  - nums[left] + nums[right-1] < target (array is sorted)
  - nums[left] + nums[right-2] < target
  - ... and so on
- So we have (right - left) valid pairs with left as the first element

## Code Implementation

### Java Solution
See: `CountPairsSumLessThanTarget.java`

### C++ Solution
See: `CountPairsSumLessThanTarget.cpp`

## Key Takeaways

1. Sorting enables efficient counting with two pointers
2. When sum < target in sorted array, all intermediate pairs are valid
3. Count multiple pairs in one step: count += (right - left)
4. Two pointers reduces O(n²) to O(n log n)

## Visual Example

```
nums = [-1,1,2,3,1], target = 2
After sorting: [-1,1,1,2,3]

left=0, right=4: -1+3=2 >= 2, right--
left=0, right=3: -1+2=1 < 2, count += (3-0) = 3 pairs: (-1,2), (-1,1), (-1,1), left++
left=1, right=3: 1+2=3 >= 2, right--
left=1, right=2: 1+1=2 >= 2, right--
left=1, right=1: stop

Total count = 3
```

## Common Pitfalls

1. Forgetting to sort the array first
2. Not understanding why count += (right - left) works
3. Using wrong comparison (< vs <=)
4. Off-by-one errors in counting
