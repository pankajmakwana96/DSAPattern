# Sliding Window - Quick Reference

## Template Cheat Sheet

### 1. Fixed-Size Window Template

```java
public int fixedWindow(int[] arr, int k) {
    int windowSum = 0, result = 0;

    // Build first window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    result = windowSum;

    // Slide window
    for (int i = k; i < arr.length; i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        result = Math.max(result, windowSum);  // or min, or other operation
    }

    return result;
}
```

### 2. Dynamic Window - Maximum Length

```java
public int maxLengthWindow(String s, int k) {
    Map<Character, Integer> map = new HashMap<>();
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        // Expand: add right element
        char rightChar = s.charAt(right);
        map.put(rightChar, map.getOrDefault(rightChar, 0) + 1);

        // Shrink: while window invalid
        while (map.size() > k) {  // condition depends on problem
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

### 3. Dynamic Window - Minimum Length

```java
public int minLengthWindow(int[] arr, int target) {
    int left = 0, sum = 0, minLen = Integer.MAX_VALUE;

    for (int right = 0; right < arr.length; right++) {
        // Expand: add right element
        sum += arr[right];

        // Shrink: while condition met
        while (sum >= target) {
            minLen = Math.min(minLen, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    return minLen == Integer.MAX_VALUE ? 0 : minLen;
}
```

### 4. Count Valid Subarrays

```java
public int countSubarrays(int[] arr, int k) {
    int left = 0, count = 0;
    // ... state variables

    for (int right = 0; right < arr.length; right++) {
        // Add arr[right] to window

        // Shrink if needed
        while (/* window invalid */) {
            // Remove arr[left] from window
            left++;
        }

        // All subarrays ending at right are valid
        count += right - left + 1;
    }

    return count;
}
```

### 5. Exactly K Pattern (using At Most)

```java
public int exactlyK(int[] arr, int k) {
    return atMostK(arr, k) - atMostK(arr, k - 1);
}

private int atMostK(int[] arr, int k) {
    // Standard sliding window for "at most K"
    int left = 0, count = 0;
    Map<Integer, Integer> map = new HashMap<>();

    for (int right = 0; right < arr.length; right++) {
        map.put(arr[right], map.getOrDefault(arr[right], 0) + 1);

        while (map.size() > k) {
            map.put(arr[left], map.get(arr[left]) - 1);
            if (map.get(arr[left]) == 0) {
                map.remove(arr[left]);
            }
            left++;
        }

        count += right - left + 1;
    }

    return count;
}
```

## C++ Templates

### 1. Fixed Window (C++)

```cpp
int fixedWindow(vector<int>& arr, int k) {
    int windowSum = 0, result = 0;

    // First window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    result = windowSum;

    // Slide window
    for (int i = k; i < arr.size(); i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        result = max(result, windowSum);
    }

    return result;
}
```

### 2. Dynamic Window (C++)

```cpp
int maxLengthWindow(string s, int k) {
    unordered_map<char, int> freq;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
```

## Pattern Recognition Guide

### Fixed Window Problems
**Indicators:**
- "subarray of size K"
- "exactly K elements"
- "window of length K"

**Solution:**
- Use fixed window template
- Time: O(n), Space: O(1)

### Maximum Window Problems
**Indicators:**
- "longest substring/subarray"
- "maximum length"
- "at most K distinct"

**Solution:**
- Use dynamic window
- Expand right, shrink left when invalid
- Track maximum size

### Minimum Window Problems
**Indicators:**
- "shortest substring/subarray"
- "minimum length"
- "smallest window containing"

**Solution:**
- Use shrinking window
- Shrink while condition met
- Track minimum size

### Counting Problems
**Indicators:**
- "count subarrays"
- "number of subarrays"
- "exactly K distinct"

**Solution:**
- Count all valid windows ending at each position
- For "exactly K": use atMost(K) - atMost(K-1)

## Common Patterns

### Pattern 1: Track Frequency
```java
Map<Character, Integer> freq = new HashMap<>();

// Add element
freq.put(ch, freq.getOrDefault(ch, 0) + 1);

// Remove element
freq.put(ch, freq.get(ch) - 1);
if (freq.get(ch) == 0) {
    freq.remove(ch);
}

// Check distinct count
int distinctCount = freq.size();
```

### Pattern 2: Track Sum
```java
int windowSum = 0;

// Add element
windowSum += arr[right];

// Remove element
windowSum -= arr[left];

// Check condition
if (windowSum >= target) { /* shrink */ }
```

### Pattern 3: Track Valid Count
```java
int validCount = 0;

// Check if element makes window valid
if (/* condition */) {
    validCount++;
}

// Window is valid when
if (validCount == required) { /* process */ }
```

### Pattern 4: Monotonic Deque (for min/max in window)
```java
Deque<Integer> deque = new ArrayDeque<>();

// Maintain decreasing order for maximum
while (!deque.isEmpty() && arr[deque.peekLast()] < arr[right]) {
    deque.pollLast();
}
deque.offerLast(right);

// Remove elements outside window
while (!deque.isEmpty() && deque.peekFirst() <= right - k) {
    deque.pollFirst();
}

// Maximum is at front
int max = arr[deque.peekFirst()];
```

## Quick Decision Tree

```
Is window size fixed (K given)?
├─ YES → Use Fixed Window Template
│   └─ Track sum/max/min/count in O(1) per slide
│
└─ NO → Is it about finding maximum length?
    ├─ YES → Use Expanding Window
    │   ├─ Expand right always
    │   ├─ Shrink left when invalid
    │   └─ Track max(right - left + 1)
    │
    └─ NO → Is it about finding minimum length?
        ├─ YES → Use Shrinking Window
        │   ├─ Expand right to meet condition
        │   ├─ Shrink left while condition met
        │   └─ Track min(right - left + 1)
        │
        └─ NO → Is it counting subarrays?
            └─ YES → Count += (right - left + 1) for each valid window
```

## Common Operations Cheat Sheet

### Initialize Window
```java
// Java
Map<Character, Integer> map = new HashMap<>();
int left = 0, result = 0;

// C++
unordered_map<char, int> freq;
int left = 0, result = 0;
```

### Expand Window
```java
// Add element to right
map.put(arr[right], map.getOrDefault(arr[right], 0) + 1);
sum += arr[right];
count++;
```

### Shrink Window
```java
// Remove element from left
map.put(arr[left], map.get(arr[left]) - 1);
if (map.get(arr[left]) == 0) {
    map.remove(arr[left]);
}
sum -= arr[left];
left++;
```

### Check Window Validity
```java
// Too many distinct elements
while (map.size() > k) { shrink(); }

// Sum too large
while (sum > target) { shrink(); }

// Repeating character
while (hasRepeating()) { shrink(); }

// Condition met
while (isValid()) { updateResult(); shrink(); }
```

### Update Result
```java
// Maximum length
maxLen = Math.max(maxLen, right - left + 1);

// Minimum length
minLen = Math.min(minLen, right - left + 1);

// Count subarrays
count += right - left + 1;

// Store window
result.add(new ArrayList<>(window));
```

## Optimization Tricks

### 1. Array Instead of HashMap (for limited range)
```java
// For lowercase letters
int[] freq = new int[26];
freq[s.charAt(i) - 'a']++;

// For ASCII
int[] freq = new int[128];
freq[s.charAt(i)]++;

// Count distinct
int distinct = 0;
for (int f : freq) {
    if (f > 0) distinct++;
}
```

### 2. Early Termination
```java
// If remaining elements can't improve result
if (right - left + 1 + (n - right - 1) < maxLen) {
    break;
}
```

### 3. Two-Pass for Exactly K
```java
// Exactly K = At Most K - At Most K-1
return atMostK(arr, k) - atMostK(arr, k - 1);
```

## Edge Cases Checklist

- [ ] Empty array/string: return 0 or default
- [ ] K = 0: usually invalid, return 0
- [ ] K > array length: handle based on problem
- [ ] K = 1: simplest case
- [ ] All elements same: check logic
- [ ] Single element: K = 1 case
- [ ] No valid window: return -1 or 0
- [ ] Negative numbers: affects sum calculations

## Complexity Analysis

### Time Complexity
- **Fixed Window**: O(n) - single pass
- **Dynamic Window**: O(n) - each element visited at most twice (once by right, once by left)
- **With HashMap**: O(n) - HashMap ops are O(1) average
- **With Deque**: O(n) - each element pushed/popped once

### Space Complexity
- **No extra structure**: O(1)
- **HashMap**: O(k) where k = distinct elements
- **Deque**: O(k) where k = window size
- **Character array**: O(1) - fixed size (26 or 128)

## Testing Strategy

### Test Cases to Consider
1. **Normal case**: arr = [1,2,3,4,5], k = 3
2. **K = 1**: Single element window
3. **K = n**: Entire array is window
4. **Empty input**: arr = []
5. **All same elements**: arr = [5,5,5,5]
6. **No valid window**: Based on constraint
7. **Edge values**: Negative numbers, large numbers

### Debug Prints
```java
System.out.println("Window [" + left + "," + right + "] = " + Arrays.toString(window));
System.out.println("Map state: " + map);
System.out.println("Current result: " + result);
```

## Common Mistakes to Avoid

1. **Off-by-one in window size**: Use `right - left + 1`
2. **Forgetting to remove from map**: Check if count becomes 0
3. **Not updating result**: Update after shrinking
4. **Wrong shrinking condition**: Verify while loop condition
5. **Integer overflow**: Use long for large sums
6. **Modifying during iteration**: Be careful with map operations
7. **Not handling empty window**: Check left <= right

## Interview Tips

1. **Clarify first**: Fixed or variable window? What to return if no valid window?
2. **Draw example**: Visualize how window slides
3. **State data structure**: "I'll use HashMap to track frequency"
4. **Mention complexity**: "This will be O(n) time, O(k) space"
5. **Handle edge cases**: "Let me check empty input..."
6. **Test with example**: Walk through your code with sample input

## Problem Type → Template Mapping

| Problem Type | Template | Example |
|-------------|----------|---------|
| Max sum subarray size K | Fixed Window | Maximum Average Subarray |
| Longest substring K distinct | Dynamic - Max Length | Fruit Into Baskets |
| Shortest subarray sum ≥ S | Dynamic - Min Length | Minimum Size Subarray Sum |
| Count subarrays K distinct | Count + At Most | Subarrays K Different |
| Contains pattern | Fixed + HashMap | Find Anagrams |
| Min window covering | Shrinking + HashMap | Minimum Window Substring |
| Max in each window | Deque | Sliding Window Maximum |

---

**Quick Tip**: When in doubt, start with the basic dynamic window template and adjust based on whether you're finding maximum, minimum, or counting.
