# Linked List Cycle

**LeetCode Link:** https://leetcode.com/problems/linked-list-cycle/

**Difficulty:** Easy

**Pattern:** Fast and Slow Pointers

## Problem Description

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

**Example 1:**
```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle where the tail connects to the 1st node (0-indexed).
```

**Example 2:**
```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle where the tail connects to the 0th node.
```

**Example 3:**
```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

## Approaches

### Approach 1: HashSet

**Intuition:**
- Store visited nodes in a hash set
- If we encounter a node we've seen before, there's a cycle

**Time Complexity:** O(n)
**Space Complexity:** O(n)

### Approach 2: Fast and Slow Pointers (Floyd's Cycle Detection - Optimal)

**Intuition:**
- Use two pointers: slow (1 step) and fast (2 steps)
- If there's a cycle, fast will eventually catch up to slow
- If there's no cycle, fast will reach null

**Algorithm:**
1. Initialize slow = head, fast = head
2. While fast != null and fast.next != null:
   - Move slow one step: slow = slow.next
   - Move fast two steps: fast = fast.next.next
   - If slow == fast: return true (cycle detected)
3. Return false (no cycle)

**Why does this work?**
- In a race track (cycle), faster runner eventually laps slower runner
- Fast gains 1 position per iteration on slow
- Within cycle length iterations, they must meet

**Time Complexity:** O(n) - Each node visited at most twice
**Space Complexity:** O(1) - Only two pointers

## Code Implementation

### Java Solution
See: `LinkedListCycle.java`

### C++ Solution
See: `LinkedListCycle.cpp`

## Key Takeaways

1. **Classic application of Floyd's Cycle Detection Algorithm**
2. **Space optimization**: O(n) → O(1) compared to HashSet
3. **Meeting guarantee**: If cycle exists, pointers WILL meet
4. **Null checks critical**: Check fast and fast.next before moving
5. **Foundation problem**: Understanding this enables solving harder variants

## Mathematical Proof

**Claim:** If there's a cycle, slow and fast will meet.

**Proof:**
- Let cycle length = C
- When slow enters cycle, let distance between slow and fast = d
- Each iteration, fast gains 1 position on slow
- After C - d iterations, fast catches slow
- Therefore, they must meet within C iterations

## Visual Example

```
Example with cycle:

3 → 2 → 0 → -4
    ↑         ↓
    ←←←←←←←←←←

Initial:
slow = 3, fast = 3

Step 1:
slow = 2, fast = 0

Step 2:
slow = 0, fast = 2

Step 3:
slow = -4, fast = -4
MEET! Cycle detected.
```

```
Example without cycle:

1 → 2 → 3 → null

Initial:
slow = 1, fast = 1

Step 1:
slow = 2, fast = 3

Step 2:
fast.next = null
No cycle.
```

## Edge Cases

1. Empty list: head == null → false
2. Single node no cycle: [1] → false
3. Single node with cycle: [1] pointing to itself → true
4. Two nodes with cycle: [1,2] where 2 points to 1 → true
5. Long list without cycle → false

## Common Pitfalls

1. **Not checking fast.next**: Causes NullPointerException
2. **Wrong initialization**: Starting pointers at different positions
3. **Incorrect loop condition**: Not checking both fast and fast.next
4. **Modifying list**: Problem requires read-only access
5. **Returning early**: Checking equality before moving pointers

## Why Not Use Slow = head, Fast = head.next?

Some implementations use this, but it complicates the logic:
- Need extra null check for head
- Meeting condition becomes more complex
- Starting both at head is cleaner and more intuitive

## Related Problems

- **Linked List Cycle II**: Find where cycle begins
- **Happy Number**: Same algorithm on number sequences
- **Find Duplicate Number**: Array cycle detection
- **Circular Array Loop**: Cycle in arrays

## Interview Tips

1. **Ask about constraints**: Can we modify the list? Space limitations?
2. **Start with brute force**: Explain HashSet approach first
3. **Optimize**: Then introduce fast-slow pointers
4. **Code carefully**: Null checks are critical
5. **Test edge cases**: Single node, no cycle, entire list is cycle

## Time Complexity Analysis

**Best Case:** O(n) - No cycle, fast reaches end quickly
**Average Case:** O(n) - Cycle exists, meet after partial traversal
**Worst Case:** O(n) - Meet just before completing second lap

All cases are O(n), making this optimal!
