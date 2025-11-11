# Find the Duplicate Number

**LeetCode Link:** https://leetcode.com/problems/find-the-duplicate-number/

**Difficulty:** Medium

**Pattern:** Fast and Slow Pointers

## Problem Description

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number** in `nums`, return this repeated number.

You must solve the problem **without** modifying the array `nums` and uses only constant extra space.

**Example 1:**
```
Input: nums = [1,3,4,2,2]
Output: 2
```

**Example 2:**
```
Input: nums = [3,1,3,4,2]
Output: 3
```

**Constraints:**
- `1 <= n <= 10^5`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
- All integers in `nums` appear only **once** except for **precisely one integer** which appears **two or more** times

## Approaches

### Approach 1: Sort (Violates Constraints)
**Time:** O(n log n), **Space:** O(1) or O(n)
*Modifies array - not allowed*

### Approach 2: HashSet (Violates Constraints)
**Time:** O(n), **Space:** O(n)
*Uses extra space - not allowed*

### Approach 3: Fast and Slow Pointers - Floyd's Algorithm (Optimal)

**Intuition:**
- Treat array as an **implicit linked list**
- Array index is the node, value at that index is the pointer to next node
- Since there's a duplicate, there's a cycle in this implicit linked list
- Use Floyd's cycle detection to find where the cycle begins
- The cycle beginning is the duplicate number

**Why does this work?**
- Index 0 to n exist, values 1 to n
- Each value points to an index
- Duplicate value means multiple nodes point to same node (cycle entry)
- The cycle entry point is the duplicate number

**Algorithm:**

**Phase 1: Detect Cycle**
1. slow = nums[0], fast = nums[0]
2. Move slow one step, fast two steps until they meet

**Phase 2: Find Cycle Entry (Duplicate)**
1. Reset slow to start (nums[0])
2. Move both slow and fast one step at a time
3. When they meet, that's the duplicate

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Code Implementation

See: `FindDuplicateNumber.java` and `FindDuplicateNumber.cpp`

## Key Takeaways

1. **Brilliant application of Floyd's algorithm on arrays**
2. **Array values as pointers**: nums[i] points to index nums[i]
3. **Duplicate creates cycle entry point**
4. **Two phases**: Detect cycle + Find entry
5. **Satisfies all constraints**: No modification, O(1) space

## Mathematical Proof

**Why does the duplicate create a cycle?**
- Imagine array indices as nodes
- Value at index i points to node nums[i]
- If value X appears twice at indices a and b:
  - Both nodes a and b point to node X
  - Node X has two incoming edges → cycle!
  - X is the cycle entry point

**Why does Floyd's algorithm find it?**
- Phase 1 finds a meeting point in the cycle
- Phase 2 finds the cycle entry from the meeting point
- The cycle entry is where the duplicate value is

## Visual Example

```
nums = [1,3,4,2,2]
Index: 0 1 2 3 4

Implicit linked list:
0 → nums[0]=1 → nums[1]=3 → nums[3]=2 → nums[2]=4 → nums[4]=2
                                  ↑                         ↓
                                  ←←←←←←←←←←←←←←←←←←←←←←←←←←

Cycle exists! Entry point = 2 (the duplicate)

Phase 1: slow and fast meet in cycle
Phase 2: Find entry point = 2
```

```
nums = [3,1,3,4,2]
Index: 0 1 2 3 4

0 → 3 → 4 → 2 → 3 (cycle back to index 3)
    ↑           ↓
    ←←←←←←←←←←←←

Entry point = 3 (the duplicate)
```

## Edge Cases

1. Minimum array: [1,1] → duplicate is 1
2. All elements same: [2,2,2,2,2] → duplicate is 2
3. Large duplicate count: [1,1,1,1,2] → duplicate is 1
4. End of range: [1,2,3,4,5,5] → duplicate is 5

## Common Pitfalls

1. **Not starting from index 0**: Must start at nums[0]
2. **Array modification**: Don't sort or mark elements
3. **Using extra space**: No HashSet allowed
4. **Wrong phase 2**: Both pointers move 1 step (not slow=1, fast=2)
5. **Index confusion**: Follow nums[i] as pointer, not i

## Why Start at nums[0] Not 0?

- Index 0 might not be part of the cycle
- Starting at nums[0] ensures we enter the linked list structure
- We treat nums[0] as the "head" of our implicit list

## Comparison with Linked List Cycle II

| Aspect | Linked List Cycle II | Find Duplicate Number |
|--------|---------------------|---------------------|
| Structure | Explicit linked list | Implicit (array as list) |
| Pointers | node.next | nums[i] |
| Cycle Entry | Node in cycle | Duplicate value |
| Starting Point | head | nums[0] |

## Related Problems

- Linked List Cycle II
- Happy Number
- Circular Array Loop
- Missing Number (complement problem)
