# Fast and Slow Pointers - Quick Reference

## Core Pattern

```java
// Basic Cycle Detection
ListNode slow = head, fast = head;
while (fast != null && fast.next != null) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow == fast) return true;  // Cycle found
}
return false;  // No cycle
```

## Common Templates

### 1. Detect Cycle
```java
boolean hasCycle(ListNode head) {
    if (head == null) return false;
    ListNode slow = head, fast = head;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) return true;
    }
    return false;
}
```

### 2. Find Middle of List
```java
ListNode findMiddle(ListNode head) {
    ListNode slow = head, fast = head;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;  // Middle node
}
```

### 3. Find Cycle Start (Floyd's Algorithm)
```java
ListNode detectCycle(ListNode head) {
    ListNode slow = head, fast = head;

    // Phase 1: Detect if cycle exists
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) break;
    }

    if (fast == null || fast.next == null) return null;

    // Phase 2: Find cycle start
    slow = head;
    while (slow != fast) {
        slow = slow.next;
        fast = fast.next;
    }
    return slow;
}
```

### 4. Check Palindrome List
```java
boolean isPalindrome(ListNode head) {
    // Find middle
    ListNode slow = head, fast = head;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }

    // Reverse second half
    ListNode prev = null, curr = slow;
    while (curr != null) {
        ListNode next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }

    // Compare both halves
    ListNode left = head, right = prev;
    while (right != null) {
        if (left.val != right.val) return false;
        left = left.next;
        right = right.next;
    }
    return true;
}
```

## Key Points

✅ **Always check**: `fast != null && fast.next != null`
✅ **Slow moves**: 1 step at a time
✅ **Fast moves**: 2 steps at a time
✅ **Meeting guaranteed**: If cycle exists, they WILL meet
✅ **Space**: O(1) - Major advantage over HashSet

## Problem Quick Guide

| Problem | Key Insight | Template |
|---------|-------------|----------|
| Happy Number | Sequence forms implicit list | Cycle Detection |
| Linked List Cycle | Classic Floyd's algorithm | Cycle Detection |
| Middle of List | Fast reaches end, slow at middle | Find Middle |
| Find Duplicate | Array indices form linked list | Cycle Detection + Start |
| Palindrome List | Find middle + reverse + compare | Find Middle + Reverse |
| Cycle Start | Two phases: detect + find | Floyd's Full Algorithm |

## Common Edge Cases

```java
// Always handle these:
if (head == null) return ...;
if (head.next == null) return ...;
if (fast == null || fast.next == null) return ...;
```

## Time & Space Complexity

- **Time**: O(n) - Each node visited at most twice
- **Space**: O(1) - Only two pointers

## When to Use This Pattern

✅ Detecting cycles in linked lists
✅ Finding middle element
✅ Checking palindromes in lists
✅ Finding duplicate in array (special case)
✅ Any "meeting point" problem

❌ Need to track all visited nodes
❌ Need specific path information
❌ Working with tree structures (use different approach)

## Debugging Tips

1. **Print pointer positions** at each step
2. **Check null conditions** before dereferencing
3. **Verify loop condition** (not just `fast != null`)
4. **Test with small cases** (1-2 nodes)
5. **Draw diagrams** for complex cycles

## Common Mistakes

❌ `while (fast != null)` - Missing fast.next check
❌ `fast = fast.next` - Fast should move 2 steps
❌ Starting pointers at different positions unnecessarily
❌ Not resetting pointer in two-phase algorithms
❌ Modifying list when only reading is allowed

## Interview Pro Tips

1. **Start simple**: Explain brute force (HashSet) first
2. **Optimize**: Then introduce fast-slow pointers
3. **Draw it**: Visual explanation helps interviewer
4. **Test edge cases**: Empty, single node, no cycle
5. **Analyze complexity**: Emphasize O(1) space benefit

---

**Remember**: If there's a potential cycle and you need O(1) space, think Fast and Slow Pointers!
