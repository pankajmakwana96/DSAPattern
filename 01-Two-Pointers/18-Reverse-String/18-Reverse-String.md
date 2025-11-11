# Reverse String

**LeetCode Link:** https://leetcode.com/problems/reverse-string/

**Difficulty:** Easy

**Pattern:** Two Pointers

## Problem Description

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array in-place with O(1) extra memory.

**Example 1:**
```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

**Example 2:**
```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

## Approaches

### Approach 1: Two Pointers from Both Ends (Optimal)

**Intuition:**
- Use two pointers, one at the start and one at the end
- Swap characters at both pointers
- Move pointers toward the center
- Stop when pointers meet or cross

**Algorithm:**
1. Initialize left = 0, right = n-1
2. While left < right:
   - Swap s[left] and s[right]
   - Increment left
   - Decrement right
3. Array is now reversed

**Time Complexity:** O(n) - Visit each element once
**Space Complexity:** O(1) - Only using two pointer variables

### Approach 2: Recursion

**Intuition:**
- Recursively swap characters from both ends
- Base case: left >= right

**Algorithm:**
```java
void reverseString(char[] s, int left, int right) {
    if (left >= right) return;
    // Swap
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    // Recursive call
    reverseString(s, left + 1, right - 1);
}
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) - Recursion stack

**Note:** Approach 1 is preferred due to O(1) space requirement.

### Approach 3: Using Built-in Functions

**Intuition:**
- Many languages have built-in reverse functions
- In C++: `std::reverse(s.begin(), s.end())`
- In Python: `s.reverse()`

**Time Complexity:** O(n)
**Space Complexity:** O(1)

## Code Implementation

### Java Solution
See: `ReverseString.java`

### C++ Solution
See: `ReverseString.cpp`

## Key Takeaways

1. Two pointers from both ends is the classic approach for reversals
2. Swapping in-place saves space
3. The condition `left < right` ensures we don't swap twice
4. Works for both even and odd length arrays
5. This is a fundamental technique used in many other problems

## Visual Example

```
Input: ['h', 'e', 'l', 'l', 'o']

Step 1: left=0, right=4
        Swap 'h' and 'o'
        ['o', 'e', 'l', 'l', 'h']

Step 2: left=1, right=3
        Swap 'e' and 'l'
        ['o', 'l', 'l', 'e', 'h']

Step 3: left=2, right=2
        left == right, stop

Result: ['o', 'l', 'l', 'e', 'h']
```

## Swap Techniques

### Standard Swap with Temp Variable
```java
char temp = s[left];
s[left] = s[right];
s[right] = temp;
```

### XOR Swap (without temp variable)
```java
s[left] ^= s[right];
s[right] ^= s[left];
s[left] ^= s[right];
```

### Arithmetic Swap (for integers)
```java
a = a + b;
b = a - b;
a = a - b;
```

**Note:** XOR swap works for characters too, but standard swap is more readable.

## Edge Cases

1. Empty array: `[]` → `[]`
2. Single character: `['a']` → `['a']`
3. Two characters: `['a', 'b']` → `['b', 'a']`
4. All same characters: `['a', 'a', 'a']` → `['a', 'a', 'a']`

## Common Pitfalls

1. Not stopping at `left < right` (may swap twice and undo reversal)
2. Creating a new array instead of in-place reversal
3. Off-by-one errors in pointer initialization
4. Using `left <= right` (will swap middle element with itself unnecessarily)

## Applications

This technique is used in:
- Reversing words in a string
- Rotating arrays
- Palindrome checking
- String manipulation problems
- In-place array rearrangement

## Related Problems

- Reverse String II (reverse every 2k characters)
- Reverse Words in a String
- Reverse Vowels of a String
- Valid Palindrome
