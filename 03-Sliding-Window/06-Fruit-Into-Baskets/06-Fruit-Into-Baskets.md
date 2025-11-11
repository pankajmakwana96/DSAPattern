# Fruit Into Baskets

**LeetCode Link:** https://leetcode.com/problems/fruit-into-baskets/

**Difficulty:** Medium

**Pattern:** Sliding Window (At Most K Distinct)

## Problem Description

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules:
- You only have two baskets, and each basket can only hold a single type of fruit
- You can start at any tree, but once started, you must pick one fruit from every tree moving to the right
- The picked fruits must fit in one of your baskets

Given the array `fruits`, return the maximum number of fruits you can pick.

**Example 1:**
```
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
```

**Example 2:**
```
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2] (fruit types 1 and 2).
```

**Example 3:**
```
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2] (fruit types 2 and 3).
```

## Approach: Longest Subarray with At Most 2 Distinct

**Intuition:**
- This is "longest subarray with at most 2 distinct elements"
- Use sliding window with HashMap to track fruit types
- Expand window while <= 2 types, shrink when > 2

**Algorithm:**
1. Use HashMap to count fruit types in window
2. Expand window by adding fruits[right]
3. While more than 2 types, shrink from left
4. Track maximum window size
5. Return max length

**Time Complexity:** O(n)
**Space Complexity:** O(1) - at most 3 entries in map

## Visual Example

```
fruits = [1,2,3,2,2]

Step 1: [1] - 1 type, maxLen=1
Step 2: [1,2] - 2 types, maxLen=2
Step 3: [1,2,3] - 3 types! Shrink
        Remove 1: [2,3] - 2 types, maxLen=2
Step 4: [2,3,2] - 2 types, maxLen=3
Step 5: [2,3,2,2] - 2 types, maxLen=4 ✓

Result: 4
```

## Key Takeaways

1. **At most 2 = basket constraint**: Two baskets = two fruit types
2. **Standard dynamic window**: Expand/shrink pattern
3. **HashMap tracks types**: Keys are fruit types, values are counts
4. **Generalization**: Can easily extend to K baskets

## Code Implementation

See: `FruitIntoBaskets.java` and `FruitIntoBaskets.cpp`

## Generalized Solution (K Baskets)

```java
public int maxFruit(int[] fruits, int k) {
    Map<Integer, Integer> map = new HashMap<>();
    int left = 0, maxLen = 0;

    for (int right = 0; right < fruits.length; right++) {
        map.put(fruits[right], map.getOrDefault(fruits[right], 0) + 1);

        while (map.size() > k) {
            map.put(fruits[left], map.get(fruits[left]) - 1);
            if (map.get(fruits[left]) == 0) {
                map.remove(fruits[left]);
            }
            left++;
        }

        maxLen = Math.max(maxLen, right - left + 1);
    }

    return maxLen;
}
```

For this problem, k = 2.

## Edge Cases

1. **All same fruit**: Return array length
2. **All different fruits**: Return 2
3. **Single fruit**: Return 1
4. **Two fruits alternating**: Return array length

## Related Problems

- Longest Substring with At Most K Distinct Characters
- Longest Substring with At Most Two Distinct Characters
- Subarrays with K Different Integers
