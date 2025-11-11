# Longest Substring Without Repeating Characters

**LeetCode Link:** https://leetcode.com/problems/longest-substring-without-repeating-characters/

**Difficulty:** Medium

**Pattern:** Sliding Window (Dynamic Size)

## Problem Description

Given a string `s`, find the length of the longest substring without repeating characters.

**Example 1:**
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

**Constraints:**
- 0 <= s.length <= 5 * 10^4
- s consists of English letters, digits, symbols and spaces.

## Approach: Sliding Window with HashSet

**Intuition:**
- Use window [left, right] to track current substring
- Expand window by adding characters
- When duplicate found, shrink from left until no duplicate
- Track maximum window size

**Algorithm:**
1. Use HashSet to store characters in current window
2. For each character at right:
   - If character not in set, add it and expand window
   - If character in set, remove from left until duplicate removed
   - Update maximum length
3. Return max length

**Time Complexity:** O(n) - each character visited at most twice
**Space Complexity:** O(min(n, m)) where m is charset size

## Visual Example

```
s = "abcabcbb"

Step 1: ""
window = [], maxLen = 0

Step 2: "a"
window = [a], maxLen = 1

Step 3: "ab"
window = [a,b], maxLen = 2

Step 4: "abc"
window = [a,b,c], maxLen = 3

Step 5: "abca" - duplicate 'a'!
Remove from left: "bca"
window = [b,c,a], maxLen = 3

Step 6: "bcab" - duplicate 'b'!
Remove from left: "cab"
window = [c,a,b], maxLen = 3

Step 7: "cabc" - duplicate 'c'!
Remove from left: "abc"
window = [a,b,c], maxLen = 3

Step 8: "abcb" - duplicate 'b'!
Remove from left: "cb"
window = [c,b], maxLen = 3

Step 9: "cbb" - duplicate 'b'!
Remove from left: "b"
window = [b], maxLen = 3

Result: 3
```

## Key Takeaways

1. **Dynamic window**: Size changes based on repeating characters
2. **HashSet for tracking**: Quick O(1) lookup
3. **Shrink strategy**: Remove from left until valid
4. **Two pointers**: Both move forward, never backward
5. **Update max after each addition**: Don't miss optimal window

## Code Implementation

See: `LongestSubstring.java` and `LongestSubstring.cpp`

## Optimization: HashMap with Index

Instead of shrinking one by one, jump left pointer:

```java
Map<Character, Integer> map = new HashMap<>();  // char -> last index
int left = 0, maxLen = 0;

for (int right = 0; right < s.length(); right++) {
    char c = s.charAt(right);

    // If char seen and within current window, jump left
    if (map.containsKey(c) && map.get(c) >= left) {
        left = map.get(c) + 1;
    }

    map.put(c, right);
    maxLen = Math.max(maxLen, right - left + 1);
}
```

**Advantage:** Only O(n) operations, no nested loops

## Edge Cases

1. **Empty string**: Return 0
2. **Single character**: Return 1
3. **All unique**: Return s.length()
4. **All same**: Return 1
5. **Two characters alternating**: "ababa" → 2

## Common Pitfalls

1. Not shrinking window correctly (removing wrong character)
2. Checking maxLen before adding character
3. Not updating left pointer when duplicate found
4. Using contains() and remove() inefficiently
5. Off-by-one in length calculation

## Comparison of Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Brute Force | O(n³) | O(min(n,m)) | Simple | Too slow |
| HashSet + Shrink | O(2n) | O(min(n,m)) | Intuitive | Some redundant work |
| HashMap + Jump | O(n) | O(min(n,m)) | Optimal | Slightly complex |

## Related Problems

- Longest Substring with At Most K Distinct Characters
- Longest Substring with At Most Two Distinct Characters
- Longest Repeating Character Replacement
- Minimum Window Substring

## Interview Tips

1. **Start with brute force**: "Check all substrings - O(n³)"
2. **Optimize**: "Sliding window can make it O(n)"
3. **Choose structure**: HashSet for simple, HashMap for optimized
4. **Explain expansion/shrinking**: Clear about when to shrink
5. **Test**: Empty, single char, all unique, all same
