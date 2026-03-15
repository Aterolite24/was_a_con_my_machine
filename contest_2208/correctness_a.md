# Correctness Analysis - Bingo Candies

## Problem Understanding
To rearrange an $n \times n$ grid so no row or column is monochromatic, we must avoid any color $X$ from dominating the board.

## Condition for Success
- Each row needs at least one candy of a different color.
- Each column needs at least one candy of a different color.
- A single set of $n$ candies of colors other than $X$ can "break" all $n$ rows and $n$ columns if placed diagonally.
- Thus, for a color $X$, if there are at least $n$ non-$X$ candies, we can always find a valid rearrangement.
- Condition: $Count(X) \le n^2 - n$ for all colors $X$.
- Special case: For $n=1$, any color makes the board monochromatic, so the answer is always NO.

## Implementation (Manual Binary Search)
- We sort the $n^2$ candies.
- For each unique color, we use a manual binary search to find its upper bound in $O(\log n^2)$.
- The total time complexity per test case is $O(n^2 \log n^2)$. With $\sum n \le 500$, this is extremely efficient.
