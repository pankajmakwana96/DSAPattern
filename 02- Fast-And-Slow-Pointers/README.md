# Fast and Slow Pointers Pattern

## Overview

The Fast and Slow Pointers pattern (also known as the **Tortoise and Hare algorithm** or **Floyd's Cycle Detection algorithm**) is a pointer technique that uses two pointers moving at different speeds through a data structure. This pattern is particularly effective for detecting cycles, finding middle elements, and solving problems in linked lists and arrays.

## When to Use Fast and Slow Pointers

1. **Cycle Detection**: Detect cycles in linked lists or arrays
2. **Finding Middle Element**: Find the middle of a linked list
3. **Finding Entry Point**: Locate where a cycle begins
4. **Palindrome Checking**: Check if a linked list is a palindrome
5. **Finding Duplicate Numbers**: Detect duplicates in special arrays
6. **List Manipulation**: Reorder or split linked lists

## How It Works

### Basic Principle
- **Slow Pointer**: Moves one step at a time
- **Fast Pointer**: Moves two steps at a time
- If there's a cycle, fast will eventually meet slow
- If there's no cycle, fast will reach the end

### Mathematical Foundation
If there's a cycle of length `C`:
- Fast pointer gains on slow pointer by 1 position per iteration
- They will meet within `C` iterations after entering the cycle
- Meeting point can be used to find cycle start

## Types of Problems

### 1. Cycle Detection
**Pattern:**
```
slow = head, fast = head
while fast != null && fast.next != null:
    slow = slow.next
    fast = fast.next.next
    if slow == fast:
        cycle detected
```
**Use Cases:** Linked List Cycle, Circular Array Loop

### 2. Finding Middle
**Pattern:**
```
slow = head, fast = head
while fast != null && fast.next != null:
    slow = slow.next
    fast = fast.next.next
return slow  // middle element
```
**Use Cases:** Middle of Linked List, Palindrome Linked List

### 3. Finding Cycle Start (Floyd's Algorithm)
**Pattern:**
```
// Phase 1: Detect cycle
slow = fast = head
while fast && fast.next:
    slow = slow.next
    fast = fast.next.next
    if slow == fast: break

// Phase 2: Find start
slow = head
while slow != fast:
    slow = slow.next
    fast = fast.next
return slow  // cycle start
```
**Use Cases:** Linked List Cycle II, Find Duplicate Number

## Time and Space Complexity

- **Time**: O(n) - Each element visited at most twice
- **Space**: O(1) - Only using two pointers

## Problems Covered (10 Problems)

### Easy Problems (4)
1. **Happy Number** - Detect cycle in number transformation
2. **Linked List Cycle** - Detect if linked list has a cycle
3. **Middle of the Linked List** - Find middle node
4. **Palindrome Linked List** - Check if list reads same forward/backward

### Medium Problems (5)
5. **Find the Duplicate Number** - Find duplicate using cycle detection
6. **Circular Array Loop** - Detect valid cycles in circular array
7. **Maximum Twin Sum of a Linked List** - Find max sum of twin nodes
8. **Linked List Cycle II** - Find where cycle begins
9. **Reorder List** - Rearrange list in specific pattern

### Hard Problems (1)
10. **Split a Circular Linked List** - Split circular list into parts

## Problem List with Links

| # | Problem | Difficulty | LeetCode Link | Implementation |
|---|---------|------------|---------------|----------------|
| 1 | Happy Number | Easy | [Link](https://leetcode.com/problems/happy-number/) | ✅ Full |
| 2 | Linked List Cycle | Easy | [Link](https://leetcode.com/problems/linked-list-cycle/) | ✅ Full |
| 3 | Middle of the Linked List | Easy | [Link](https://leetcode.com/problems/middle-of-the-linked-list/) | ✅ Full |
| 4 | Circular Array Loop | Medium | [Link](https://leetcode.com/problems/circular-array-loop/) | ✅ Full |
| 5 | Find the Duplicate Number | Medium | [Link](https://leetcode.com/problems/find-the-duplicate-number/) | ✅ Full |
| 6 | Palindrome Linked List | Easy | [Link](https://leetcode.com/problems/palindrome-linked-list/) | ✅ Full |
| 7 | Maximum Twin Sum Linked List | Medium | [Link](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) | ✅ Full |
| 8 | Linked List Cycle II | Medium | [Link](https://leetcode.com/problems/linked-list-cycle-ii/) | ✅ Full |
| 9 | Reorder List | Medium | [Link](https://leetcode.com/problems/reorder-list/) | ✅ Full |
| 10 | Split Circular Linked List | Hard | [Link](https://leetcode.com/problems/split-a-circular-linked-list/) | 📖 Approach |

## Key Patterns and Techniques

### 1. Basic Cycle Detection
```java
boolean hasCycle(ListNode head) {
    if (head == null) return false;

    ListNode slow = head;
    ListNode fast = head;

    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;

        if (slow == fast) {
            return true;  // Cycle detected
        }
    }

    return false;  // No cycle
}
```

### 2. Finding Middle Element
```java
ListNode findMiddle(ListNode head) {
    ListNode slow = head;
    ListNode fast = head;

    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }

    return slow;  // Middle node
}
```

### 3. Finding Cycle Start
```java
ListNode detectCycle(ListNode head) {
    ListNode slow = head, fast = head;

    // Phase 1: Detect cycle
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) break;
    }

    if (fast == null || fast.next == null) return null;

    // Phase 2: Find start
    slow = head;
    while (slow != fast) {
        slow = slow.next;
        fast = fast.next;
    }

    return slow;
}
```

## Tips and Tricks

1. **Null Checks**: Always check `fast != null && fast.next != null`
2. **Initialization**: Usually both pointers start at head
3. **Speed**: Fast moves 2x, slow moves 1x (can be adjusted)
4. **Meeting Point**: When they meet, specific mathematical properties hold
5. **Two Phases**: Many problems need two phases (detect + find)

## Common Mistakes

1. Not checking if fast.next exists before fast.next.next
2. Off-by-one errors when finding middle (even vs odd length)
3. Not resetting pointer to head in two-phase algorithms
4. Forgetting edge cases (empty list, single node)
5. Infinite loops when pointers don't move

## Why Fast and Slow Pointers Work for Cycle Detection

**Intuition:**
- In a cycle, fast pointer laps slow pointer
- Fast gains 1 position per iteration
- Within cycle length iterations, they must meet
- Like a race track - faster runner catches slower runner

**Mathematical Proof:**
- Let distance to cycle = `a`
- Let cycle length = `C`
- When slow enters cycle, fast is somewhere in cycle
- Distance between them = `d`
- They meet after `C - d` steps (when fast catches up)

## Applications Beyond Linked Lists

1. **Sequence Cycle Detection**: Finding repeating patterns in sequences
2. **Random Number Generators**: Detecting period in PRNGs
3. **Graph Cycles**: Finding cycles in functional graphs
4. **Memory**: Detecting infinite loops with constant space

## Comparison with Other Patterns

| Pattern | Space | Use Case |
|---------|-------|----------|
| Fast-Slow Pointers | O(1) | Cycle detection, middle finding |
| HashSet | O(n) | Cycle detection (simpler but more space) |
| Two Pointers | O(1) | Sorted arrays, opposite directions |
| Sliding Window | O(1) | Subarray problems |

## Practice Strategy

1. **Week 1**: Master basic cycle detection (Problems 1-3)
2. **Week 2**: Learn cycle start finding (Problems 4-5)
3. **Week 3**: Apply to complex scenarios (Problems 6-8)
4. **Week 4**: Advanced applications (Problems 9-10)

---

**Author**: Pankaj Kumar Makwana
**Last Updated**: 2025-11-11
**Total Problems**: 10 (9 with full implementation + 1 with approach)
