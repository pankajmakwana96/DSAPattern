# Minimum Window Substring

**LeetCode Link:** https://leetcode.com/problems/minimum-window-substring/

**Difficulty:** Hard

**Pattern:** Sliding Window (Shrinking with HashMap)

## Problem Description

Given two strings `s` and `t` of lengths `m` and `n` respectively, return the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return the empty string `""`.

**Example 1:**
```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

**Example 2:**
```
Input: s = "a", t = "a"
Output: "a"
```

**Example 3:**
```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
```

## Approach: Sliding Window with HashMap

**Intuition:**
- Track required characters and their frequencies
- Expand window until all characters covered
- Shrink window while maintaining coverage
- Track minimum window

**Algorithm:**
1. Build frequency map of t
2. Use two pointers and counter for matched characters
3. Expand right: add characters, decrement required count
4. When all matched, shrink left while valid
5. Track minimum window during shrinking
6. Return minimum window substring

**Time Complexity:** O(m + n) where m=s.length, n=t.length
**Space Complexity:** O(n) for frequency map

## Visual Example

```
s = "ADOBECODEBANC", t = "ABC"
Required: {A:1, B:1, C:1}

Step 1-4: "ADOB" - have A,B, missing C
Step 5: "ADOBE" - still missing C
Step 6: "ADOBEC" - ALL FOUND! have=3, minWindow="ADOBEC" (6)

Shrink: "DOBEC" - missing A, expand again
Step 7-9: "DOBECODEB" - missing C
Step 10: "DOBECODEBAN" - have all, but larger
Step 11: "DOBECODE" + "BANC" - ALL FOUND! minWindow="BANC" (4) ✓

Continue checking, "BANC" is minimum.
```

## Key Takeaways

1. **Two frequency maps**: One for t, one for current window
2. **Counter optimization**: Track how many required chars matched
3. **Shrinking phase**: Only shrink when window is valid
4. **Update result during shrinking**: Get smaller valid windows
5. **Return substring**: Need to track start and length

## Code Implementation

See: `MinimumWindowSubstring.java` and `MinimumWindowSubstring.cpp`

## Implementation Details

```java
Map<Character, Integer> required = new HashMap<>();  // chars in t
Map<Character, Integer> window = new HashMap<>();     // chars in current window
int have = 0, need = required.size();                 // unique chars matched

while (right < s.length()) {
    char c = s.charAt(right);
    window.put(c, window.getOrDefault(c, 0) + 1);

    // Check if this char satisfies requirement
    if (required.containsKey(c) &&
        window.get(c).equals(required.get(c))) {
        have++;
    }

    // Try to shrink
    while (have == need) {
        // Update result
        if (right - left + 1 < minLen) {
            minLen = right - left + 1;
            resultStart = left;
        }

        // Shrink from left
        char leftChar = s.charAt(left);
        window.put(leftChar, window.get(leftChar) - 1);
        if (required.containsKey(leftChar) &&
            window.get(leftChar) < required.get(leftChar)) {
            have--;
        }
        left++;
    }

    right++;
}
```

## Edge Cases

1. **t longer than s**: Return ""
2. **t not in s**: Return ""
3. **s equals t**: Return s
4. **Duplicate chars in t**: Must count all
5. **Empty s or t**: Return ""

## Common Pitfalls

1. Not handling duplicate characters correctly
2. Using have/need wrong (should be unique chars, not total)
3. Updating result outside shrinking loop
4. Not checking if char is required before updating have
5. Comparing Integer objects with == instead of .equals()

## Why This is Hard

1. **Multiple requirements**: Must track all chars with frequencies
2. **Optimal shrinking**: Must know when to stop shrinking
3. **Counter logic**: have/need must track unique chars matched
4. **Edge cases**: Many corner cases to handle
5. **Substring extraction**: Must remember start position

## Interview Tips

1. **Clarify**: Case sensitive? Special characters?
2. **Start simple**: "Need to track which chars we still need"
3. **Explain maps**: "required map vs window map"
4. **Counter trick**: "have/need tracks unique chars matched"
5. **Shrinking logic**: "Shrink while all requirements met"
6. **Test thoroughly**: Empty, no match, exact match cases
