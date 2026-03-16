# Correctness Proof – Problem B: Right Maximum

## Problem Reduction
Each operation finds the **rightmost maximum** in the current array and removes it along with everything after it. This is equivalent to:

1. Start with prefix `a[0..n-1]`.
2. Find the rightmost occurrence of the prefix maximum → position `p`.
3. Shrink to prefix `a[0..p-1]`. Increment operation count.
4. Repeat until prefix is empty.

## Data Structures
- **Prefix-max array** `pmx[i]` = max of `a[0..i]`. Computed in O(n).
- **Per-value index lists** `pos[v]` = sorted list of all indices where `a[i] == v`.

## Binary Search Usage
At each step with right boundary `r`:
- `mx = pmx[r]` gives the maximum value in `a[0..r]`.
- Binary search in `pos[mx]` for the **rightmost index ≤ r**.
  - The list `pos[mx]` is sorted in increasing order.
  - We find the largest `pos[mx][j]` such that `pos[mx][j] <= r`.
  - This is a standard "upper bound − 1" binary search on a sorted array → monotone predicate.

## Why It Works
- `pmx[r]` correctly gives the maximum of the current prefix since we only shrink the prefix from the right, and `pmx` is non-decreasing.
- Binary search on the sorted index list finds the rightmost occurrence of `mx` within `[0, r]` in O(log n).
- Setting `r = found_index - 1` correctly simulates removing everything from that position onward.

## Complexity
- **Time:** O(n log n) per test case — at most n iterations, each with an O(log n) binary search.
- **Space:** O(n) for prefix-max and index lists.
