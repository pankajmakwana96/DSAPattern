# Linked List Cycle II

**LeetCode Link:** https://leetcode.com/problems/linked-list-cycle-ii/

**Difficulty:** Medium

**Pattern:** Fast and Slow Pointers

## Problem Description

Given the `head` of a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer.

**Do not modify** the linked list.

**Example 1:**
```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle, where tail connects to the second node.
```

**Example 2:**
```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
```

**Example 3:**
```
Input: head = [1], pos = -1
Output: no cycle
```

## Approach: Floyd's Cycle Detection Algorithm (Two Phases)

**Intuition:**
- Phase 1: Detect if cycle exists using fast-slow pointers
- Phase 2: Find cycle entry point using mathematical property

**Algorithm:**

**Phase 1: Detect Cycle**
1. slow = head, fast = head
2. Move slow 1 step, fast 2 steps
3. If they meet, cycle exists
4. If fast reaches null, no cycle

**Phase 2: Find Entry Point**
1. Reset slow to head
2. Keep fast at meeting point
3. Move both 1 step at a time
4. When they meet again, that's the cycle entry

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Mathematical Proof

Let's prove why Phase 2 works:

**Setup:**
- Distance from head to cycle entry: **a**
- Distance from cycle entry to meeting point: **b**
- Distance from meeting point back to cycle entry: **c**
- Cycle length: **C = b + c**

**When slow and fast meet (Phase 1):**
- Slow traveled: **a + b**
- Fast traveled: **a + b + k×C** (k complete cycles)
- Fast = 2 × Slow: **a + b + k×C = 2(a + b)**

**Solving:**
```
a + b + k×C = 2a + 2b
k×C = a + b
a = k×C - b
a = k×(b + c) - b
a = (k-1)×C + C - b
a = (k-1)×C + c
```

**Conclusion:**
- Distance from head to entry (a) = Distance from meeting point to entry (c) + some complete cycles
- Moving both pointers 1 step from their positions will make them meet at entry!

## Code Implementation

See: `LinkedListCycleII.java` and `LinkedListCycleII.cpp`

## Key Takeaways

1. **Two distinct phases**: Detection vs Finding entry
2. **Mathematical elegance**: Distance equality property
3. **O(1) space**: No hash set needed
4. **Foundation for other problems**: Find Duplicate Number uses same logic
5. **Interview favorite**: Tests both coding and mathematical understanding

## Visual Example

```
3 → 2 → 0 → -4
    ↑         ↓
    ←←←←←←←←←←

a = 1 (head to entry at node 2)
b = 2 (entry to meeting point at node -4)
c = 1 (meeting point back to entry)

Phase 1: slow and fast meet at node -4
Phase 2:
  slow at head (3), fast at -4
  Step 1: slow at 2, fast at 2 → MEET!

Entry = node 2 ✓
```

## Step-by-Step Walkthrough

```
List: 3 → 2 → 0 → -4 → (back to 2)

Phase 1:
slow=3, fast=3
slow=2, fast=0
slow=0, fast=2
slow=-4, fast=-4  → MEET!

Phase 2:
slow=3 (reset), fast=-4 (stay)
slow=2, fast=2  → MEET! This is the entry!
```

## Edge Cases

1. **No cycle**: Return null
2. **Single node, no cycle**: Return null
3. **Single node, self cycle**: Return that node
4. **Entire list is cycle**: Entry is head
5. **Very long cycle**: Algorithm still O(n)

## Common Pitfalls

1. Not checking if cycle exists before Phase 2
2. Not resetting slow pointer to head in Phase 2
3. Moving pointers at different speeds in Phase 2 (both should move 1 step)
4. Not checking for null in Phase 1
5. Returning meeting point instead of entry point

## Comparison with Hash Set Approach

| Aspect | Floyd's Algorithm | Hash Set |
|--------|------------------|----------|
| Time | O(n) | O(n) |
| Space | O(1) | O(n) |
| Implementation | Complex | Simple |
| Modifies List | No | No |

## Why Not Just Use Hash Set?

**Interview perspective:**
- Hash Set is easier but uses O(n) space
- Floyd's algorithm demonstrates:
  - Deep understanding of linked lists
  - Mathematical insight
  - Optimization skills
- Always mention hash set as alternative, then optimize

## Related Problems

- Linked List Cycle (simpler version)
- Find Duplicate Number (same algorithm on array)
- Happy Number (cycle detection in sequences)
- Circular Array Loop

## Interview Strategy

1. **Clarify requirements**: Can we modify? Space constraints?
2. **Mention hash set**: "I can solve with hash set in O(n) space..."
3. **Optimize**: "But we can do O(1) space with Floyd's algorithm..."
4. **Explain math**: Draw diagram and explain distance relationship
5. **Code carefully**: Two distinct phases
6. **Test**: No cycle, single node, entire cycle cases
