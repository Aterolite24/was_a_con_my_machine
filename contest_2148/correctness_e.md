# Correctness Analysis for Problem E - Split

## 1. Problem Insight
The problem asks us to find the number of "awesome" subarrays $a[l,r]$. A subarray $a[l,r]$ is awesome if we can partition all elements into $k$ multisets such that multiset 1 contains all elements from the subarray $a[l,r]$ (plus optionally elements from outside the subarray), and the remaining elements can be distributed into the other $k-1$ multisets such that all $k$ multisets become identical.

### Necessary and Sufficient Constraints:
For all $k$ multisets to be identical, every value $v$ present in the array must be uniformly distributed. 
1. The absolute total frequency of each element $v$, let's term it `cnt[v]`, MUST be divisible by $k$. If there exists any element where $cnt[v] \pmod k \neq 0$, then it is impossible to distribute it equally among $k$ sets, resulting in $0$ awesome subarrays globally.
2. If `cnt[v]` is divisible by $k$, each sequence multiset inevitably requires exactly $req[v] = cnt[v] / k$ copies of $v$.
3. Because multiset 1 automatically collects all elements originating from the subarray $a[l,r]$, the frequency of any element $v$ STRICTLY within the subarray, let's designate it $c_{in}(v)$, must not surpass its quota. Namely: $c_{in}(v) \le req[v]$.
4. Whatever frequency deficit exists ($req[v] - c_{in}(v)$) can unrestrictedly be fulfilled from outside elements since the count outside is guaranteed to suffice: $cnt[v] - c_{in}(v) \ge cnt[v] - req[v] = (k-1)req[v]$, meaning there are also unequivocally enough tokens left to fulfill exactly the quotas for the residual $k-1$ multisets.
5. In conclusion, subarray $a[l,r]$ is valid **if and only if** for all elements $v \in a[l,r]$, the local occurrence within the subarray satisfies $c_{in}(v) \le req[v]$.

## 2. Using Binary Search
To count total valid subarrays efficiently, we establish the maximum valid right boundary $r$ for any fixed left boundary $l$. 
1. We compute `pos[x]`, storing the monotonic list of positional indices where element `x` appeared in the array.
2. For an element starting exactly at index $i$, it will violate its quota natively at its $(req[a[i]] + 1)$-th occurrence. We implement a **Custom Binary Search** (`customBinarySearch` mapping explicit positional comparisons natively instead of relying on `<algorithm>` functions like `std::lower_bound`) over `pos[a[i]]` to quickly query the index of element $i$.
3. Bounding the occurrence index with $+ req[a[i]]$, we map exactly where the subarray becomes disqualified, which we denote as $bad[i]$.
4. The longest sequence adhering to constraints spanning from $l$ cannot contain **any** such interval $[i, bad[i]]$. As a result, $r$ is effectively bound mathematically: $r \le \min_{i \ge l} (bad[i]) - 1$.
5. We optimize this minimum logic iteratively to a linear suffix-minimum array termed `min_bad`, yielding the direct threshold constraints for every $l$. Overall valid derivations sequentially total to $(min\_bad[l] - l)$.

## 3. Complexity
- **Time Complexity:** Sorting and indexing occurs natively upon iterating input. Locating occurrences per item mandates Custom Binary Searches. With exactly $n$ occurrences traversed and bound vectors maximally spanning lengths of $n$, the routine resolves robustly in $O(N \log N)$ total time overall execution.
- **Space Complexity:** Frequency arrays, limits mappings (`bad`, `min_bad`), and multiset position vectors scale evenly maintaining a strict upper bounds profile. Total required storage safely runs bounded at $O(N)$ with practically low scalar multipliers.
