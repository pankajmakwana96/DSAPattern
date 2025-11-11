# Sliding Window Pattern

## Pattern Overview

The **Sliding Window** pattern is used to perform operations on a specific window size of an array or string. The window "slides" through the data structure, typically from left to right, to efficiently solve problems involving contiguous subarrays or substrings.

**Time Complexity:** Usually O(n) instead of O(n²) or O(n³)
**Space Complexity:** Typically O(1) to O(k) where k is window size or unique elements

## When to Use Sliding Window

Use this pattern when:
- Problem involves **contiguous sequence** of elements (subarray/substring)
- Asked to find **longest**, **shortest**, or **optimal** window
- Need to track elements in a **specific range** or window
- Problem mentions **subarray/substring** with a constraint
- Optimization is needed from brute force O(n²) to O(n)

**Key Indicators:**
- "Maximum/Minimum sum of subarray of size K"
- "Longest substring with K distinct characters"
- "Find all anagrams in a string"
- "Smallest subarray with sum ≥ S"
- "Maximum/Minimum of all subarrays of size K"

## Types of Sliding Window

### 1. Fixed-Size Window

Window size is constant (K elements).

**Pattern:**
```
- Initialize window of size K
- Calculate result for first window
- Slide window: Remove leftmost, add rightmost
- Update result
```

**Problems:**
- Maximum Average Subarray
- Maximum Sum of Subarray of size K
- Count occurrences of anagram

**Example:**
```
Array: [1, 3, 2, 6, -1, 4, 1, 8, 2], K = 5
Window slides: [1,3,2,6,-1] → [3,2,6,-1,4] → [2,6,-1,4,1] → ...
```

### 2. Dynamic-Size Window (Variable)

Window size changes based on conditions.

**Pattern:**
```
- Use two pointers (left, right)
- Expand window by moving right
- Shrink window when condition violated
- Track optimal window
```

**Problems:**
- Longest Substring Without Repeating Characters
- Minimum Window Substring
- Longest Repeating Character Replacement

**Example:**
```
String: "abcabcbb", find longest substring without repeating
Window expands/contracts: "a" → "ab" → "abc" → "bc" → "bca" → ...
```

### 3. Dynamic with Auxiliary Data Structure

Uses HashMap/Set to track elements in window.

**Pattern:**
```
- Use Map/Set to store elements
- Track frequency/count of elements
- Adjust window based on Map/Set state
- Update result when condition met
```

**Problems:**
- Fruit Into Baskets
- Subarrays with K Different Integers
- Minimum Window Substring

## Core Techniques

### 1. Basic Fixed Window
```java
// Find maximum sum of subarray of size k
public int maxSum(int[] arr, int k) {
    int windowSum = 0, maxSum = 0;

    // First window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    maxSum = windowSum;

    // Slide window
    for (int i = k; i < arr.length; i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        maxSum = Math.max(maxSum, windowSum);
    }

    return maxSum;
}
```

### 2. Dynamic Window (Two Pointers)
```java
// Longest substring with at most k distinct characters
public int lengthOfLongestSubstringKDistinct(String s, int k) {
    Map<Character, Integer> map = new HashMap<>();
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        // Expand window
        map.put(s.charAt(right), map.getOrDefault(s.charAt(right), 0) + 1);

        // Shrink window if needed
        while (map.size() > k) {
            char leftChar = s.charAt(left);
            map.put(leftChar, map.get(leftChar) - 1);
            if (map.get(leftChar) == 0) {
                map.remove(leftChar);
            }
            left++;
        }

        // Update result
        maxLen = Math.max(maxLen, right - left + 1);
    }

    return maxLen;
}
```

### 3. Shrinking Window
```java
// Minimum size subarray with sum >= target
public int minSubArrayLen(int target, int[] nums) {
    int left = 0, sum = 0, minLen = Integer.MAX_VALUE;

    for (int right = 0; right < nums.length; right++) {
        sum += nums[right];

        // Shrink window while condition met
        while (sum >= target) {
            minLen = Math.min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }

    return minLen == Integer.MAX_VALUE ? 0 : minLen;
}
```

## Problem-Solving Framework

### Step 1: Identify Pattern Type
- Fixed size → Use basic sliding window
- Find maximum → Expand greedily, track max
- Find minimum → Shrink greedily, track min
- Count subarrays → Use multiple techniques

### Step 2: Choose Data Structure
- **Array/String only** → Two pointers
- **Track frequency** → HashMap
- **Track uniqueness** → HashSet
- **Track order** → Deque
- **Track range** → TreeMap

### Step 3: Define Window Validity
- What makes window valid?
- When to expand? (always or conditionally)
- When to shrink? (condition violated)
- What to track? (sum, count, frequency)

### Step 4: Implement Template
```
1. Initialize: left = 0, result variable
2. for right in range(n):
       a. Add arr[right] to window
       b. While window invalid:
            - Remove arr[left] from window
            - left++
       c. Update result with current window
3. Return result
```

## Common Patterns and Solutions

### Pattern 1: Fixed Size - Maximum/Minimum
**Template:**
```
1. Calculate first window result
2. Slide: remove left, add right
3. Update max/min
```

### Pattern 2: At Most K Distinct
**Template:**
```
1. Expand window with right
2. If distinct > k, shrink from left
3. Update result at each step
```

### Pattern 3: Exactly K Distinct
**Trick:** atMost(K) - atMost(K-1)

