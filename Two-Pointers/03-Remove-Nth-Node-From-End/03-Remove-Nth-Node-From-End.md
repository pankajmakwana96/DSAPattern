# Remove Nth Node From End of List

**LeetCode Link:** https://leetcode.com/problems/remove-nth-node-from-end-of-list/

**Difficulty:** Medium

**Pattern:** Two Pointers (Fast & Slow)

## Problem Description

Given the head of a linked list, remove the nth node from the end of the list and return its head.

**Example 1:**
```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Example 2:**
```
Input: head = [1], n = 1
Output: []
```

**Example 3:**
```
Input: head = [1,2], n = 1
Output: [1]
```

## Approaches

### Approach 1: Two Pass (Straightforward)

**Intuition:**
- First pass: Calculate the length of the linked list
- Second pass: Traverse to the (length - n)th node and remove the next node

**Algorithm:**
1. Count the total number of nodes in the list
2. Calculate the position from the beginning: pos = length - n
3. Traverse to position pos-1 and remove the next node

**Time Complexity:** O(n) - Two passes through the list
**Space Complexity:** O(1)

### Approach 2: One Pass with Two Pointers (Optimal)

**Intuition:**
- Use two pointers (fast and slow) with a gap of n nodes between them
- When fast pointer reaches the end, slow pointer will be at the node before the one to be removed
- Use a dummy node to handle edge cases (removing the head)

**Algorithm:**
1. Create a dummy node pointing to head
2. Initialize fast and slow pointers to dummy
3. Move fast pointer n+1 steps ahead
4. Move both pointers until fast reaches the end
5. Remove the node: slow.next = slow.next.next
6. Return dummy.next

**Time Complexity:** O(n) - Single pass through the list
**Space Complexity:** O(1)

**Why n+1 steps?**
- We want slow to be at the node BEFORE the one to be deleted
- If fast moves n+1 steps, when it reaches null, slow will be at the correct position

## Code Implementation

### Java Solution
See: `RemoveNthNodeFromEnd.java`

### C++ Solution
See: `RemoveNthNodeFromEnd.cpp`

## Key Takeaways

1. Dummy node simplifies edge case handling (removing head)
2. Two pointers with fixed gap is a common pattern for "nth from end" problems
3. One pass solution is more efficient and elegant
4. Always consider edge cases: n = length (remove head), list with one node
5. The gap between pointers determines which node we can access

## Visual Example

```
Remove 2nd node from end:

Initial: 1 -> 2 -> 3 -> 4 -> 5 -> null, n = 2

Step 1: Move fast n+1 (3) steps
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> null
slow     fast

Step 2: Move both until fast reaches end
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> null
         slow          fast

Step 3: Remove slow.next
dummy -> 1 -> 2 -> 3 -> 5 -> null
         slow

Result: 1 -> 2 -> 3 -> 5
```
