# Create Maximum Number

**LeetCode Link:** https://leetcode.com/problems/create-maximum-number/

**Difficulty:** Hard

**Pattern:** Two Pointers + Greedy + Divide and Conquer

## Problem Description

You are given two integer arrays `nums1` and `nums2` of lengths `m` and `n` respectively. `nums1` and `nums2` represent the digits of two numbers. You are also given an integer `k`.

Create the maximum number of length `k <= m + n` from digits of the two arrays. The relative order of the digits from the same array must be preserved.

Return an array of the `k` digits representing the answer.

**Example 1:**
```
Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3]
```

**Example 2:**
```
Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
Output: [6,7,6,0,4]
```

**Example 3:**
```
Input: nums1 = [3,9], nums2 = [8,9], k = 3
Output: [9,8,9]
```

## Approach: Divide and Conquer + Merge

**Intuition:**
- Split k into two parts: take i elements from nums1 and k-i from nums2
- For each split, find maximum subsequence of length i from nums1
- Find maximum subsequence of length k-i from nums2
- Merge them to get maximum number
- Try all possible splits and return maximum

**Key Observations:**
1. Problem splits into three subproblems:
   - Find max subsequence of length x from an array
   - Merge two sequences to get lexicographically largest
   - Try all valid splits

2. For each valid split (i from 0 to k):
   - i elements from nums1 (where i <= m and k-i <= n)
   - k-i elements from nums2

**Algorithm:**

### Part 1: Max Subsequence of Length k from Array
```java
int[] maxSubsequence(int[] nums, int k) {
    int[] stack = new int[k];
    int top = 0;
    int toRemove = nums.length - k; // Elements we can skip

    for (int num : nums) {
        // Pop smaller elements while we have removals left
        while (top > 0 && stack[top-1] < num && toRemove > 0) {
            top--;
            toRemove--;
        }

        if (top < k) {
            stack[top++] = num;
        } else {
            toRemove--;
        }
    }

    return stack;
}
```

### Part 2: Merge Two Sequences
```java
int[] merge(int[] nums1, int[] nums2) {
    int[] result = new int[nums1.length + nums2.length];
    int i = 0, j = 0, k = 0;

    while (i < nums1.length || j < nums2.length) {
        if (isGreater(nums1, i, nums2, j)) {
            result[k++] = nums1[i++];
        } else {
            result[k++] = nums2[j++];
        }
    }

    return result;
}

boolean isGreater(int[] nums1, int i, int[] nums2, int j) {
    while (i < nums1.length && j < nums2.length && nums1[i] == nums2[j]) {
        i++;
        j++;
    }
    return j >= nums2.length || (i < nums1.length && nums1[i] > nums2[j]);
}
```

### Part 3: Main Algorithm
```java
public int[] maxNumber(int[] nums1, int[] nums2, int k) {
    int m = nums1.length, n = nums2.length;
    int[] maxResult = new int[k];

    // Try all possible splits
    for (int i = Math.max(0, k - n); i <= Math.min(k, m); i++) {
        int[] sub1 = maxSubsequence(nums1, i);
        int[] sub2 = maxSubsequence(nums2, k - i);
        int[] merged = merge(sub1, sub2);

        if (isGreater(merged, 0, maxResult, 0)) {
            maxResult = merged;
        }
    }

    return maxResult;
}
```

**Time Complexity:** O(k * (m + n)²)
- O(k) splits to try
- O(m + n) for each maxSubsequence
- O(m + n) for merge
- Comparison can be O(m + n)

**Space Complexity:** O(k)

## Visual Example

```
nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5

Try split i=2 (2 from nums1, 3 from nums2):
  maxSubseq(nums1, 2) = [6,5]
  maxSubseq(nums2, 3) = [9,8,3]
  merge([6,5], [9,8,3]) = [9,8,6,5,3]

Try all splits and take maximum: [9,8,6,5,3]
```

## Key Takeaways

1. Divide problem into: select, merge, compare
2. Monotonic stack for max subsequence
3. Greedy merging with lookahead comparison
4. Try all valid splits of k
5. Complex problem requiring multiple techniques

## Common Pitfalls

1. Not trying all valid splits
2. Incorrect merge comparison (need lookahead)
3. Off-by-one in max subsequence selection
4. Not handling edge cases (k = 0, k = m + n)
5. Time limit exceeded without optimization
