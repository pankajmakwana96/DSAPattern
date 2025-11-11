# Count Subarrays With Fixed Bounds

**LeetCode Link:** https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

**Difficulty:** Hard

**Pattern:** Two Pointers / Sliding Window

## Problem Description

You are given an integer array `nums` and two integers `minK` and `maxK`.

A fixed-bound subarray of `nums` is a subarray that satisfies the following conditions:
- The minimum value in the subarray is equal to `minK`.
- The maximum value in the subarray is equal to `maxK`.

Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

**Example 1:**
```
Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
```

**Example 2:**
```
Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
```

## Approaches

### Approach: Three Pointers (Optimal)

**Intuition:**
- Track last positions of minK, maxK, and last invalid element
- For each position, count valid subarrays ending at that position
- A subarray is valid if:
  - It contains both minK and maxK
  - All elements are within [minK, maxK]

**Key Observations:**
1. Elements outside [minK, maxK] break valid subarrays
2. For position i to end a valid subarray:
   - We need minK and maxK to appear before i
   - Last invalid position should be before both minK and maxK positions
3. Number of valid subarrays ending at i = min(lastMinPos, lastMaxPos) - lastInvalidPos

**Algorithm:**
1. Initialize:
   - lastMin = -1 (last position of minK)
   - lastMax = -1 (last position of maxK)
   - lastInvalid = -1 (last position of element outside [minK, maxK])
2. For each index i:
   - Update lastInvalid if nums[i] outside [minK, maxK]
   - Update lastMin if nums[i] == minK
   - Update lastMax if nums[i] == maxK
   - Count valid subarrays: max(0, min(lastMin, lastMax) - lastInvalid)
3. Return total count

**Why does this work?**
- min(lastMin, lastMax) gives the rightmost of the two required boundaries
- Subtracting lastInvalid gives the number of valid starting positions
- All subarrays from (lastInvalid+1) to min(lastMin, lastMax) are valid starts

**Time Complexity:** O(n) - Single pass
**Space Complexity:** O(1) - Only three variables

## Code Implementation

### Java Solution
See: `CountSubarraysFixedBounds.java`

### C++ Solution
See: `CountSubarraysFixedBounds.cpp`

## Key Takeaways

1. Track three positions: minK, maxK, and invalid element
2. Count subarrays ending at each position incrementally
3. The formula: min(lastMin, lastMax) - lastInvalid counts valid starts
4. Invalid elements reset the counting window
5. This is a variation of sliding window with three pointers

## Visual Example

```
nums = [1,3,5,2,7,5], minK = 1, maxK = 5

i=0: nums[0]=1 (minK), lastMin=0
     Valid subarrays = min(0, -1) - (-1) = 0

i=1: nums[1]=3,
     Valid subarrays = min(0, -1) - (-1) = 0

i=2: nums[2]=5 (maxK), lastMax=2
     Valid subarrays = min(0, 2) - (-1) = 1  → [1,3,5]

i=3: nums[3]=2
     Valid subarrays = min(0, 2) - (-1) = 1  → [1,3,5,2]

i=4: nums[4]=7 (invalid!), lastInvalid=4
     Valid subarrays = min(0, 2) - 4 = 0

i=5: nums[5]=5 (maxK), lastMax=5
     Valid subarrays = min(0, 5) - 4 = 0

Total = 0+0+1+1+0+0 = 2
```

## Common Pitfalls

1. Not handling elements outside [minK, maxK]
2. Forgetting to use max(0, ...) to avoid negative counts
3. Not understanding why min(lastMin, lastMax) is used
4. Off-by-one errors in position tracking
5. Not initializing positions to -1
