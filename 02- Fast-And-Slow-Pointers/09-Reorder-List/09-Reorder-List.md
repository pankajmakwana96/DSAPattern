# Reorder List

**LeetCode Link:** https://leetcode.com/problems/reorder-list/

**Difficulty:** Medium

**Pattern:** Fast and Slow Pointers

## Problem Description

You are given the head of a singly linked-list. The list can be represented as:
```
L0 → L1 → … → Ln-1 → Ln
```

Reorder the list to be on the following form:
```
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

**Example 1:**
```
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```

**Example 2:**
```
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```

## Approach: Find Middle + Reverse + Merge

**Intuition:**
- Split list into two halves at middle
- Reverse the second half
- Merge the two halves alternately

**Algorithm:**
1. **Find middle**: Use fast-slow pointers
2. **Split**: Separate into two lists
3. **Reverse second half**: Reverse in-place
4. **Merge alternately**: Weave nodes from both lists

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Detailed Steps

### Step 1: Find Middle
```
1 → 2 → 3 → 4 → 5
S,F

1 → 2 → 3 → 4 → 5
    S       F

1 → 2 → 3 → 4 → 5
        S           F(null)

Middle = 3
```

### Step 2: Split into Two Lists
```
First half:  1 → 2 → 3 → null
Second half: 4 → 5 → null
```

### Step 3: Reverse Second Half
```
First half:  1 → 2 → 3
Second half: 5 → 4 (reversed)
```

### Step 4: Merge Alternately
```
Take from first:  1
Take from second: 5
Take from first:  2
Take from second: 4
Take from first:  3

Result: 1 → 5 → 2 → 4 → 3
```

## Code Implementation

See: `ReorderList.java` and `ReorderList.cpp`

## Key Takeaways

1. **Combines three techniques**: Find middle + Reverse + Merge
2. **In-place reordering**: O(1) extra space
3. **Three distinct phases**: Each phase is straightforward
4. **No value modification**: Only pointer manipulation
5. **Handles odd and even lengths**: Works for both

## Visual Example - Even Length

```
Input: 1 → 2 → 3 → 4

After finding middle and splitting:
L1: 1 → 2
L2: 3 → 4

After reversing L2:
L1: 1 → 2
L2: 4 → 3

Merging:
1 → 4 → 2 → 3

Result: [1,4,2,3] ✓
```

## Visual Example - Odd Length

```
Input: 1 → 2 → 3 → 4 → 5

After finding middle and splitting:
L1: 1 → 2 → 3
L2: 4 → 5

After reversing L2:
L1: 1 → 2 → 3
L2: 5 → 4

Merging:
1 → 5 → 2 → 4 → 3

Result: [1,5,2,4,3] ✓
```

## Edge Cases

1. **Empty list**: null → null
2. **Single node**: [1] → [1]
3. **Two nodes**: [1,2] → [1,2]
4. **Three nodes**: [1,2,3] → [1,3,2]

## Common Pitfalls

1. Not properly splitting the list (forgetting to set middle.next = null)
2. Losing reference to second half after split
3. Incorrect merge logic (not alternating properly)
4. Off-by-one errors with odd/even length lists
5. Not handling edge cases (null, single node)

## Why Three Phases?

**Alternative approach**: Use stack or array (O(n) space)

**Three-phase approach advantages:**
- O(1) space
- Demonstrates multiple linked list techniques
- Each phase is simple and testable
- Shows strong problem-solving skills

## Implementation Details

### Phase 1: Find Middle
```java
ListNode slow = head, fast = head;
while (fast.next != null && fast.next.next != null) {
    slow = slow.next;
    fast = fast.next.next;
}
// slow is now at end of first half
```

### Phase 2: Reverse Second Half
```java
ListNode prev = null, curr = secondHalf;
while (curr != null) {
    ListNode next = curr.next;
    curr.next = prev;
    prev = curr;
    curr = next;
}
// prev is new head of reversed second half
```

### Phase 3: Merge
```java
ListNode first = head, second = reversedSecondHalf;
while (second != null) {
    ListNode tmp1 = first.next;
    ListNode tmp2 = second.next;
    first.next = second;
    second.next = tmp1;
    first = tmp1;
    second = tmp2;
}
```

## Related Problems

- Palindrome Linked List (similar structure)
- Reverse Linked List II
- Merge Two Sorted Lists
- Middle of Linked List