### Pattern 4: Minimum Window with Condition
**Template:**
```
1. Expand to meet condition
2. Shrink while maintaining condition
3. Track minimum window
```

### Pattern 5: Maximum Window with Constraint
**Template:**
```
1. Expand while constraint satisfied
2. Track maximum window size
3. Shrink when constraint violated
```

## Time and Space Complexity

### Time Complexity Patterns

| Pattern | Complexity | Explanation |
|---------|-----------|-------------|
| Fixed Window | O(n) | Single pass through array |
| Dynamic Window | O(n) | Each element visited at most twice |
| With HashMap | O(n) | HashMap operations are O(1) average |
| With Deque | O(n) | Each element pushed/popped once |

### Space Complexity Patterns

| Data Structure | Space | Use Case |
|---------------|-------|----------|
| Two Pointers Only | O(1) | Simple sum/count tracking |
| HashMap | O(k) | k = distinct elements in window |
| HashSet | O(k) | Track unique elements |
| Deque | O(k) | Maintain min/max in window |

## Edge Cases to Consider

1. **Empty input**: Return 0 or default value
2. **Single element**: Window size = 1
3. **K > array length**: Handle appropriately
4. **All elements same**: Check if logic handles
5. **Negative numbers**: Affect sum calculations
6. **K = 0**: Usually invalid, return 0
7. **No valid window**: Return appropriate default

## Common Mistakes

1. **Not resetting window state**: HashMap not cleared properly
2. **Off-by-one errors**: Window size calculation
3. **Forgetting to update result**: Only updating when shrinking
4. **Infinite loop**: Shrinking condition never met
5. **Integer overflow**: Sum of large numbers
6. **Not handling duplicates**: In frequency maps
7. **Wrong boundary conditions**: right - left vs right - left + 1

## Optimization Techniques

### 1. Early Termination
```java
if (right - left + 1 > remaining) break;
```

### 2. Prefix Sum
```java
// For range sum queries
int[] prefix = new int[n + 1];
for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
}
int windowSum = prefix[right + 1] - prefix[left];
```

### 3. Monotonic Deque
```java
// For sliding window maximum
Deque<Integer> deque = new ArrayDeque<>();
// Maintain decreasing order in deque
```

### 4. Character Array Instead of HashMap
```java
// For ASCII characters
int[] freq = new int[26];  // or int[128]
freq[s.charAt(i) - 'a']++;
```

## Debugging Tips

1. **Print window state**: Log [left, right] and contents
2. **Verify window size**: right - left + 1
3. **Check HashMap state**: Print map at each step
4. **Validate conditions**: Are they checked correctly?
5. **Test with small input**: [1,2,3] with K=2
6. **Edge case first**: Test K=1, K=n, empty array

## Interview Strategy

1. **Clarify constraints**:
   - Window size fixed or variable?
   - What defines a valid window?
   - Return value if no valid window?

2. **Start with brute force**:
   - "Naive O(n²) would be nested loops..."
   - "We can optimize with sliding window to O(n)..."

3. **Explain the approach**:
   - Fixed or dynamic window?
   - What data structure to track state?
   - Expand/shrink strategy?

4. **Code carefully**:
   - Initialize properly
   - Handle edge cases
   - Update result correctly

5. **Test thoroughly**:
   - Normal case
   - Edge cases (empty, K=1, K=n)
   - No valid window case

## Problem Categories

### Easy (Foundational)
- Maximum Average Subarray I
- Contains Duplicate II
- Diet Plan Performance

### Medium (Core Patterns)
- Longest Substring Without Repeating Characters
- Minimum Size Subarray Sum
- Longest Repeating Character Replacement
- Fruit Into Baskets
- Repeated DNA Sequences

### Hard (Advanced Techniques)
- Minimum Window Substring
- Sliding Window Maximum
- Subarrays with K Different Integers
- Minimum Window Subsequence

## Learning Path

**Week 1: Fixed Window**
1. Maximum Average Subarray I
2. Diet Plan Performance
3. Contains Duplicate II

**Week 2: Dynamic Window Basics**
4. Longest Substring Without Repeating Characters
5. Minimum Size Subarray Sum
6. Fruit Into Baskets

**Week 3: Advanced Dynamic**
7. Longest Repeating Character Replacement
8. Frequency of the Most Frequent Element
9. Repeated DNA Sequences

**Week 4: Hard Problems**
10. Minimum Window Substring
11. Sliding Window Maximum
12. Subarrays with K Different Integers
13. Minimum Window Subsequence

## Key Takeaways

1. **Sliding window optimizes** from O(n²) to O(n)
2. **Two pointers** (left, right) define the window
3. **HashMap/Set** track elements in window
4. **Expand** window by moving right pointer
5. **Shrink** window by moving left pointer
6. **Update result** after each valid window
7. **Practice recognizing** when to apply pattern

## Related Patterns

- **Two Pointers**: Similar concept, different constraints
- **Dynamic Programming**: Some overlap in optimization
- **Monotonic Stack/Queue**: For min/max in window
- **Prefix Sum**: For range queries optimization

---

**Pattern Type**: Sliding Window
**Difficulty Range**: Easy to Hard
**Time Complexity**: Typically O(n)
**Core Skill**: Window management and state tracking
**Total Problems**: 15

## Quick Reference

See `QUICK-REFERENCE.md` for code templates and cheat sheets.
