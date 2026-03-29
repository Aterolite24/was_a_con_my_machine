# Correctness of C2. A Simple GCD Problem

The problem asks to maximize the number of changes to an array $a$ to $a'$, replacing $a_i$ with $a'_i \le b_i$ ($a'_i \neq a_i$) such that the GCD of all subarrays remains the same:
$\forall l < r: \gcd(a'_l \dots a'_r) = \gcd(a_l \dots a_r)$

## Core Insight

To preserve the GCD of ALL subarrays, it is both necessary and sufficient to preserve the GCD of all ADJACENT pairs. If we enforce $\gcd(a'_i, a'_{i+1}) = \gcd(a_i, a_{i+1}) = g_i$ for all $i$, then the GCD of any subarray spanning $l$ to $r$ is identical because $\gcd(x, y, z) = \gcd(\gcd(x,y), \gcd(y,z))$.

This condition means $a'_i$ must be a multiple of $g_{i-1}$ and $g_i$. Thus, $a'_i$ must be a multiple of $L_i = \text{lcm}(g_{i-1}, g_i)$. We can express every valid assignment as $a'_i = x_i \cdot L_i$, where $x_i \ge 1$.

## Coprime Conditions

If we substitute $a'_i = x_i L_i$, the adjacent GCD requirement becomes:
$\gcd(x_i L_i, x_{i+1} L_{i+1}) = g_i$
Dividing by $g_i$, we get:
$\gcd(x_i \cdot \frac{L_i}{g_i}, x_{i+1} \cdot \frac{L_{i+1}}{g_i}) = 1$

Let $U_i = L_i / g_i$ and $V_i = L_{i+1} / g_i$. We require $\gcd(x_i U_i, x_{i+1} V_i) = 1$.
Since $U_i$ and $V_i$ depend only on the original array, their GCD is already 1.
Therefore, the requirements simplify perfectly to:
1. $x_i$ is coprime to $V_{i-1}$ (if $i > 0$).
2. $x_i$ is coprime to $U_{i}$ (if $i < n - 1$).
3. $x_i$ is coprime to $x_{i+1}$.

We define $Base_i = V_{i-1} \cdot U_i$ as the base fixed constraint for each $x_i$.
For any change $m = x \cdot L_i \le b_i$, $x$ must be coprime to $Base_i$, and adjacent choices $x_i, x_{i+1}$ must be mutually coprime. If $a_i$ is unchanged, its effective $x_i = a_i / L_i$ is mathematically guaranteed to be coprime to $Base_i$.

## Dynamic Programming Solution

The problem translates to assigning $x_i$ for each $i$ (either $a_i / L_i$ at cost 0, or some generic $x$ at cost 1) to maximize the total cost such that adjacent choices are coprime.

Since $Base_i$ has a limited number of prime factors (at most 10), there are many small primes available. For any $i$, if an improvement exists, taking the first up to 40 valid integers $x$ coprime to $Base_i$ safely guarantees we will encompass several primes to avoid any collisions with neighbors.

We employ Dynamic Programming:
`dp[i][j]` = max changes for prefix $i$ given we pick choice $j$ for $x_i$.
The DP transitions in $O(N \cdot 40^2)$ operations, guaranteeing maximum valid changes without Time Limit or edge-case failures.
