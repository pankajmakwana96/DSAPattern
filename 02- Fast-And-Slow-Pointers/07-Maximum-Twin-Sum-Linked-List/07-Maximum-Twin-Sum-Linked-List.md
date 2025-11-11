# Maximum Twin Sum of a Linked List

**LeetCode Link:** https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

**Difficulty:** Medium

**Pattern:** Fast and Slow Pointers

## Problem Description

In a linked list of size `n`, where `n` is **even**, the `i-th` node (0-indexed) of the linked list is known as the **twin** of the `(n-1-i)-th` node, if `0 <= i <= (n / 2) - 1`.

For example, if `n = 4`, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for `n = 4`.

The **twin sum** is defined as the sum of a node and its twin.

Given the `head` of a linked list with even length, return the **maximum twin sum** of the linked list.

**Example 1:**
```
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum is 6.
```

**Example 2:**
```
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins are:
- Node 0 is the twin of node 3 with twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 with twin sum of 2 + 2 = 4.
Thus, the maximum twin sum is max(7, 4) = 7.
```

**Example 3:**
```
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
```

## Approach: Fast-Slow Pointers + Reverse Second Half

**Intuition:**
- Twin pairs are symmetric from both ends
- Find middle using fast-slow pointers
- Reverse second half
- Traverse both halves simultaneously to find max twin sum

**Algorithm:**
1. Find middle of list using fast-slow pointers
2. Reverse second half of list
3. Iterate through first half and reversed second half together
4. Calculate twin sum for each pair
5. Track maximum twin sum

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Code Implementation

See: `MaximumTwinSum.java` and `MaximumTwinSum.cpp`

## Key Takeaways

1. **Combines**: Finding middle + Reversing + Two-pointer traversal
2. **Twin relationship**: i-th node pairs with (n-1-i)-th node
3. **Guaranteed even length**: Simplifies middle finding
4. **O(1) space**: In-place reversal
5. **Single pass calculation**: After setup

## Visual Example

```
Input: [5,4,2,1]

Step 1: Find middle
5 → 4 → 2 → 1
    M

Step 2: Reverse second half
5 → 4    1 → 2
First    Second (reversed)

Step 3: Calculate twin sums
Twin 0: 5 + 1 = 6
Twin 1: 4 + 2 = 6

Maximum = 6
```

```
Input: [4,2,2,3]

After middle and reverse:
4 → 2    3 → 2

Twin sums:
4 + 3 = 7  ✓ (max)
2 + 2 = 4

Maximum = 7
```

## Edge Cases

1. **Minimum length (n=2)**: [1,2] → 3
2. **All same**: [5,5,5,5] → 10
3. **Large values**: [1,100000] → 100001
4. **Increasing**: [1,2,3,4] → 5

## Common Pitfalls

1. Forgetting list length is always even
2. Not reversing second half properly
3. Off-by-one errors in pairing
4. Integer overflow with large sums
5. Not initializing max to MIN_VALUE

## Why Reverse Second Half?

**Alternative**: Store first half in array (O(n) space)

**Reversal approach benefits:**
- O(1) space
- Efficient linear traversal
- Can restore list if needed
- Demonstrates strong linked list manipulation skills

## Step-by-Step Breakdown

### Step 1: Find Middle (O(n/2))
```java
ListNode slow = head, fast = head;
while (fast != null && fast.next != null) {
    slow = slow.next;
    fast = fast.next.next;
}
// slow is now at middle
```

### Step 2: Reverse Second Half (O(n/2))
```java
ListNode prev = null, curr = slow;
while (curr != null) {
    ListNode next = curr.next;
    curr.next = prev;
    prev = curr;
    curr = next;
}
// prev is head of reversed second half
```

### Step 3: Calculate Max Twin Sum (O(n/2))
```java
int maxSum = 0;
ListNode first = head, second = prev;
while (second != null) {
    maxSum = Math.max(maxSum, first.val + second.val);
    first = first.next;
    second = second.next;
}
```

## Related Problems

- Palindrome Linked List (similar structure)
- Middle of Linked List
- Reverse Linked List II
- Reorder List
