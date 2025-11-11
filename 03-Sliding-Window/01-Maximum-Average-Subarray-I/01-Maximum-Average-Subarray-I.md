# Maximum Average Subarray I

**LeetCode Link:** https://leetcode.com/problems/maximum-average-subarray-i/

**Difficulty:** Easy

**Pattern:** Sliding Window (Fixed Size)

## Problem Description

You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose length is equal to `k` that has the maximum average value and return this value.

**Example 1:**
```
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
```

**Example 2:**
```
Input: nums = [5], k = 1
Output: 5.00000
```

**Constraints:**
- n == nums.length
- 1 <= k <= n <= 10^5
- -10^4 <= nums[i] <= 10^4

## Approach: Fixed-Size Sliding Window

**Intuition:**
- Calculate sum of first K elements
- Slide window: remove leftmost, add rightmost
- Track maximum sum, convert to average

**Algorithm:**
1. Calculate sum of first K elements
2. Initialize maxSum with this sum
3. Slide window from index K to end:
   - Remove nums[i-k] from sum
   - Add nums[i] to sum
   - Update maxSum if current sum is larger
4. Return maxSum / k as double

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Visual Example

```
nums = [1, 12, -5, -6, 50, 3], k = 4

Initial window [0-3]:
[1, 12, -5, -6] → sum = 2

Slide to [1-4]:
Remove 1, Add 50
[12, -5, -6, 50] → sum = 51 ← MAX

Slide to [2-5]:
Remove 12, Add 3
[-5, -6, 50, 3] → sum = 42

Maximum sum = 51
Average = 51 / 4 = 12.75
```

## Step-by-Step Walkthrough

```
nums = [1, 12, -5, -6, 50, 3], k = 4

Step 1: First window sum
sum = 1 + 12 + (-5) + (-6) = 2
maxSum = 2

Step 2: Slide to index 4
sum = 2 - 1 + 50 = 51
maxSum = 51

Step 3: Slide to index 5
sum = 51 - 12 + 3 = 42
maxSum = 51 (unchanged)

Result: 51 / 4.0 = 12.75
```

## Key Takeaways

1. **Classic fixed window problem**: Window size K never changes
2. **Optimization**: O(n) instead of O(n*k) brute force
3. **Sliding technique**: Remove left, add right in O(1)
4. **Track sum, not average**: Convert to average at end
5. **Integer overflow**: Use long if needed for sum

## Code Implementation

See: `MaximumAverageSubarray.java` and `MaximumAverageSubarray.cpp`

## Edge Cases

1. **K = 1**: Each element is a subarray
2. **K = n**: Entire array is the only subarray
3. **All negative**: Still works correctly
4. **Single element** (n=1, k=1): Return that element
5. **Large numbers**: Be careful with integer overflow

## Common Pitfalls

1. Calculating average inside loop (unnecessary division)
2. Not using sliding window (recalculating sum each time)
3. Integer division instead of floating point
4. Off-by-one errors in loop bounds
5. Not handling negative numbers correctly

## Brute Force vs Optimized

### Brute Force: O(n*k)
```java
for (int i = 0; i <= n - k; i++) {
    int sum = 0;
    for (int j = i; j < i + k; j++) {
        sum += nums[j];
    }
    maxSum = Math.max(maxSum, sum);
}
```

### Optimized: O(n)
```java
// Calculate first window
for (int i = 0; i < k; i++) sum += nums[i];

// Slide window
for (int i = k; i < n; i++) {
    sum = sum - nums[i-k] + nums[i];
    maxSum = Math.max(maxSum, sum);
}
```

**Improvement:** 100x faster for large K!

## Related Problems

- Maximum Sum Subarray of Size K (similar)
- Minimum Size Subarray Sum (variable window)
- Sliding Window Maximum (using deque)
- Maximum Points You Can Obtain from Cards

## Interview Tips

1. **Clarify**: Can k be larger than array length? (No per constraints)
2. **Mention brute force**: "Could do O(n*k) but sliding window is O(n)"
3. **Explain sliding**: "Remove leftmost, add rightmost"
4. **Return type**: Make sure to return double, not int
5. **Test**: Use provided examples, add edge case
