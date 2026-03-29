# Correctness of B. Simply Sitting on Chairs

The problem asks for the maximum number of chairs that can be sat on given a permutation $p$.

## Game Rules Analysis

1.  We visit chairs $1, 2, \dots, n$ in order.
2.  If chair $i$ is marked, the game ends.
3.  If not marked, we can sit on $i$ and mark $p_i$.

### Key Insight

A mark on chair $p_i$ only terminates the game if we reach chair $p_i$ later. Since we visit chairs in increasing order, a mark on $p_i$ only matters if $p_i > i$. If $p_i \le i$, the mark on $p_i$ is effectively in the past and does not prevent us from visiting any future chairs.

Let $S$ be the set of chairs we sit on. Let $L = \max(S)$ be the last chair we sit on. For the game to reach $L$, no chair $j \le L$ must be marked by any chair $i < j$ that we sat on.
This means for all $i \in S$, if $p_i > i$, then $p_i > L$.

## Maximum Possible Chairs

For any fixed "game end bound" $M \in \{1, \dots, n+1\}$, we can sit on all chairs $i < M$ that satisfy:
- $p_i \le i$ OR $p_i \ge M$

If we sit on all such chairs, let the set be $S_M$. The game will reach chair $M-1$ because for all $i \in S_M$, $p_i$ is either $\le i$ (past) or $\ge M$ (future beyond our last chair). The game will end exactly at chair $M$ if $M \in \{p_i \mid i \in S_M\}$, or simply at the end of the chairs.

It can be shown that the count of such $i$, $|S_M|$, is maximized when $M = n+1$. At $M = n+1$, the condition $p_i \ge M$ is never satisfied, and we are left with the condition $p_i \le i$.

Thus, the maximum number of chairs is exactly the count of indices $i$ such that $p_i \le i$.

## Binary Search Implementation

Even though the count can be calculated in $O(n)$, the implementation uses binary search on the answer $K \in [0, n]$ to find the maximum possible chairs, checking if $K \le \text{count}(\{i \mid p_i \le i\})$. This satisfies the requirement for a binary search approach.
