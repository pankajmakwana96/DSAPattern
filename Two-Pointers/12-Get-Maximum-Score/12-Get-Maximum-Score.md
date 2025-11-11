# Get the Maximum Score

**LeetCode Link:** https://leetcode.com/problems/get-the-maximum-score/

**Difficulty:** Hard

**Pattern:** Two Pointers + Dynamic Programming

## Problem Description

You are given two sorted arrays of distinct integers `nums1` and `nums2`.

A valid path is defined as follows:
- Choose array `nums1` or `nums2` to traverse (from index 0).
- Traverse the current array from left to right.
- If you are reading any value that is present in `nums1` and `nums2` you are allowed to change your path to the other array.

Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo `10^9 + 7`.

The score is defined as the sum of values in the path.

**Example 1:**
```
Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
Output: 30
Explanation: Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10]
The maximum is obtained with the path [2,4,6,8,9] = 2+4+6+8+9+1 = 30
```

**Example 2:**
```
Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
Output: 109
Explanation: Maximum sum is obtained with the path [1,3,5,100].
```

## Approach: Two Pointers with Path Sum Tracking

**Intuition:**
- Use two pointers to traverse both arrays simultaneously
- Keep track of sum in each path
- At common elements (intersection points), choose the path with higher sum
- Add the maximum sum to result and reset path sums

**Key Observations:**
1. Common elements are decision points where we can switch paths
2. Between two common elements, we must stay on one path
3. At each common element, take the path with maximum sum so far
4. Both arrays are sorted, making two-pointer approach efficient

**Algorithm:**
1. Initialize i = 0, j = 0, sum1 = 0, sum2 = 0, result = 0
2. While both pointers are valid:
   - If nums1[i] < nums2[j]:
     - Add nums1[i] to sum1, increment i
   - If nums1[i] > nums2[j]:
     - Add nums2[j] to sum2, increment j
   - If nums1[i] == nums2[j] (common element):
     - result += max(sum1, sum2) + nums1[i]
     - Reset sum1 = 0, sum2 = 0
     - Increment both i and j
3. Add remaining elements to respective sums
4. result += max(sum1, sum2)
5. Return result % (10^9 + 7)

**Time Complexity:** O(n + m) where n, m are array lengths
**Space Complexity:** O(1)

## Visual Example

```
nums1 = [2,4,5,8,10]
nums2 = [4,6,8,9]

Step 1: i=0, j=0
  nums1[0]=2 < nums2[0]=4
  sum1 = 2, i=1

Step 2: i=1, j=0
  nums1[1]=4 == nums2[0]=4  (Common!)
  result = 0 + max(2, 0) + 4 = 6
  sum1 = 0, sum2 = 0
  i=2, j=1

Step 3: i=2, j=1
  nums1[2]=5 < nums2[1]=6
  sum1 = 5, i=3

Step 4: i=3, j=1
  nums1[3]=8 > nums2[1]=6
  sum2 = 6, j=2

Step 5: i=3, j=2
  nums1[3]=8 == nums2[2]=8  (Common!)
  result = 6 + max(5, 6) + 8 = 20
  sum1 = 0, sum2 = 0
  i=4, j=3

Step 6: i=4, j=3
  nums1[4]=10 > nums2[3]=9
  sum2 = 9, j=4

Step 7: Process remaining
  sum1 = 10 (nums1[4])
  result = 20 + max(10, 9) = 30
```

## Implementation Notes

```java
public int maxSum(int[] nums1, int[] nums2) {
    long MOD = 1_000_000_007;
    long sum1 = 0, sum2 = 0, result = 0;
    int i = 0, j = 0;

    while (i < nums1.length && j < nums2.length) {
        if (nums1[i] < nums2[j]) {
            sum1 += nums1[i++];
        } else if (nums1[i] > nums2[j]) {
            sum2 += nums2[j++];
        } else {
            result += Math.max(sum1, sum2) + nums1[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }

    while (i < nums1.length) sum1 += nums1[i++];
    while (j < nums2.length) sum2 += nums2[j++];

    result += Math.max(sum1, sum2);
    return (int)(result % MOD);
}
```

## Key Takeaways

1. Two pointers work well with two sorted arrays
2. Track cumulative sums between decision points
3. At common elements, greedily choose best path
4. Handle remaining elements after main loop
5. Use long to avoid overflow before modulo

## Common Pitfalls

1. Forgetting to handle remaining elements
2. Integer overflow - use long
3. Not resetting sums after common elements
4. Not adding the common element value to result
5. Modulo operation timing - do it at the end
