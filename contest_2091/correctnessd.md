# Correctness Analysis for Problem D: Place of the Olympiad

This document outlines the correctness of the binary search approach for finding the minimum possible length of the longest bench.

## Problem Recap

We need to place $k$ desks in an $n \times m$ grid. A bench is a sequence of consecutive desks in a row. We want to minimize the maximum bench length $L$.

## Key Observation

In a row of $m$ spots, if we want to place as many desks as possible such that no bench has length greater than $L$, we should place benches of length $L$ separated by a single empty spot.
This means for every $L+1$ spots, we can place a maximum of $L$ desks.
The number of such "full blocks" of size $(L+1)$ that can fit in $m$ spots is $\lfloor \frac{m}{L+1} \rfloor$.
The number of gaps between these blocks is at least $\lfloor \frac{m}{L+1} \rfloor$. Each gap must contain at least one empty spot.
So, the maximum number of desks that can be placed in a row is:
$$f(L) = m - \lfloor \frac{m}{L+1} \rfloor$$

## Total Capacity

With $n$ identical rows, the total number of desks that can be placed across all rows without exceeding a maximum bench length of $L$ is:
$$F(L) = n \times (m - \lfloor \frac{m}{L+1} \rfloor)$$

## Binary Search Correctness

1. **Monotonicity**: $F(L)$ is a non-decreasing function of $L$. As $L$ increases, $(L+1)$ increases, $\lfloor \frac{m}{L+1} \rfloor$ decreases or stays the same, and thus $m - \lfloor \frac{m}{L+1} \rfloor$ increases or stays the same.
2. **Search Range**: $L$ can range from $1$ (minimum possible for $k \ge 1$) to $m$ (maximum possible for $k = n \times m$).
3. **Goal**: We want to find the smallest $L$ such that $F(L) \ge k$.

Since $F(L)$ is monotonic, we can use binary search on $L$ to find the smallest $L$ satisfying $F(L) \ge k$.

## Implementation Details

- The implementation uses `long long` for $n, m, k$ and intermediate calculations to prevent overflow, as $n \times m$ can reach $10^{18}$.
- The binary search correctly identifies the lower bound $L$ by updating `ans = mid` and narrowing the search to `[l, mid - 1]` whenever $F(L) \ge k$.
