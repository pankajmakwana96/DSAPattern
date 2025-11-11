# Lowest Common Ancestor of a Binary Tree III

**LeetCode Link:** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/ (Premium)

**Difficulty:** Medium

**Pattern:** Two Pointers

## Problem Description

Given two nodes of a binary tree `p` and `q`, return their lowest common ancestor (LCA).

Each node has a reference to its parent node. The definition for `Node` is below:

```java
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
```

According to the definition of LCA: "The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."

**Example 1:**
```
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

Input: root = 3, p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

**Example 2:**
```
Input: root = 3, p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself.
```

## Approaches

### Approach 1: Path to Root + Compare

**Intuition:**
- Get paths from both nodes to root
- Find the first common node in the paths

**Algorithm:**
1. Store path from p to root in a set
2. Traverse from q to root
3. First node found in the set is the LCA

**Time Complexity:** O(h) where h is height
**Space Complexity:** O(h) for the set

### Approach 2: Two Pointers - Path Intersection (Optimal)

**Intuition:**
- Similar to finding intersection of two linked lists
- Use two pointers starting from p and q
- Move them up simultaneously
- When one reaches root, redirect it to the other starting node
- They will meet at LCA

**Why this works:**
- Let's say depth of p is dp, depth of q is dq
- Distance from p to LCA is d1, from q to LCA is d2
- When p1 reaches root, it has traveled dp steps
- Redirect to q, it will travel dq more steps before reaching LCA
- Total: dp + d2
- Similarly p2 travels: dq + d1
- Since d1 + distance(LCA to root) = dp and d2 + distance(LCA to root) = dq
- Both will meet at LCA

**Algorithm:**
1. Initialize p1 = p, p2 = q
2. While p1 != p2:
   - p1 = p1.parent (if p1.parent exists, else p1 = q)
   - p2 = p2.parent (if p2.parent exists, else p2 = p)
3. Return p1 (or p2, they're equal)

**Time Complexity:** O(h) where h is height
**Space Complexity:** O(1)

## Code Implementation

### Java Solution
See: `LowestCommonAncestorBinaryTreeIII.java`

### C++ Solution
See: `LowestCommonAncestorBinaryTreeIII.cpp`

## Key Takeaways

1. Parent pointers transform tree problem into linked list problem
2. Path intersection technique works for tree LCA
3. Two pointers eliminate need for extra space
4. Redirect to other node equalizes path lengths automatically
5. Similar to linked list intersection problem

## Visual Example

```
Tree:
        3
       / \
      5   1
     / \
    6   2

Find LCA(6, 2):

p1 path: 6 → 5 → 3 → null → (redirect to 2) → 5
p2 path: 2 → 5 → 3 → null → (redirect to 6) → 5

They meet at 5, which is the LCA!
```

## Common Pitfalls

1. Not handling case where one node is ancestor of other
2. Infinite loop if not redirecting properly
3. Not checking for null parent
4. Off-by-one errors in traversal
