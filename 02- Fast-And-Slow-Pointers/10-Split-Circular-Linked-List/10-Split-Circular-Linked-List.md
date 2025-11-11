# Split Circular Linked List

**LeetCode Link:** https://leetcode.com/problems/split-linked-list-in-parts/ (Related problem)

**Difficulty:** Hard

**Pattern:** Fast and Slow Pointers

## Problem Description

Given a circular linked list, split it into two equal circular linked lists. If the number of nodes is odd, the first list should have one extra node.

A circular linked list is a linked list where all nodes are connected to form a circle. There is no NULL at the end. The last node points back to the first node.

**Example 1:**
```
Input: 1 → 2 → 3 → 4 → 5 → 6 → (back to 1)
Output:
  List 1: 1 → 2 → 3 → (back to 1)
  List 2: 4 → 5 → 6 → (back to 4)
```

**Example 2:**
```
Input: 1 → 2 → 3 → 4 → 5 → (back to 1)
Output:
  List 1: 1 → 2 → 3 → (back to 1)
  List 2: 4 → 5 → (back to 4)
```

**Example 3:**
```
Input: 1 → 2 → (back to 1)
Output:
  List 1: 1 → (self loop)
  List 2: 2 → (self loop)
```

## Approach: Fast and Slow Pointers

**Intuition:**
- Use fast-slow pointers to find the middle of circular list
- Split at the middle point
- Make each half circular again

**Algorithm:**
1. Use slow and fast pointers (slow moves 1, fast moves 2)
2. Count total nodes while finding middle
3. Determine split point (n/2 for even, (n+1)/2 for odd)
4. Traverse to split point and split the list
5. Make both halves circular

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Detailed Steps

### Step 1: Find Middle and Count Nodes

For circular list: 1 → 2 → 3 → 4 → 5 → 6 → (back to 1)

```
Initial: slow = 1, fast = 1, count = 0

Iteration 1:
  slow = 2, fast = 3, count = 1

Iteration 2:
  slow = 3, fast = 5, count = 2

Iteration 3:
  slow = 4, fast = 1 (back to start), count = 3
  STOP when fast reaches head again

Total nodes = 6
Middle point = node 3 (after 3 nodes)
```

### Step 2: Split at Middle

```
Original: 1 → 2 → 3 → 4 → 5 → 6 → (back to 1)
                   ↑ split here

After split:
  List 1: 1 → 2 → 3 → 6 (temporarily)
  List 2: 4 → 5 → 6 (not circular yet)
```

### Step 3: Make Both Halves Circular

```
Find last node of first half (node 3)
Find last node of second half (node 6)

List 1: 1 → 2 → 3 → (back to 1)
List 2: 4 → 5 → 6 → (back to 4)
```

## Key Challenges

1. **Detecting middle in circular list**: Unlike regular list, no NULL to detect end
2. **Counting nodes**: Need to track when we've made full circle
3. **Maintaining circularity**: Both resulting lists must remain circular
4. **Handling odd length**: First list gets extra node

## Detailed Algorithm

```
1. Edge cases:
   - If head is NULL, return (NULL, NULL)
   - If only one node (self loop), return (head, NULL)
   - If only two nodes, split into two single-node circular lists

2. Find middle and count:
   slow = head
   fast = head
   count = 0

   do:
       slow = slow.next
       fast = fast.next.next
       count++
   while (fast != head && fast.next != head)

   if (fast != head):
       count++  // Odd number of nodes

   totalNodes = count * 2 (if fast == head)
                OR count * 2 + 1 (if fast.next == head)

3. Calculate split point:
   splitPoint = (totalNodes + 1) / 2  // First half gets extra if odd

4. Traverse to split point:
   current = head
   for i = 1 to splitPoint - 1:
       current = current.next

   secondHead = current.next  // Start of second list
   current.next = NULL  // Temporarily break

5. Find last node of second half:
   lastOfSecond = secondHead
   while (lastOfSecond.next != head):
       lastOfSecond = lastOfSecond.next

6. Make both circular:
   current.next = head  // Close first circle
   lastOfSecond.next = secondHead  // Close second circle

7. Return (head, secondHead)
```

