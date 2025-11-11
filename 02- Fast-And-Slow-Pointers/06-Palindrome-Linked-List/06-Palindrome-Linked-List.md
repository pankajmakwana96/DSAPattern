# Palindrome Linked List

**LeetCode Link:** https://leetcode.com/problems/palindrome-linked-list/

**Difficulty:** Easy

**Pattern:** Fast and Slow Pointers

## Problem Description

Given the `head` of a singly linked list, return `true` if it is a palindrome or `false` otherwise.

**Example 1:**
```
Input: head = [1,2,2,1]
Output: true
```

**Example 2:**
```
Input: head = [1,2]
Output: false
```

**Follow up:** Could you do it in O(n) time and O(1) space?

## Approaches

### Approach 1: Copy to Array
**Intuition:** Copy values to array, check with two pointers
**Time:** O(n), **Space:** O(n)

### Approach 2: Fast-Slow Pointers + Reverse (Optimal)

**Intuition:**
- Find middle of list using fast-slow pointers
- Reverse second half of list
- Compare first half with reversed second half
- Optionally restore list

**Algorithm:**
1. **Find middle**: Use fast-slow pointers
2. **Reverse second half**: Reverse from middle to end
3. **Compare**: Compare first half with reversed second half
4. **Optional**: Restore list by reversing again

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Detailed Steps

### Step 1: Find Middle
```
1 → 2 → 3 → 2 → 1
S,F

1 → 2 → 3 → 2 → 1
    S       F

1 → 2 → 3 → 2 → 1
        S           F(null)

Middle = 3
```

### Step 2: Reverse Second Half
```
Original: 1 → 2 → 3 → 2 → 1 → null
After:    1 → 2 → 3 ← 2 ← 1

First half: 1 → 2 → 3
Second half: 1 → 2 (reversed)
```

### Step 3: Compare
```
Compare: 1,2  with  1,2 ✓
Result: true (palindrome)
```

## Code Implementation

See: `PalindromeLinkedList.java` and `PalindromeLinkedList.cpp`

## Key Takeaways

1. **Combines two techniques**: Finding middle + Reversing list
2. **O(1) space solution** possible with in-place reversal
3. **Three phases**: Find middle, reverse, compare
4. **Can restore list** if needed (reverse again)
5. **Handles odd and even** length lists correctly

## Visual Example - Odd Length

```
Input: 1 → 2 → 3 → 2 → 1

Step 1: Find middle
slow ends at 3 (middle)

Step 2: Reverse 2 → 1
Result: 1 ← 2
p1 = 1, p2 = 1

Step 3: Compare
1 == 1 ✓
2 == 2 ✓
Result: true
```

## Visual Example - Even Length

```
Input: 1 → 2 → 2 → 1

Step 1: Find middle
slow ends at first 2

Step 2: Reverse 2 → 1
Result: 1 ← 2
p1 = 1, p2 = 1

Step 3: Compare
1 == 1 ✓
2 == 2 ✓
Result: true
```

## Edge Cases

1. **Empty list**: null → true
2. **Single node**: [1] → true
3. **Two nodes same**: [1,1] → true
4. **Two nodes different**: [1,2] → false
5. **All same**: [1,1,1,1] → true

## Common Pitfalls

1. Not handling odd vs even length correctly
2. Losing reference to second half after reversal
3. Not checking if list is empty
4. Off-by-one errors in comparison
5. Forgetting to restore list if required

## Optimization: Do We Need to Restore?

**Pros of restoring:**
- Leaves input unchanged (good practice)
- Allows reusing the list

**Cons:**
- Extra O(n/2) operations
- Most problems don't require it

**Interview tip:** Ask if you need to restore the list!

## Why This Pattern Works

1. **Finding middle**: O(n/2) with fast-slow
2. **Reversing half**: O(n/2) in-place
3. **Comparing**: O(n/2) walk through
4. **Total**: O(n) time, O(1) space ✓

## Comparison with Array Approach

| Aspect | Array Copy | In-Place |
|--------|-----------|----------|
| Time | O(n) | O(n) |
| Space | O(n) | O(1) |
| Implementation | Simpler | More complex |
| Modifies List | No | Yes (can restore) |

## Related Problems

- Middle of Linked List
- Reverse Linked List
- Reverse Linked List II
- Reorder List
