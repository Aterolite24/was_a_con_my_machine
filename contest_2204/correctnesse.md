# Correctness Proof – Problem E: Sum of Digits

## Problem Analysis
The string $S(x)$ is defined as $x$ followed by its digit sum reduction chain.
Let $x = x_0$, $x_1 = \text{digit\_sum}(x_0)$, $x_2 = \text{digit\_sum}(x_1)$, ..., $x_k$ where $x_k \le 9$.
The string is $\text{str}(x_0) + \text{str}(x_1) + \dots + \text{str}(x_k)$.

## Invariant
The total sum of all digit characters $T$ in the string $S(x)$ is:
$T = \text{digit\_sum}(x_0) + \text{digit\_sum}(x_1) + \dots + \text{digit\_sum}(x_k)$
Since $\text{digit\_sum}(x_i) = x_{i+1}$ for $i < k$ and $\text{digit\_sum}(x_k) = x_k$:
$T = x_1 + x_2 + \dots + x_k + x_k$

## Algorithm
1. Calculate the total digit sum $T$ of the input string.
2. Iterate through all possible values of $d_1 = x_1$ (from 1 to $T$).
3. For each $d_1$, compute the chain $x_2, x_3, \dots, x_k$.
4. Check if $T = x_1 + x_2 + \dots + x_k + x_k$.
5. Verify if the digits in the chain $\text{str}(x_1) + \dots + \text{str}(x_k)$ are a subset of the input digits.
6. Verify if the remaining digits sum to $d_1$.
7. Construct $x$ from the remaining digits (ensuring no leading zero by sorting descending).

## Complexity
- **Time:** $O(T \cdot \text{chain\_length} + |s|) = O(T \cdot \text{log}(T) + |s|)$ per test case. Since $T \le 9 \cdot |s|$, and $|s| \le 10^5$, this fits within the 2s time limit.
- **Space:** $O(|s|)$.
