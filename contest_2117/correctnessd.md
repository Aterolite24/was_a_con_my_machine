# Correctness Proof - Problem D: Retaliation

## Problem Modeling
We are given two operations:
1. Decrease $a_i$ by $i$. Let $x$ be the total count of this operation.
2. Decrease $a_i$ by $n - i + 1$. Let $y$ be the total count of this operation.

For the array to explode, all elements must become zero. This implies:
$$a_i = x \cdot i + y \cdot (n - i + 1), \quad \forall i \in \{1, \dots, n\}$$

## Key Relationships
Summing the expressions for $a_1$ and $a_n$:
- $a_1 = x \cdot 1 + y \cdot n$
- $a_n = x \cdot n + y \cdot 1$
- $a_1 + a_n = (x + y) + n(x + y) = (n + 1)(x + y)$

Thus, the total operations $S = x + y$ must satisfy:
$$S = \frac{a_1 + a_n}{n + 1}$$
If $a_1 + a_n$ is not divisible by $n+1$, no solution exists.

## Binary Search Applicability
Substituting $y = S - x$ into the expression for $a_1$:
$$a_1 = x + n(S - x) = x(1 - n) + nS$$
As $x$ increases, $a_1$ strictly decreases (since $n \ge 2$). 
This monotonicity allows us to binary search for a unique $x \in [0, S]$.

## Validation
Once $x$ is found, we calculate $y = S - x$ and verify if the equation holds for all other $a_i$. If it does, we output `YES`.

## Complexity
- Time: $O(N)$ for each test case due to final array validation. Binary search takes $O(\log S)$.
- Space: $O(N)$ to store the array.
