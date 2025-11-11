# Repeated DNA Sequences

**LeetCode Link:** https://leetcode.com/problems/repeated-dna-sequences/

**Difficulty:** Medium

**Pattern:** Fixed Sliding Window with HashSet

## Problem Description

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'. Given a string `s` that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

**Example 1:**
```
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
```

**Example 2:**
```
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
```

## Approach: Fixed Window (size 10) + HashSet

**Algorithm:**
1. Slide a window of size 10 through the string
2. Use HashSet to track seen sequences
3. Use another Set to track sequences that appear more than once
4. Return sequences that appeared multiple times

**Time Complexity:** O(n)
**Space Complexity:** O(n)

## Code Implementation

See: `RepeatedDNASequences.java` and `RepeatedDNASequences.cpp`
