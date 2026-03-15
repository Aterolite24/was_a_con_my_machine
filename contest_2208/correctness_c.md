# Correctness Analysis - Stamina and Tasks

## Problem Understanding
Maximize total points $\sum S_i \cdot c_i$, where $S_i$ is the stamina at task $i$. 
- Initial stamina $S_1 = 1$.
- If task $i$ is completed, $S_{i+1} = S_i \cdot (1 - p_i/100)$.
- If task $i$ is skipped, $S_{i+1} = S_i$.

## Dynamic Programming Approach
Let $dp[i]$ be the maximum possible gain from tasks $i$ through $n$, assuming the stamina at the start of task $i$ is $1$.

### Recurrence Relation
For task $i$, we have two choices:
1. **Skip Task $i$**: The gain is simply $dp[i+1]$ (since stamina remains unchanged).
2. **Complete Task $i$**: The gain is $1 \cdot c_i$ (points for task $i$) plus the maximum gain from tasks $i+1 \dots n$ starting with stamina $(1 - p_i/100)$. Since the total gain scales linearly with the starting stamina, this is $(1 - p_i/100) \cdot dp[i+1]$.

Thus:
$$dp[i] = \max(dp[i+1], c_i + (1 - p_i/100) \cdot dp[i+1])$$

### Why Backwards DP?
If we tried forwards DP, we would need to track the current stamina as part of the state, which is a real number and would lead to an infinite state space. By working backwards, we leverage the linearity of the points gain: $Gain(S, i \dots n) = S \cdot Gain(1, i \dots n)$.

## Complexity
- **Time Complexity**: $O(T \cdot n)$, which is $O(10^5)$ total across all test cases.
- **Space Complexity**: $O(n)$ to store tasks, and $O(1)$ for the DP variable if implemented iteratively.

## Numerical Stability
- Using `long double` for intermediate DP calculations ensures sufficient precision for the $10^{-6}$ error bound.
- The values are always non-negative and monotonically non-decreasing as we move from $n$ to $1$.
