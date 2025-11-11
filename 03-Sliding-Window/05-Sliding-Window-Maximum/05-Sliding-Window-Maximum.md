# Sliding Window Maximum

**LeetCode Link:** https://leetcode.com/problems/sliding-window-maximum/

**Difficulty:** Hard

**Pattern:** Sliding Window with Monotonic Deque

## Problem Description

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

**Example 1:**
```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**Example 2:**
```
Input: nums = [1], k = 1
Output: [1]
```

## Approach: Monotonic Decreasing Deque

**Intuition:**
- Use deque to store indices (not values)
- Maintain decreasing order in deque
- Front of deque always has maximum
- Remove elements outside window

**Algorithm:**
1. Deque stores indices in decreasing order of values
2. For each element:
   - Remove indices outside current window from front
   - Remove indices with smaller values from back
   - Add current index to back
   - If window complete, add front element to result

**Time Complexity:** O(n) - each element added/removed once
**Space Complexity:** O(k) - deque size

## Visual Example

```
nums = [1,3,-1,-3,5,3,6,7], k = 3

i=0: deque=[0], window=[1]
i=1: deque=[1], window=[1,3] (remove 0, add 1)
i=2: deque=[1,2], window=[1,3,-1], max=3 ← output[0]

i=3: deque=[1,2,3], window=[3,-1,-3], max=3 ← output[1]
i=4: deque=[4], window=[-1,-3,5], max=5 ← output[2] (clear deque, 5 > all)
i=5: deque=[4,5], window=[-3,5,3], max=5 ← output[3]
i=6: deque=[6], window=[5,3,6], max=6 ← output[4] (6 > 5,3)
i=7: deque=[7], window=[3,6,7], max=7 ← output[5] (7 > all)

Result: [3,3,5,5,6,7]
```

## Key Takeaways

1. **Deque stores indices**: Not values, so we can check if in window
2. **Monotonic decreasing**: Back elements always smaller
3. **Front is maximum**: Always max in current window
4. **O(n) complexity**: Each element processed once
5. **Remove from both ends**: Front for window, back for monotonic

## Code Implementation

See: `SlidingWindowMaximum.java` and `SlidingWindowMaximum.cpp`

## Why Deque (Not other structures)?

| Structure | Time | Why Not? |
|-----------|------|----------|
| Brute Force | O(n*k) | Too slow |
| Max Heap | O(n log k) | Can't remove non-top elements efficiently |
| Multiset (C++) | O(n log k) | Works but slower than deque |
| **Deque** | **O(n)** | **Optimal - O(1) per element** |

## Deque Operations

```java
Deque<Integer> deque = new ArrayDeque<>();

// Add to back
deque.offerLast(i);

// Remove from back
deque.pollLast();

// Remove from front
deque.pollFirst();

// Peek front
int maxIndex = deque.peekFirst();
```

## Interview Tips

1. **Mention brute force**: "Could check max in each window - O(n*k)"
2. **Heap approach**: "Heap is O(n log k), but deque can do O(n)"
3. **Explain monotonic**: "Keep decreasing order, remove smaller from back"
4. **Index vs value**: "Store indices to check if still in window"
5. **Walk through example**: Draw deque state at each step
