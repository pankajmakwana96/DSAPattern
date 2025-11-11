# Next Palindrome Using Same Digits

**LeetCode Link:** https://leetcode.com/problems/next-palindrome-using-same-digits/

**Difficulty:** Hard

**Pattern:** Two Pointers + Next Permutation

## Problem Description

You are given a numeric string `num`, representing a very large palindrome.

Return the smallest palindrome larger than `num` that can be created by rearranging its digits. If no such palindrome exists, return an empty string `""`.

A palindrome is a number that reads the same forward and backward.

**Example 1:**
```
Input: num = "1221"
Output: "2112"
Explanation: The next palindrome larger than "1221" is "2112".
```

**Example 2:**
```
Input: num = "32123"
Output: ""
Explanation: No palindromes larger than "32123" can be made by rearranging the digits.
```

**Example 3:**
```
Input: num = "45544"
Output: "54445"
```

## Approach: Next Permutation on First Half

**Intuition:**
- A palindrome is determined by its first half
- To get next palindrome, find next permutation of first half
- Mirror the result to create full palindrome
- If no next permutation exists, return empty string

**Key Observations:**
1. Only need to work with first half of palindrome
2. Apply next permutation algorithm to first half
3. Mirror to create the palindrome
4. For odd-length, middle character stays in place

**Algorithm:**
1. Extract first half:
   - For even length n: first n/2 characters
   - For odd length n: first n/2 characters (excluding middle)
2. Find next permutation of first half:
   - Find rightmost position i where digit[i] < digit[i+1]
   - If no such i exists, return "" (no next permutation)
   - Find smallest digit on right of i that is larger than digit[i]
   - Swap them
   - Reverse the suffix after i
3. Mirror first half to second half
4. For odd length, keep middle character unchanged

**Time Complexity:** O(n)
**Space Complexity:** O(n)

## Next Permutation Algorithm

```java
boolean nextPermutation(char[] arr, int end) {
    // Find rightmost i where arr[i] < arr[i+1]
    int i = end - 1;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i < 0) return false; // No next permutation

    // Find smallest element on right that's larger than arr[i]
    int j = end;
    while (arr[j] <= arr[i]) {
        j--;
    }

    // Swap
    swap(arr, i, j);

    // Reverse suffix
    reverse(arr, i + 1, end);

    return true;
}
```

## Complete Solution

```java
public String nextPalindrome(String num) {
    char[] chars = num.toCharArray();
    int n = chars.length;
    int mid = n / 2;

    // Get next permutation of first half
    boolean hasNext;
    if (n % 2 == 0) {
        hasNext = nextPermutation(chars, mid - 1);
    } else {
        hasNext = nextPermutation(chars, mid - 1);
    }

    if (!hasNext) {
        return "";
    }

    // Mirror first half to second half
    for (int i = 0; i < mid; i++) {
        chars[n - 1 - i] = chars[i];
    }

    return new String(chars);
}
```

## Visual Example

```
num = "1221"
n = 4, mid = 2

First half: "12"

Next permutation of "12": "21"

Mirror to create palindrome: "2112"

Result: "2112"
```

```
num = "32123"
n = 5, mid = 2

First half: "32" (excluding middle '1')

Next permutation of "32": Does not exist (descending order)

Result: ""
```

## Key Takeaways

1. Palindrome problem reduces to first half manipulation
2. Next permutation algorithm is key
3. Mirror the result to maintain palindrome property
4. Handle odd/even length strings differently
5. No next permutation means no larger palindrome

## Common Pitfalls

1. Not handling odd vs even length correctly
2. Not understanding next permutation algorithm
3. Forgetting to mirror the first half
4. Not preserving middle character in odd-length
5. Off-by-one errors in indexing
