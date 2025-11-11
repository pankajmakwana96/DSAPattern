# Minimum Size Subarray Sum

**LeetCode Link:** https://leetcode.com/problems/minimum-size-subarray-sum/

**Difficulty:** Medium

**Pattern:** Sliding Window (Shrinking)

## Problem Description

Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a subarray whose sum is greater than or equal to `target`. If there is no such subarray, return `0` instead.

**Example 1:**
```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

**Example 2:**
```
Input: target = 4, nums = [1,4,4]
Output: 1
```

**Example 3:**
```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

**Constraints:**
- 1 <= target <= 10^9
- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^4

**Follow up:** If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

## Approach: Shrinking Sliding Window

**Intuition:**
- Expand window until sum >= target
- Once condition met, shrink from left while maintaining sum >= target
- Track minimum window size

**Algorithm:**
1. Use two pointers: left = 0, right = 0
2. Expand window by adding nums[right]
3. While sum >= target:
   - Update minimum length
   - Shrink window by removing nums[left]
   - left++
4. Return minimum length (or 0 if never found)

**Time Complexity:** O(n) - each element added and removed at most once
**Space Complexity:** O(1)

## Visual Example

```
nums = [2, 3, 1, 2, 4, 3], target = 7

Step 1: [2] sum=2 < 7
Step 2: [2,3] sum=5 < 7
Step 3: [2,3,1] sum=6 < 7
Step 4: [2,3,1,2] sum=8 >= 7 ← minLen=4
        Shrink: [3,1,2] sum=6 < 7
Step 5: [3,1,2,4] sum=10 >= 7 ← minLen=4
        Shrink: [1,2,4] sum=7 >= 7 ← minLen=3
        Shrink: [2,4] sum=6 < 7
Step 6: [2,4,3] sum=9 >= 7 ← minLen=3
        Shrink: [4,3] sum=7 >= 7 ← minLen=2 ✓
        Shrink: [3] sum=3 < 7

Result: minLen = 2
```

## Key Takeaways

1. **Shrinking window**: Key is to shrink WHILE condition is met
2. **Greedy approach**: Always try to shrink when possible
3. **Each element visited twice**: Once by right, once by left
4. **Update inside while loop**: Get smallest valid window
5. **Positive numbers only**: Makes shrinking valid

## Code Implementation

See: `MinimumSizeSubarraySum.java` and `MinimumSizeSubarraySum.cpp`

## Alternative Approach: Binary Search + Prefix Sum

**Time:** O(n log n), **Space:** O(n)

```java
public int minSubArrayLen(int target, int[] nums) {
    int n = nums.length;
    int[] prefix = new int[n + 1];

    // Build prefix sum
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    int minLen = Integer.MAX_VALUE;

    // For each starting point
    for (int i = 0; i < n; i++) {
        // Binary search for ending point
        int toFind = target + prefix[i];
        int idx = binarySearch(prefix, toFind);
        if (idx != -1) {
            minLen = Math.min(minLen, idx - i);
        }
    }

    return minLen == Integer.MAX_VALUE ? 0 : minLen;
}
```

**Note:** Sliding window O(n) is better for this problem!

## Edge Cases

1. **Single element >= target**: Return 1
2. **Sum of all elements < target**: Return 0
3. **All elements same**: Works correctly
4. **Target = 1, array has 1**: Return 1
5. **Large target**: Might need entire array

## Common Pitfalls

1. Updating minLen outside while loop (missing optimal windows)
2. Not checking if valid window found (returning MAX_VALUE)
3. Wrong shrinking condition (using <  instead of >=)
4. Forgetting to expand window (not incrementing right)
5. Integer overflow with large sums

## Why Sliding Window Works

**Key Insight:** If [i, j] has sum >= target, then:
- [i, j+1] definitely has sum >= target
- We should try to shrink from i+1

**Monotonicity:** As we remove elements from left, sum decreases. Once sum < target, we know we need to expand right.

## Comparison with Other Approaches

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | Check all subarrays |
| Sliding Window | O(n) | O(1) | Optimal |
| Binary Search | O(n log n) | O(n) | Works but unnecessary |
| Prefix Sum only | O(n²) | O(n) | Not optimal |

## Related Problems

- Maximum Size Subarray Sum Equals k
- Minimum Window Substring (similar shrinking pattern)
- Shortest Subarray with Sum at Least K (handles negatives - harder)
- Maximum Average Subarray (fixed window version)

## Interview Tips

1. **Clarify**: All positive numbers? (Yes, makes it easier)
2. **Brute force first**: "Could check all O(n²) subarrays..."
3. **Optimize**: "Sliding window can shrink when condition met"
4. **Explain shrinking**: "Remove from left while sum >= target"
5. **Test**: No solution case, single element, all elements needed
