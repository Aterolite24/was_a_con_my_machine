# Correctness Analysis - Brightness Begins

## Problem Transformation

We are given $n$ light bulbs, initially all ON. For each $i = 1, 2, \ldots, n$, we flip the state of all bulbs $j$ where $j$ is divisible by $i$. We want to find the smallest $n$ such that exactly $k$ bulbs remain ON.

### Lemma 1: Final state of bulb $x$
A bulb $x$ is flipped once for every $i \in \{1, 2, \ldots, n\}$ such that $i$ is a divisor of $x$. If $d(x)$ is the number of divisors of $x$:
- If $d(x)$ is even, the bulb ends in its initial state (ON).
- If $d(x)$ is odd, the bulb ends in the opposite of its initial state (OFF).

### Lemma 2: Square numbers
An integer $x$ has an odd number of divisors if and only if $x$ is a perfect square.
- Proof: Divisors come in pairs $(d, x/d)$. A divisor $d$ is only paired with itself if $d = x/d$, i.e., $x = d^2$.

### Corollary
Bulb $x$ is OFF if and only if $x$ is a perfect square. Otherwise, it is ON.

## Mathematical Model

For a given $n$, the number of bulbs that are OFF is the number of perfect squares in the range $[1, n]$. This is exactly $\lfloor\sqrt{n}\rfloor$.
Therefore, the number of bulbs that remain ON is:
$$f(n) = n - \lfloor\sqrt{n}\rfloor$$

We need to find the smallest $n$ such that $f(n) = k$.

### Lemma 3: Monotonicity
$f(n)$ is a non-decreasing function of $n$.
- Proof: $f(n+1) - f(n) = (n+1 - \lfloor\sqrt{n+1}\rfloor) - (n - \lfloor\sqrt{n}\rfloor) = 1 - (\lfloor\sqrt{n+1}\rfloor - \lfloor\sqrt{n}\rfloor)$.
- Since $\lfloor\sqrt{n+1}\rfloor - \lfloor\sqrt{n}\rfloor$ is either 0 or 1, $f(n+1) - f(n) \ge 0$.
- Specifically, $f(n)$ stays constant only when $n+1$ is a perfect square. When $n+1$ is NOT a perfect square, $f(n)$ increases by 1.

Since $f(n)$ is non-decreasing, we can use binary search to find the smallest $n$ such that $f(n) \ge k$.

## Binary Search Implementation

### Bounds
- Lower bound $l = 1$: For $k \ge 1$, $n$ must be at least 1.
- Upper bound $r = 2 \cdot 10^{18}$: Since $n - \sqrt{n} \approx k$, for $k = 10^{18}$, $n$ will be around $10^{18} + 10^9$. $2 \cdot 10^{18}$ is a safe upper bound.

### Precision
$10^{18}$ fits in a 64-bit `long long`. To avoid precision issues with `sqrtl` (which uses `long double`), we include adjustment loops:
```cpp
ll sq = sqrtl(mid);
while(sq*sq > mid) sq--;
while((sq+1)*(sq+1) <= mid) sq++;
```
This ensures `sq` is exactly $\lfloor\sqrt{mid}\rfloor$.

### Smallest $n$
The binary search finds the first $mid$ where $f(mid) \ge k$. Since $f(n)$ only stays constant when $n$ is a perfect square (and perfect squares are OFF), the first $n$ such that $f(n) \ge k$ will always satisfy $f(n) = k$ and be the smallest such $n$.
Specifically, if $f(m^2-1) = k$ and $f(m^2) = k$, the binary search will correctly pick $m^2-1$.
