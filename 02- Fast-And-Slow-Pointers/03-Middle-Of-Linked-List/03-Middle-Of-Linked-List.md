# Middle of the Linked List

**LeetCode Link:** https://leetcode.com/problems/middle-of-the-linked-list/

**Difficulty:** Easy

**Pattern:** Fast and Slow Pointers

## Problem Description

Given the `head` of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the **second middle** node.

**Example 1:**
```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node is 3.
```

**Example 2:**
```
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes (3 and 4), we return the second one.
```

## Approaches

### Approach 1: Two Pass

**Intuition:**
- Count total nodes in first pass
- In second pass, move to middle (count/2)

**Time Complexity:** O(n)
**Space Complexity:** O(1)

### Approach 2: Fast and Slow Pointers (Optimal)

**Intuition:**
- Slow pointer moves 1 step, fast pointer moves 2 steps
- When fast reaches end, slow is at middle
- Single pass solution

**Algorithm:**
1. Initialize slow = head, fast = head
2. While fast != null and fast.next != null:
   - slow = slow.next (1 step)
   - fast = fast.next.next (2 steps)
3. Return slow (middle node)

**Why does this work?**
- Fast moves twice as fast as slow
- When fast finishes, slow has covered half the distance
- For odd length: fast.next = null, slow at middle
- For even length: fast = null, slow at second middle

**Time Complexity:** O(n) - Single pass
**Space Complexity:** O(1) - Two pointers

## Code Implementation

See: `MiddleOfLinkedList.java` and `MiddleOfLinkedList.cpp`

## Key Takeaways

1. Classic application of fast-slow pointers for finding middle
2. Single pass is more efficient than counting
3. Handles odd and even length lists automatically
4. Foundation for many other problems (palindrome, reordering)
5. No need to know list length beforehand

## Visual Example

**Odd Length List:**
```
1 → 2 → 3 → 4 → 5 → null
S,F

1 → 2 → 3 → 4 → 5 → null
    S       F

1 → 2 → 3 → 4 → 5 → null
        S           F(null)

Middle = 3 ✓
```

**Even Length List:**
```
1 → 2 → 3 → 4 → 5 → 6 → null
S,F

1 → 2 → 3 → 4 → 5 → 6 → null
    S       F

1 → 2 → 3 → 4 → 5 → 6 → null
        S           F

1 → 2 → 3 → 4 → 5 → 6 → null
            S            F(null)

Middle = 4 (second middle) ✓
```

## Edge Cases

1. **Single node**: Return that node
2. **Two nodes**: Return second node
3. **Empty list**: Return null
4. **Very long list**: Algorithm still O(1) space

## Applications

This pattern is used in:
- **Palindrome Linked List**: Find middle, reverse second half
- **Reorder List**: Split at middle, reverse, merge
- **Merge Sort on Linked List**: Find middle to split
- **Binary Search on Linked List**: Find middle pivot

## Common Pitfalls

1. Off-by-one error with even length lists
2. Not handling null head
3. Not checking fast.next before fast.next.next
4. Returning first middle instead of second for even length

## Why Second Middle for Even Length?

Design choice by LeetCode for consistency:
- Makes palindrome checking easier
- Simplifies many algorithms
- If you need first middle, check `fast.next.next != null` instead
