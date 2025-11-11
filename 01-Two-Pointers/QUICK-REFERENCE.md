# Two Pointers Pattern - Quick Reference Cheat Sheet

## Pattern Recognition

### When to Use Two Pointers?
✅ Problem involves sorted/sortable array or string
✅ Need to find pairs/triplets with certain sum/property
✅ Checking for palindrome or symmetric patterns
✅ Partitioning or rearranging array elements
✅ Linked list with distance/cycle constraints
✅ Merging two sorted sequences

## Three Types of Two Pointers

### 1. Opposite Direction (Converging)
```java
int left = 0, right = n - 1;
while (left < right) {
    // Process elements at left and right
    // Move pointers based on condition
    left++; right--;
}
```
**Use Cases**: Palindrome, Two Sum (sorted), Container with Most Water

### 2. Same Direction (Slow & Fast)
```java
int slow = 0, fast = 0;
while (fast < n) {
    // Fast pointer explores
    // Slow pointer maintains invariant
    fast++;
    if (condition) slow++;
}
```
**Use Cases**: Remove Duplicates, Partition Array, Sliding Window

### 3. Fixed Distance
```java
int fast = k; // k steps ahead
while (fast < n) {
    // Maintain k distance
    slow++;
    fast++;
}
```
**Use Cases**: Remove Nth from End, K-distance problems

## Common Patterns & Solutions

### Pattern 1: Valid Palindrome
```java
boolean isPalindrome(String s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        // Skip non-alphanumeric
        while (l < r && !isAlnum(s.charAt(l))) l++;
        while (l < r && !isAlnum(s.charAt(r))) r--;
        if (lower(s.charAt(l++)) != lower(s.charAt(r--)))
            return false;
    }
    return true;
}
```

### Pattern 2: Two Sum (Sorted Array)
```java
int[] twoSum(int[] nums, int target) {
    int l = 0, r = nums.length - 1;
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) return new int[]{l, r};
        if (sum < target) l++;
        else r--;
    }
    return new int[]{-1, -1};
}
```

### Pattern 3: Remove Duplicates
```java
int removeDuplicates(int[] nums) {
    int slow = 0;
    for (int fast = 1; fast < nums.length; fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}
```

### Pattern 4: Dutch National Flag (3 Pointers)
```java
void sortColors(int[] nums) {
    int low = 0, mid = 0, high = nums.length - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums, low++, mid++);
        else if (nums[mid] == 1) mid++;
        else swap(nums, mid, high--);
    }
}
```

### Pattern 5: Fast & Slow for Linked List
```java
ListNode detectCycle(ListNode head) {
    ListNode slow = head, fast = head;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) return slow; // Cycle detected
    }
    return null; // No cycle
}
```

### Pattern 6: 3Sum with Sorted Array
```java
List<List<Integer>> threeSum(int[] nums) {
    Arrays.sort(nums);
    List<List<Integer>> result = new ArrayList<>();
    for (int i = 0; i < nums.length - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicates
        int l = i + 1, r = nums.length - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                result.add(Arrays.asList(nums[i], nums[l], nums[r]));
                while (l < r && nums[l] == nums[l+1]) l++; // Skip
                while (l < r && nums[r] == nums[r-1]) r--; // Skip
                l++; r--;
            } else if (sum < 0) l++;
            else r--;
        }
    }
    return result;
}
```

## Time Complexity Cheat Sheet

| Operation | Complexity | Note |
|-----------|-----------|------|
| Single Pass | O(n) | Most common |
| Two nested loops | O(n²) | 3Sum, 4Sum variants |
| With sorting | O(n log n) | Sort then two pointers |
| Linked list | O(n) | Single pass usually |
| With HashMap | O(n) | Sometimes better than two pointers |

## Space Complexity

| Approach | Space | Note |
|----------|-------|------|
| In-place | O(1) | Preferred when possible |
| With result array | O(n) | Output space |
| Recursion | O(h) | Call stack depth |

## Common Edge Cases

1. **Empty input**: `nums.length == 0`
2. **Single element**: `nums.length == 1`
3. **Two elements**: May need special handling
4. **All same elements**: `[1,1,1,1,1]`
5. **Already sorted**: Ascending or descending
6. **Duplicates**: Need to skip properly
7. **Negative numbers**: In sum problems
8. **Overflow**: For large numbers

## Debugging Checklist

- [ ] Are pointer bounds correct? (`<` vs `<=`)
- [ ] Are you moving the right pointer?
- [ ] Are you skipping duplicates correctly?
- [ ] Are you handling empty/single element?
- [ ] Did you sort when needed?
- [ ] Are you checking array bounds before access?
- [ ] Is the termination condition correct?

## Common Mistakes

❌ **Off-by-one errors**: Using wrong comparison (`<` vs `<=`)
❌ **Not skipping duplicates**: Causes duplicate results
❌ **Wrong pointer movement**: Moving wrong pointer or not moving at all
❌ **Forgetting to sort**: When problem requires sorted data
❌ **Array out of bounds**: Not checking before accessing
❌ **Infinite loop**: Not changing pointer positions
❌ **Wrong initialization**: Starting pointers at wrong positions

## Quick Problem Classification

### Palindrome Problems
- Valid Palindrome
- Valid Palindrome II
- Palindrome Linked List
- Strobogrammatic Number

### Sum Problems
- Two Sum (sorted)
- 3Sum
- 4Sum
- Pair with Target Sum

### Array Manipulation
- Remove Duplicates
- Sort Colors (Dutch Flag)
- Squares of Sorted Array
- Partition Array

### Linked List
- Remove Nth from End
- Middle of Linked List
- Detect Cycle
- LCA with Parent Pointers

### String Problems
- Reverse String/Words
- Valid Word Abbreviation
- Subsequence Matching

## Interview Tips

1. **Ask clarifying questions**:
   - Is array sorted?
   - Are duplicates allowed?
   - Can I modify input?
   - What's the expected output format?

2. **Explain your approach**:
   - Why two pointers?
   - What invariant are you maintaining?
   - How do you handle edge cases?

3. **Walk through example**:
   - Show pointer movements
   - Explain each step
   - Handle edge cases

4. **Analyze complexity**:
   - Time complexity
   - Space complexity
   - Can it be optimized?

5. **Test your code**:
   - Normal case
   - Edge cases
   - Large inputs

## Practice Strategy

1. **Week 1**: Master basic patterns (10 easy problems)
2. **Week 2**: Practice medium problems (10-15 problems)
3. **Week 3**: Tackle hard problems (5-10 problems)
4. **Week 4**: Mix and review, timed practice

## Related Patterns

- **Sliding Window**: Similar to same-direction two pointers
- **Binary Search**: Can combine with two pointers
- **Fast & Slow**: Linked list variant
- **Merge Sort**: Two pointers for merging

---

**Pro Tip**: If you can sort the array/string first, two pointers becomes much more powerful!

**Remember**: Two pointers is about maintaining an invariant while reducing search space efficiently.
