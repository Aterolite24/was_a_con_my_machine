# Correctness of Binary Search Logic

## Explanation
The given problem is "A. Rank List". Teams are compared primarily by the total problems solved (descending), and secondarily by penalty time (ascending). Since the array is already sorted based on this custom comparator, teams with the exact same score (problems solved and penalty time) will appear in a contiguous block within the array.

Let the targeted score at the $k$-th position (index `k - 1`) be `(p_k, t_k)`. Our objective is to find the first occurrence (`L`) and the last occurrence (`R`) of this exact score within the array using binary search. The final answer is the number of teams residing between these borders inclusively: `R - L + 1`.

### Searching for Left Boundary (`L`)
To find the first index of `(p_k, t_k)`, we perform a binary search over the array `[0, n-1]`:
- First, we investigate `mid`. If `v[mid]` is strictly better than the target (i.e., `v[mid].first > p_k` or `v[mid].first == p_k && v[mid].second < t_k`), the left boundary definitely lies to its right. We close the gap by setting `l = mid + 1`.
- Otherwise, `v[mid]` is strictly worse or exactly equal to the target. In both these possibilities, the initial occurrence must be located to its left. We do `r = mid - 1`.
- Lastly, if `v[mid]` is exactly equal to `(p_k, t_k)`, we additionally record this mid as a candidate for the true left boundary: `L = mid`.

### Searching for Right Boundary (`R`)
To find the final index of `(p_k, t_k)`, we execute a second binary search over the array constraints `[L, n-1]`:
- If `v[mid]` is strictly worse than the target (i.e., `v[mid].first < p_k` or `v[mid].first == p_k && v[mid].second > t_k`), then the tail occurrence must lie to its left. Therefore, we shift boundaries by executing `r = mid - 1`.
- Otherwise, `v[mid]` is strictly better or exactly equal. In both instances, the last occurrence must expand to its right. Consequently, we shift boundaries by executing `l = mid + 1`.
- Notice that if `v[mid]` exactly matches `(p_k, t_k)`, we register this position as a valid possibility for the true right boundary: `R = mid`.

## Complexity
- **Time Complexity:** Pre-sorting the array takes $\mathcal{O}(N \log N)$. Implementing two isolated binary searches takes $\mathcal{O}(\log N)$ each. Overall worst-case time consumption is $\mathcal{O}(N \log N)$, which runs instantly for small constraints like $N \le 50$.
- **Space/Auxiliary Complexity:** We only require allocating memory for an array mapping vectors of size $N$, yielding an extremely optimal memory footprint of $\mathcal{O}(N)$.
