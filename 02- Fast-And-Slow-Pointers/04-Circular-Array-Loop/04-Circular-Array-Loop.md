# Circular Array Loop

**LeetCode Link:** https://leetcode.com/problems/circular-array-loop/

**Difficulty:** Medium

**Pattern:** Fast and Slow Pointers

## Problem Description

You are playing a game involving a **circular array** of non-zero integers `nums`. Each `nums[i]` denotes the number of indices forward/backward you must move if you are located at index `i`:
- If `nums[i]` is positive, move `nums[i]` steps **forward**, and
- If `nums[i]` is negative, move `nums[i]` steps **backward**.

Since the array is **circular**, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

A **cycle** in the array consists of a sequence of indices `seq` of length `k` where:
- Following the movement rules above results in the repeating index sequence
- Every `nums[seq[j]]` is either **all positive** or **all negative**
- `k > 1`

Return `true` if there is a cycle in `nums`, or `false` otherwise.

**Example 1:**
```
Input: nums = [2,-1,1,2,2]
Output: true
Explanation: There is a cycle from index 0 -> 2 -> 3 -> 0.
```

**Example 2:**
```
Input: nums = [-1,2]
Output: false
Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle because the cycle's length is 1.
```

**Example 3:**
```
Input: nums = [-2,1,-1,-2,-2]
Output: false
Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle because nums[1] is positive, but nums[2] is negative.
```

## Approach: Fast and Slow Pointers with Direction Check

**Intuition:**
- Treat array as implicit linked list where each index points to next index
- Use Floyd's cycle detection algorithm
- Additional constraints: same direction, cycle length > 1

**Algorithm:**
1. For each starting index:
   - Use fast and slow pointers
   - Both must move in same direction (all positive or all negative)
   - Check if cycle length > 1 (not single element loop)
   - If valid cycle found, return true
2. Optimization: Mark visited indices to avoid redundant checks

**Time Complexity:** O(n²) - Worst case check from each index
**Space Complexity:** O(1) - Only using pointers

## Key Challenges

1. **Direction Consistency**: All elements in cycle must have same sign
2. **Single Element Cycles**: Must be invalid (k > 1)
3. **Circular Indexing**: Handle wraparound correctly
4. **Non-Cycle Paths**: Mark as visited to avoid rechecking

## Code Implementation

See: `CircularArrayLoop.java` and `CircularArrayLoop.cpp`

## Helper Functions

```java
// Get next index in circular array
int getNext(int[] nums, int index) {
    int n = nums.length;
    int next = (index + nums[index]) % n;
    if (next < 0) next += n;  // Handle negative wraparound
    return next;
}

// Check if direction is same
boolean isSameDirection(int[] nums, int i, int j) {
    return (nums[i] > 0) == (nums[j] > 0);
}
```

## Key Takeaways

1. Extension of basic cycle detection with additional constraints
2. Direction checking is crucial for validity
3. Single-element cycles must be rejected
4. Circular array indexing requires careful modulo arithmetic
5. Optimization: Mark visited paths

## Visual Example

```
nums = [2,-1,1,2,2]
Index:  0  1 2 3 4

From index 0:
0 → 2 (0 + 2 = 2) ✓
2 → 3 (2 + 1 = 3) ✓
3 → 0 (3 + 2 = 5 % 5 = 0) ✓ CYCLE!

All positive direction ✓
Length > 1 ✓
Result: true
```

```
nums = [-1,2]
Index:  0 1

From index 1:
1 → 1 (1 + 2 = 3 % 2 = 1)

Single element cycle ✗
Result: false
```

## Edge Cases

1. Single element array: Always false
2. All same direction but no cycle: False
3. Mixed directions: False
4. Self-loop (k=1): False

## Common Pitfalls

1. Not checking direction consistency
2. Accepting single-element cycles
3. Incorrect circular index calculation
4. Not handling negative indices properly
5. Inefficient: checking same path multiple times
