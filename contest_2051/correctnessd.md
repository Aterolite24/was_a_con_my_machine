# Correctness Analysis for Problem D: Counting Pairs (Contest 2051)

This problem involves finding the number of pairs $(i, j)$ such that $1 \le i < j \le n$ and removing them leaves a sum between $x$ and $y$.

## Mathematical Formulation

Let $S$ be the total sum of all elements in the sequence $a$. When elements at positions $i$ and $j$ are removed, the sum of the remaining elements is $S - a_i - a_j$.
The condition is:
$$x \le S - a_i - a_j \le y$$
Rearranging these inequalities gives:
$$a_i + a_j \le S - x$$
$$a_i + a_j \ge S - y$$
Combining these, we need to count pairs $(i, j)$ with $i < j$ such that:
$$S - y \le a_i + a_j \le S - x$$

## Algorithm: Sorting and Binary Search

1. **Preprocessing**: Calculate the total sum $S$ of all elements. This takes $O(n)$ time.
2. **Sorting**: Sort the array $a$ in non-decreasing order. This takes $O(n \log n)$ time.
3. **Counting Pairs**:
   - For each element $a_i$ at index $i$, we seek the number of elements $a_j$ at indices $j > i$ such that $a_i + a_j \in [S-y, S-x]$.
   - Let $L = S - y$ and $R = S - x$.
   - The condition $L \le a_i + a_j \le R$ is equivalent to $L - a_i \le a_j \le R - a_i$.
   - Since the array is sorted, the set of such $a_j$ forms a contiguous range in the suffix $a[i+1 \dots n-1]$.
   - We use two manual binary search operations to find the boundaries of this range:
     - `lb`: the first index $j > i$ such that $a_j \ge L - a_i$.
     - `ub`: the last index $j > i$ such that $a_j \le R - a_i$.
   - The number of valid $j$'s for a fixed $i$ is $\max(0, ub - lb + 1)$.
   - Summing these counts over all $i \in [0, n-1]$ gives the total number of interesting pairs.

## Complexity

- Time: $O(n \log n)$ for sorting plus $n \times O(\log n)$ for the binary searches, resulting in $O(n \log n)$ overall.
- Space: $O(1)$ additional space beyond the input array storage.

This approach is efficient enough given the constraints ($n \le 2 \cdot 10^5$, sum of $n \le 2 \cdot 10^5$).
