# Two Pointers Pattern

## Overview

The Two Pointers pattern is a common algorithmic technique used to solve array and string problems efficiently. It involves using two pointers that traverse the data structure in a coordinated manner, often reducing time complexity from O(n²) to O(n).

## When to Use Two Pointers

1. **Sorted Arrays/Strings**: When dealing with sorted data, two pointers can help find pairs or triplets
2. **Palindrome Problems**: Check from both ends moving toward the center
3. **Array Partitioning**: Segregate elements based on certain conditions
4. **Linked Lists**: Fast and slow pointers for cycle detection or finding middle
5. **Sliding Window**: Maintain a window while traversing

## Types of Two Pointers

### 1. Opposite Direction (Converging)
- Start from both ends and move toward the center
- Used in: Palindrome checking, Two Sum in sorted array, Container With Most Water
- Example: `left = 0, right = n-1`, move inward

### 2. Same Direction (Slow & Fast)
- Both pointers move in the same direction at different speeds
- Used in: Removing duplicates, Linked list cycle detection, Sliding window
- Example: `slow = 0, fast = 0`, fast moves ahead

### 3. Fixed Gap
- Maintain a fixed distance between pointers
- Used in: Remove Nth Node from End
- Example: `fast moves n steps ahead, then both move together`

## Time and Space Complexity

- **Time**: Usually O(n) - single pass through the data
- **Space**: Usually O(1) - only using pointer variables

## Problems Covered

### Easy Problems
1. **Valid Palindrome** - Check if string reads same backward
2. **Reverse String** - Reverse character array in-place
3. **Squares of a Sorted Array** - Square and sort in O(n) time
4. **Valid Word Abbreviation** - Match word with abbreviated version
5. **Strobogrammatic Number** - Number looks same upside down

### Medium Problems
6. **3Sum** - Find all triplets that sum to zero
7. **Remove Nth Node from End of List** - Remove node using fast/slow pointers
8. **Sort Colors** - Dutch National Flag problem (3 pointers)
9. **Reverse Words in a String** - Reverse word order with space handling
10. **Valid Palindrome II** - Palindrome with at most one deletion
11. **Count Pairs Whose Sum is Less than Target** - Counting pairs efficiently
12. **Append Characters to String to Make Subsequence** - String matching
13. **Lowest Common Ancestor of a Binary Tree III** - Two pointers on tree paths

### Hard Problems
14. **Minimum Number of Moves to Make Palindrome** - Greedy with two pointers
15. **Next Palindrome Using Same Digits** - Next permutation variation
16. **Count Subarrays With Fixed Bounds** - Sliding window with constraints
17. **Get the Maximum Score** - Two arrays with path switching
18. **Find the Lexicographically Largest String From Box II** - Greedy selection
19. **Create Maximum Number** - Merge two arrays optimally

## Problem List with Links

| # | Problem | Difficulty | LeetCode Link | Implementation |
|---|---------|------------|---------------|----------------|
| 1 | Valid Palindrome | Easy | [Link](https://leetcode.com/problems/valid-palindrome/) | ✅ Full (Java, C++) |
| 2 | 3Sum | Medium | [Link](https://leetcode.com/problems/3sum/) | ✅ Full (Java, C++) |
| 3 | Remove Nth Node from End of List | Medium | [Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | ✅ Full (Java, C++) |
| 4 | Sort Colors | Medium | [Link](https://leetcode.com/problems/sort-colors/) | ✅ Full (Java, C++) |
| 5 | Reverse Words in a String | Medium | [Link](https://leetcode.com/problems/reverse-words-in-a-string/) | ✅ Full (Java, C++) |
| 6 | Valid Word Abbreviation | Easy | [Link](https://leetcode.com/problems/valid-word-abbreviation/) | ✅ Full (Java, C++) |
| 7 | Strobogrammatic Number | Easy | [Link](https://leetcode.com/problems/strobogrammatic-number/) | ✅ Full (Java, C++) |
| 8 | Count Pairs Sum Less Than Target | Easy | [Link](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/) | ✅ Full (Java, C++) |
| 9 | Append Characters to Make Subsequence | Medium | [Link](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/) | ✅ Full (Java, C++) |
| 10 | Lowest Common Ancestor Binary Tree III | Medium | [Link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/) | ✅ Full (Java, C++) |
| 11 | Count Subarrays With Fixed Bounds | Hard | [Link](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/) | ✅ Full (Java, C++) |
| 12 | Squares of a Sorted Array | Easy | [Link](https://leetcode.com/problems/squares-of-a-sorted-array/) | ✅ Full (Java, C++) |
| 13 | Reverse String | Easy | [Link](https://leetcode.com/problems/reverse-string/) | ✅ Full (Java, C++) |
| 14 | Valid Palindrome II | Easy | [Link](https://leetcode.com/problems/valid-palindrome-ii/) | ✅ Full (Java, C++) |
| 15 | Get the Maximum Score | Hard | [Link](https://leetcode.com/problems/get-the-maximum-score/) | 📖 Approach Only |
| 16 | Minimum Moves to Make Palindrome | Hard | [Link](https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/) | 📖 Approach Only |
| 17 | Next Palindrome Using Same Digits | Hard | [Link](https://leetcode.com/problems/next-palindrome-using-same-digits/) | 📖 Approach Only |
| 18 | Lexicographically Largest String Box II | Hard | [Link](https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-ii/) | 📖 Approach Only |
| 19 | Create Maximum Number | Hard | [Link](https://leetcode.com/problems/create-maximum-number/) | 📖 Approach Only |

## Key Patterns and Techniques

### 1. Palindrome Checking
```
left = 0, right = n-1
while left < right:
    if arr[left] != arr[right]: return false
    left++, right--
```

### 2. Two Sum (Sorted Array)
```
left = 0, right = n-1
while left < right:
    sum = arr[left] + arr[right]
    if sum == target: found
    if sum < target: left++
    if sum > target: right--
```

### 3. Remove Duplicates
```
slow = 0
for fast = 1 to n-1:
    if arr[fast] != arr[slow]:
        slow++
        arr[slow] = arr[fast]
```

### 4. Dutch National Flag (3 Pointers)
```
low = 0, mid = 0, high = n-1
while mid <= high:
    if arr[mid] == 0: swap(low++, mid++)
    if arr[mid] == 1: mid++
    if arr[mid] == 2: swap(mid, high--)
```

## Tips and Tricks

1. **Sort First**: Many two-pointer problems require sorted data
2. **Skip Duplicates**: Use `while` loops to skip duplicate elements
3. **Edge Cases**: Empty arrays, single element, all same elements
4. **Pointer Bounds**: Always check `left < right` or `left <= right` based on problem
5. **In-Place Operations**: Two pointers often enable in-place modifications

## Common Mistakes

1. Not handling edge cases (empty input, single element)
2. Off-by-one errors in pointer initialization or movement
3. Not skipping duplicates properly
4. Incrementing/decrementing wrong pointer
5. Not checking bounds before accessing array elements

## Resources

- [LeetCode Two Pointers Tag](https://leetcode.com/tag/two-pointers/)
- Time Complexity: Most problems are O(n) or O(n²) for nested scenarios
- Space Complexity: Usually O(1) for in-place operations

## How to Practice

1. Start with easy palindrome problems
2. Move to sorting and partitioning problems
3. Practice linked list problems with fast/slow pointers
4. Attempt harder problems with multiple constraints
5. Focus on edge cases and optimization

---

**Author**: Pankaj Kumar Makwana
**Last Updated**: 2025-11-11
