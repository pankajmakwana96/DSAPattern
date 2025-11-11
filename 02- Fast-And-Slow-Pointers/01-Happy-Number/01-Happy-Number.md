# Happy Number

**LeetCode Link:** https://leetcode.com/problems/happy-number/

**Difficulty:** Easy

**Pattern:** Fast and Slow Pointers

## Problem Description

Write an algorithm to determine if a number `n` is happy.

A **happy number** is a number defined by the following process:
- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
- Those numbers for which this process ends in 1 are happy.

Return `true` if `n` is a happy number, and `false` if not.

**Example 1:**
```
Input: n = 19
Output: true
Explanation:
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1
```

**Example 2:**
```
Input: n = 2
Output: false
Explanation: The sequence enters a cycle and never reaches 1.
```

## Approaches

### Approach 1: HashSet

**Intuition:**
- Keep track of all numbers seen during the process
- If we see a number again, we're in a cycle (not happy)
- If we reach 1, the number is happy

**Time Complexity:** O(log n) - Number of digits determines iterations
**Space Complexity:** O(log n) - Storing seen numbers

### Approach 2: Fast and Slow Pointers (Optimal)

**Intuition:**
- Treat the sequence as a linked list where each number points to its next number
- Use Floyd's cycle detection algorithm
- Slow pointer moves one step, fast pointer moves two steps
- If they meet at 1, number is happy
- If they meet elsewhere, there's a cycle (not happy)

**Algorithm:**
1. Initialize slow = n, fast = n
2. Repeat:
   - slow = getNext(slow)  // one step
   - fast = getNext(getNext(fast))  // two steps
   - If fast == 1, return true
   - If slow == fast, cycle detected (return false)
3. Helper function getNext(): sum of squares of digits

**Time Complexity:** O(log n)
**Space Complexity:** O(1) - Only using two pointers

**Why does this work?**
- If there's a cycle (not reaching 1), fast and slow will eventually meet
- If the number is happy, fast will reach 1 before meeting slow
- No extra space needed unlike HashSet approach

## Code Implementation

### Java Solution
See: `HappyNumber.java`

### C++ Solution
See: `HappyNumber.cpp`

## Key Takeaways

1. Non-intuitive use of fast-slow pointers for number sequences
2. Cycle detection doesn't require explicit linked list structure
3. Any sequence that repeats can use this pattern
4. Space optimization: O(n) → O(1)
5. Mathematical observation: all unhappy numbers eventually cycle

## Helper Function

The key is calculating the next number:

```java
int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}
```

## Visual Example

```
n = 19

Slow path (1 step):
19 → 82 → 68 → 100 → 1

Fast path (2 steps):
19 → 68 → 1

Fast reaches 1 first!
Result: true (happy number)
```

```
n = 2

Both paths will eventually cycle:
2 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 (cycle!)

Slow and fast meet at some point in this cycle.
Result: false (not happy)
```

## Edge Cases

1. n = 1: Already happy (return true immediately)
2. n = 7: Happy number (reaches 1)
3. Single digit unhappy numbers: Will cycle
4. Large numbers: Still works efficiently

## Common Pitfalls

1. Not handling the case when fast reaches 1
2. Incorrect digit sum calculation
3. Infinite loop if not checking for cycles
4. Not moving fast pointer two steps

## Why This Problem Uses Fast-Slow Pointers

- Sequence of numbers forms an implicit "linked list"
- Each number "points to" its next number
- Either reaches 1 (end) or cycles
- Perfect for Floyd's cycle detection

## Alternative Approaches

**1. HashSet Approach:**
- Easier to understand
- O(n) space
- Good for interviews if asked for simpler solution first

**2. Mathematical Observation:**
- For numbers < 1000, there are only a few possible cycles
- Can hardcode known unhappy cycles
- Not generalizable or elegant

## Related Problems

- Find the Duplicate Number
- Linked List Cycle
- Any sequence with potential cycles
