# Correctness Analysis - ConneR and the A.R.C. Markland-N (Binary Search)

## Problem Understanding
Find the minimum distance $d$ from floor $s$ to an open floor in a building with $n$ floors, where $k$ floors are closed.

## Algorithm: Binary Search on Distance $d$

### 1. Monotonicity
Let $P(d)$ be the predicate: "There exists at least one open floor in the range $[s-d, s+d]$".
- If $P(d)$ is true, then $P(d+1)$ is also true because the range $[s-(d+1), s+(d+1)]$ is a superset of $[s-d, s+d]$.
- We want to find the smallest $d$ such that $P(d)$ is true.
- Since $P(d)$ is monotonic (F...FT...T), we can use Binary Search.

### 2. Feasibility Check ($P(d)$)
To check if any floor in the range $[L, R] = [\max(1, s-d), \min(n, s+d)]$ is open:
1. Count the number of closed floors in the building that fall within $[L, R]$.
2. This can be done efficiently in $O(\log k)$ using `std::upper_bound` and `std::lower_bound` on the sorted list of closed floors.
3. Total floors in $[L, R]$ is $R - L + 1$.
4. If `count_closed < total_floors`, then at least one floor in the range must be open.

### 3. Search Space
The maximum distance $d$ required is at most $k+1$, because even if the $k$ floors closest to $s$ are all closed, the $(k+1)$-th floor (if it exists within building bounds) must be open. $k \le 1000$ and $n \le 10^9$.

### 4. Complexity
- **Preprocessing**: $O(k \log k)$ to sort a list of $k$ floors.
- **Binary Search**: $O(\log k)$ steps.
- **Check Function**: $O(\log k)$ per call.
- **Total Time**: $O(T \cdot k \log k)$. Given $\sum k \le 1000$, this is extremely fast.

## Example Trace
`5 2 3`, closed `{1, 2, 3}`. Colin at 2.
- $d=0$: Range [2, 2]. Closed in range: {2}. Count=1. Total=1. $1 < 1$ is False.
- $d=1$: Range [1, 3]. Closed in range: {1, 2, 3}. Count=3. Total=3. $3 < 3$ is False.
- $d=2$: Range [1, 4]. Closed in range: {1, 2, 3}. Count=3. Total=4. $3 < 4$ is True!
Result: $d=2$.