## Visual Example - Even Length (6 nodes)

```
Input: 1 → 2 → 3 → 4 → 5 → 6 → ↰

Step 1: Find middle
  slow traverses: 1 → 2 → 3 → 4
  fast traverses: 1 → 3 → 5 → 1 (back to start)
  Total nodes: 6

Step 2: Split point = 3
  Traverse to node 3

Step 3: Split
  Node 3.next = 4 (save as secondHead)
  Node 3.next = NULL

Step 4: Find last of second (node 6)
  Node 6.next was pointing to 1

Step 5: Close circles
  Node 3.next = 1
  Node 6.next = 4

Result:
  List 1: 1 → 2 → 3 → ↰
  List 2: 4 → 5 → 6 → ↰
```

## Visual Example - Odd Length (5 nodes)

```
Input: 1 → 2 → 3 → 4 → 5 → ↰

Step 1: Find middle
  Total nodes: 5
  Split point: (5+1)/2 = 3

Step 2-5: Same process

Result:
  List 1: 1 → 2 → 3 → ↰ (3 nodes)
  List 2: 4 → 5 → ↰     (2 nodes)
```

## Edge Cases

1. **NULL list**: Return (NULL, NULL)
2. **Single node**: Return (head, NULL) or create two single-node lists
3. **Two nodes**: Split into two single-node circular lists
4. **Odd length**: First list gets the extra node
5. **Large list**: Algorithm remains O(n)

## Common Pitfalls

1. **Infinite loop**: Forgetting circular nature when traversing
2. **Wrong split point**: Off-by-one errors in calculation
3. **Breaking circularity**: Not properly reconnecting circles
4. **Losing reference**: Losing track of second half's head
5. **Edge case handling**: Not handling 1 or 2 node cases

## Why This Is Hard

1. **No NULL marker**: Can't use traditional list traversal patterns
2. **Careful counting**: Must detect when we've completed full circle
3. **Multiple pointers**: Need to track multiple references carefully
4. **Maintaining invariants**: Must ensure both halves remain circular
5. **Edge cases**: Many special cases to handle

## Alternative Approaches

### Approach 1: Count First, Then Split
**Time:** O(n), **Space:** O(1)
```
1. Count total nodes in one pass
2. Calculate split point
3. Traverse to split point
4. Split and make circular
```
**Pros:** Simpler logic, clearer
**Cons:** Requires two passes (count + split)

### Approach 2: Fast-Slow (Optimal)
**Time:** O(n), **Space:** O(1)
```
1. Use fast-slow to find middle while counting
2. Split at middle
3. Make both halves circular
```
**Pros:** Single pass, demonstrates pointer mastery
**Cons:** More complex logic

### Approach 3: Convert to Array
**Time:** O(n), **Space:** O(n)
```
1. Convert circular list to array
2. Split array in half
3. Reconstruct two circular lists
```
**Pros:** Easier to implement
**Cons:** O(n) extra space, doesn't demonstrate in-place skills

## Comparison Table

| Approach | Time | Space | Difficulty | Interview Score |
|----------|------|-------|------------|-----------------|
| Count First | O(n) | O(1) | Medium | Good |
| Fast-Slow | O(n) | O(1) | Hard | Excellent |
| Array Convert | O(n) | O(n) | Easy | Poor |

## Implementation Considerations

### Detecting Full Circle
```java
// Pattern: Count until we reach start again
ListNode slow = head;
ListNode fast = head;
int count = 0;

do {
    slow = slow.next;
    fast = fast.next.next;
    count++;
} while (fast != head && fast.next != head);

// If fast == head: even number of nodes (count * 2)
// If fast.next == head: odd number of nodes (count * 2 + 1)
```

