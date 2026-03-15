# Correctness of Binary Search for "Increase and Copy"

The problem asks for the minimum moves to get an array sum $\ge n$ starting from `[1]`.
Available moves:
1. **Increase**: $a_i = a_i + 1$
2. **Copy**: $a_{new} = a_i$

## Mathematical Strategy

To maximize the sum for a fixed total number of moves $m$, we should:
1. Spend $x$ moves increasing the initial element from $1$ to $x+1$.
2. Spend $y$ moves copying that element.
3. Total moves $m = x + y$.
4. Total elements in the array: $y + 1$.
5. Total sum: $(x+1) \cdot (y+1)$.

To maximize $(x+1)(y+1)$ given $x+y=m$, we should make $x+1$ and $y+1$ as equal as possible (since the product of two numbers with a fixed sum is maximized when they are equal).

Let $A = x+1$ and $B = y+1$.
The sum of $A+B = (x+1) + (y+1) = (x+y) + 2 = m+2$.
The maximum product $A \cdot B$ is achieved when $A \approx B \approx \frac{m+2}{2}$.

## Binary Search Logic in Code

In your code:
```cpp
ll mid = l + (r - l) / 2;
if ((mid * mid) / 4 >= n) { ... }
```
Here, `mid` represents $m+2$.

### Why `(mid * mid) / 4`?
If $m+2$ is even, $A = B = \frac{mid}{2}$. Product $= \frac{mid}{2} \cdot \frac{mid}{2} = \frac{mid^2}{4}$.
If $m+2$ is odd, $A = \lfloor \frac{mid}{2} \rfloor, B = \lceil \frac{mid}{2} \rceil = \lfloor \frac{mid}{2} \rfloor + 1$.
Product $= k(k+1)$ where $k = \lfloor \frac{mid}{2} \rfloor$.

Note that $\lfloor \frac{(2k+1)^2}{4} \rfloor = \lfloor \frac{4k^2 + 4k + 1}{4} \rfloor = k^2 + k = k(k+1)$.
So integer division `(mid * mid) / 4` correctly gives the maximum possible product for both even and odd values of `mid`.

### Final Answer: `ans - 2`
Since `mid` represents $m+2$, the number of moves $m$ is `mid - 2`.

## Complexity
- **Time**: $O(T \cdot \log N)$ where $T=1000, N=10^9$. $\log_2(10^9) \approx 30$. Total operations $\approx 3 \cdot 10^4$, very fast.
- **Space**: $O(1)$.
- **Overflow**: `long long` handles up to $\approx 9 \cdot 10^{18}$. Since $n \le 10^9$, `mid` is $\approx 63245 \times 2$ (at most), so `mid * mid` is well within limits.
