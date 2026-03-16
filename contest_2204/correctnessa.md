# Correctness Proof – Problem A: Passing the Ball

## Observation
The ball starts at student 1 (`s[0] = 'R'`) and moves right. It keeps moving right until it reaches a student with `'L'`, who sends it back left. At student 1 (`'R'`), it bounces right again. The ball is trapped in the pocket `[1, first_L]`.

Since exactly `n` passes occur and the pocket has at most `n` positions, every student in the pocket is visited at least once.

**Answer** = index of the first `'L'` + 1 (1-indexed).

## Why Binary Search Works
Define predicate `P(p)` = "there exists an `'L'` in `s[0..p]`".

- `P(0)` = false (since `s[0] = 'R'`).
- `P(n-1)` = true (since `s[n-1] = 'L'`).
- `P` is monotone: once true, it stays true.

Binary search finds the smallest `p` where `P(p)` is true → that's the first `'L'`.

## Complexity
- **Time:** `O(n log n)` per test case (binary search × inner scan).
- **Space:** `O(n)` for the string.