### Calculating Split Point
```java
int totalNodes;
if (fast == head) {
    totalNodes = count * 2;
} else {
    totalNodes = count * 2 + 1;
}

int splitPoint = (totalNodes + 1) / 2;  // First half gets extra if odd
```

### Splitting Safely
```java
// Save references before breaking links
ListNode firstHead = head;
ListNode secondHead = splitNode.next;
ListNode lastOfFirst = splitNode;

// Find last node of second half (points to firstHead)
ListNode lastOfSecond = secondHead;
while (lastOfSecond.next != firstHead) {
    lastOfSecond = lastOfSecond.next;
}

// Close the circles
lastOfFirst.next = firstHead;
lastOfSecond.next = secondHead;
```

## Interview Tips

1. **Draw it out**: Sketch the circular list and mark pointers
2. **Handle edge cases first**: NULL, 1 node, 2 nodes
3. **Explain the challenge**: Mention lack of NULL marker
4. **Show counting logic**: Clearly explain how to detect full circle
5. **Verify circularity**: Confirm both results are properly circular
6. **Discuss alternatives**: Mention count-first approach as simpler option

## Related Problems

- **Middle of Linked List**: Similar fast-slow technique
- **Linked List Cycle II**: Detecting and measuring cycles
- **Reorder List**: Multi-phase list manipulation
- **Rotate List**: Circular list operations
- **Split Linked List in Parts**: LeetCode variation

## Key Concepts Mastered

- Fast and slow pointers in circular context
- Counting nodes without NULL marker
- Maintaining data structure invariants
- Multiple pointer coordination
- In-place list manipulation with O(1) space

## Practice Strategy

1. **Start with regular list**: Solve "Find Middle" first
2. **Add circularity**: Practice detecting full circles
3. **Count nodes**: Practice counting in circular lists
4. **Split practice**: Practice breaking and reconnecting
5. **Test thoroughly**: Cover all edge cases

## When to Use This Pattern

Use Fast-Slow in circular list when:
- Need to find middle of circular structure
- Must maintain O(1) space
- Want to demonstrate advanced pointer skills
- Circular invariant must be preserved
- No auxiliary data structures allowed

## Mathematical Properties

**For even-length circular list (n nodes):**
- After n/2 steps, slow is at middle
- After n/2 steps, fast returns to start
- Split creates two lists of size n/2

**For odd-length circular list (n nodes):**
- After (n+1)/2 steps, slow is at middle
- After (n-1)/2 steps, fast is one before start
- Split creates lists of size ⌈n/2⌉ and ⌊n/2⌋

## Code Template

```java
class Solution {
    public ListNode[] splitCircularList(ListNode head) {
        // Edge cases
        if (head == null) return new ListNode[]{null, null};
        if (head.next == head) return new ListNode[]{head, null};

        // Find middle and count
        ListNode slow = head, fast = head;
        int count = 0;

        do {
            slow = slow.next;
            fast = fast.next.next;
            count++;
        } while (fast != head && fast.next != head);

        // Calculate total and split point
        int total = (fast == head) ? count * 2 : count * 2 + 1;
        int splitPoint = (total + 1) / 2;

        // Traverse to split
        ListNode curr = head;
        for (int i = 1; i < splitPoint; i++) {
            curr = curr.next;
        }

        // Split and make circular
        ListNode secondHead = curr.next;
        ListNode lastSecond = secondHead;
        while (lastSecond.next != head) {
            lastSecond = lastSecond.next;
        }

        curr.next = head;
        lastSecond.next = secondHead;

        return new ListNode[]{head, secondHead};
    }
}
```

## Summary

The Split Circular Linked List problem combines multiple advanced concepts:
- Fast and slow pointers for finding middle
- Careful counting in circular structures
- In-place manipulation with O(1) space
- Maintaining structural invariants
- Multiple reference tracking

It's an excellent problem to demonstrate mastery of linked list manipulation and the fast-slow pointer pattern in a challenging context.
