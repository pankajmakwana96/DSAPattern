# Two Pointers - Folder Structure

## Overview

Each of the 19 problems now has its own dedicated folder containing:
- **Problem explanation** (.md file)
- **Java solution** (.java file) - for problems with full implementation
- **C++ solution** (.cpp file) - for problems with full implementation

## Complete Folder Structure

```
Two-Pointers/
├── README.md                                    # Pattern overview and guide
├── QUICK-REFERENCE.md                           # Cheat sheet with code templates
│
├── 01-Valid-Palindrome/
│   ├── 01-Valid-Palindrome.md
│   ├── ValidPalindrome.java
│   └── ValidPalindrome.cpp
│
├── 02-3Sum/
│   ├── 02-3Sum.md
│   ├── ThreeSum.java
│   └── ThreeSum.cpp
│
├── 03-Remove-Nth-Node-From-End/
│   ├── 03-Remove-Nth-Node-From-End.md
│   ├── RemoveNthNodeFromEnd.java
│   └── RemoveNthNodeFromEnd.cpp
│
├── 04-Sort-Colors/
│   ├── 04-Sort-Colors.md
│   ├── SortColors.java
│   └── SortColors.cpp
│
├── 05-Reverse-Words-In-String/
│   ├── 05-Reverse-Words-In-String.md
│   ├── ReverseWordsInString.java
│   └── ReverseWordsInString.cpp
│
├── 06-Valid-Word-Abbreviation/
│   ├── 06-Valid-Word-Abbreviation.md
│   ├── ValidWordAbbreviation.java
│   └── ValidWordAbbreviation.cpp
│
├── 07-Strobogrammatic-Number/
│   ├── 07-Strobogrammatic-Number.md
│   ├── StrobogrammaticNumber.java
│   └── StrobogrammaticNumber.cpp
│
├── 08-Count-Pairs-Sum-Less-Than-Target/
│   ├── 08-Count-Pairs-Sum-Less-Than-Target.md
│   ├── CountPairsSumLessThanTarget.java
│   └── CountPairsSumLessThanTarget.cpp
│
├── 09-Append-Characters-To-Make-Subsequence/
│   ├── 09-Append-Characters-To-Make-Subsequence.md
│   ├── AppendCharactersToMakeSubsequence.java
│   └── AppendCharactersToMakeSubsequence.cpp
│
├── 10-Lowest-Common-Ancestor-Binary-Tree-III/
│   ├── 10-Lowest-Common-Ancestor-Binary-Tree-III.md
│   ├── LowestCommonAncestorBinaryTreeIII.java
│   └── LowestCommonAncestorBinaryTreeIII.cpp
│
├── 11-Count-Subarrays-Fixed-Bounds/
│   ├── 11-Count-Subarrays-Fixed-Bounds.md
│   ├── CountSubarraysFixedBounds.java
│   └── CountSubarraysFixedBounds.cpp
│
├── 12-Get-Maximum-Score/
│   └── 12-Get-Maximum-Score.md
│
├── 13-Minimum-Moves-Make-Palindrome/
│   └── 13-Minimum-Moves-Make-Palindrome.md
│
├── 14-Next-Palindrome-Same-Digits/
│   └── 14-Next-Palindrome-Same-Digits.md
│
├── 15-Lexicographically-Largest-String-Box-II/
│   └── 15-Lexicographically-Largest-String-Box-II.md
│
├── 16-Create-Maximum-Number/
│   └── 16-Create-Maximum-Number.md
│
├── 17-Squares-Of-Sorted-Array/
│   ├── 17-Squares-Of-Sorted-Array.md
│   ├── SquaresOfSortedArray.java
│   └── SquaresOfSortedArray.cpp
│
├── 18-Reverse-String/
│   ├── 18-Reverse-String.md
│   ├── ReverseString.java
│   └── ReverseString.cpp
│
└── 19-Valid-Palindrome-II/
    ├── 19-Valid-Palindrome-II.md
    ├── ValidPalindromeII.java
    └── ValidPalindromeII.cpp
```

## Summary

### Problems with Full Implementation (14)
These folders contain .md + .java + .cpp files:
- 01-Valid-Palindrome
- 02-3Sum
- 03-Remove-Nth-Node-From-End
- 04-Sort-Colors
- 05-Reverse-Words-In-String
- 06-Valid-Word-Abbreviation
- 07-Strobogrammatic-Number
- 08-Count-Pairs-Sum-Less-Than-Target
- 09-Append-Characters-To-Make-Subsequence
- 10-Lowest-Common-Ancestor-Binary-Tree-III
- 11-Count-Subarrays-Fixed-Bounds
- 17-Squares-Of-Sorted-Array
- 18-Reverse-String
- 19-Valid-Palindrome-II

### Problems with Approach Only (5)
These folders contain only .md file with detailed algorithm explanations:
- 12-Get-Maximum-Score
- 13-Minimum-Moves-Make-Palindrome
- 14-Next-Palindrome-Same-Digits
- 15-Lexicographically-Largest-String-Box-II
- 16-Create-Maximum-Number

## How to Use

### For a specific problem:
1. Navigate to the problem folder (e.g., `01-Valid-Palindrome/`)
2. Read the `.md` file for problem description and approaches
3. Review the Java implementation (`.java` file)
4. Review the C++ implementation (`.cpp` file)
5. Run and test the code with provided test cases

### To compile and run:

**Java:**
```bash
cd 01-Valid-Palindrome
javac ValidPalindrome.java
java ValidPalindrome
```

**C++:**
```bash
cd 01-Valid-Palindrome
g++ -std=c++17 ValidPalindrome.cpp -o ValidPalindrome
./ValidPalindrome
```

## Benefits of This Structure

✅ **Organized**: Each problem is self-contained in its own folder
✅ **Easy Navigation**: Find everything related to one problem in one place
✅ **Scalable**: Easy to add more problems following the same structure
✅ **Clear Separation**: Full implementations vs approach-only problems are clearly distinguished
✅ **Version Control Friendly**: Easy to track changes per problem

---

**Total Problems**: 19
**Total Folders**: 19 problem folders + 1 root (Two-Pointers)
**Total Files**: 49 files (21 .md + 14 .java + 14 .cpp)
