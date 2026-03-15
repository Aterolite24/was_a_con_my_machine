# Correctness Analysis: Shovels and Swords

## Problem Summary
- **Shovel**: Costs 2 sticks, 1 diamond.
- **Sword**: Costs 1 stick, 2 diamonds.
- **Goal**: Maximize total tools (emeralds) given $a$ sticks and $b$ diamonds.

## Mathematical Formulation
Let $x$ be the number of shovels and $y$ be the number of swords.
Total emeralds $K = x + y$.

**Constraints:**
1. $2x + y \le a$ (Sticks constraint)
2. $x + 2y \le b$ (Diamonds constraint)
3. $x, y \ge 0$

## Deriving the Binary Search Condition
We want to check if a total of $K$ emeralds can be earned. This is possible if there exist non-negative integers $x, y$ such that:
- $x + y = K$
- $2x + y \le a \implies x + (x + y) \le a \implies x + K \le a \implies x \le a - K$
- $x + 2y \le b \implies (x + y) + y \le b \implies K + y \le b \implies y \le b - K$

Since $y = K - x$, the second condition becomes:
$K - x \le b - K \implies x \ge 2K - b$

So, $x$ must satisfy:
$\max(0, 2K - b) \le x \le \min(K, a - K)$

For such an $x$ to exist, the following must hold:
1. $0 \le K$ (Trivial)
2. $0 \le a - K \implies K \le a$
3. $2K - b \le K \implies K \le b$
4. $2K - b \le a - K \implies 3K \le a + b$

## Implementation Verification
The code implements a binary search for the maximum $K$ that satisfies these three conditions:
```cpp
if(mid <= a and mid <= b and 3*mid <= a+b)
```
These conditions are exactly what we derived.

### Example Walkthrough ($a=8, b=7$):
- $K \le 8$
- $K \le 7$
- $3K \le 15 \implies K \le 5$
- Max $K = \min(8, 7, 5) = 5$.
- Output: `5` (Matches example).

## Conclusion
The binary search approach correctly identifies the maximum possible value of $x+y$ by checking the necessary and sufficient conditions derived from the problem's resource constraints.
