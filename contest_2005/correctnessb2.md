# Correctness Analysis - The Strict Teacher (Hard Version)

## Problem Model
There are $m$ teachers and David on a discrete line from 1 to $n$. David and teachers move alternately:
1.  David moves to an adjacent cell or stays.
2.  All $m$ teachers move to an adjacent cell or stay.

David aims to maximize moves until any teacher occupies the same cell as him.

## Optimal Strategies

### 1. David is between Two Teachers $L$ and $R$
Suppose David is at $a$ and the nearest teachers are at $L$ and $R$ ($L < a < R$).
- David's best strategy is to stay at the midpoint $(L+R)/2$.
- The teachers' best strategy is to move towards each other, closing the gap.
- The distance between $L$ and $R$ is $R - L$. They meet at the midpoint in $\lfloor (R - L) / 2 \rfloor$ moves.
- Since David can move optimally to avoid being caught earlier by positioning himself exactly at the midpoint, the teachers can catch him in exactly $\lfloor (R - L) / 2 \rfloor$ moves.

### 2. David is Beyond All Teachers
#### a) David to the Left ($a < \min(b_i)$)
- David runs to cell 1.
- The nearest (leftmost) teacher $b_{min}$ chases him.
- David reaches 1 in $a-1$ moves. If the teacher reaches him before or at cell 1, the catch happens.
- However, since David wants to maximize moves, he runs towards the boundary opposite to the teacher.
- The teacher must travel the distance from $b_{min}$ to the boundary (cell 1) to catch a David who runs to 1. This takes $b_{min} - 1$ moves.

#### b) David to the Right ($a > \max(b_i)$)
- Symmetrically, David runs to cell $n$.
- The nearest (rightmost) teacher $b_{max}$ chases him.
- The teacher takes $n - b_{max}$ moves to catch him.

## Implementation Correctness
The implementation uses `std::sort` for teacher positions ($O(m \log m)$) and `std::upper_bound` ($O(\log m)$) for each query to locate $L$ and $R$.
- `it == v.begin()` correctly identifies "David to the Left".
- `it == v.end()` correctly identifies "David to the Right".
- Otherwise, `*it` and `*prev(it)` correctly identify the bounding teachers.

The total complexity $O(T \cdot (m+q) \log m)$ is efficient for $m, q \le 10^5$ and $T$ test cases.
