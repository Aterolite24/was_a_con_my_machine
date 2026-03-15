# Correctness Analysis - Frog Jumps (Binary Search)

## Problem Understanding
The frog starts at cell 0 and wants to reach cell $n+1$. At any cell $i$, it can jump at most $d$ cells.
- If $s[i] = 'L'$, it jumps to $[idx-d, idx-1]$.
- If $s[i] = 'R'$, it jumps to $[idx+1, idx+d]$.
- At cell 0, it can only jump to the right.

## Algorithm: Binary Search on Jump Distance $d$

### 1. Monotonicity
Let $P(d)$ be a predicate that is true if the frog can reach $n+1$ with a maximum jump distance $d$.
If the frog can reach the destination with distance $d$, it can also reach it with any distance $d' > d$. This monotonicity allows us to binary search for the minimum $d$.

### 2. Feasibility Check ($P(d)$)
The problem reduces to checking if the maximum distance between consecutive 'R' positions (including 0 and $n+1$) is at most $d$.
Let $R = \{r_0, r_1, \dots, r_{m+1}\}$ be the set of indices of 'R' characters in $s$, with $r_0 = 0$ and $r_{m+1} = n+1$.
$P(d)$ is true if $\max(r_{i+1} - r_i) \le d$ for all $i$.

### 3. Complexity
- **Binary Search**: $O(\log N)$ steps.
- **Check Function**: $O(N)$ per call.
- **Total Time**: $O(T \cdot N \log N)$. Given $\sum |s| \le 2 \cdot 10^5$, this fits easily within 2 seconds.
