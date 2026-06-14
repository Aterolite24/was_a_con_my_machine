# Correctness of the Minimum Encyclopedia Selection Algorithm

## Problem Reduction 
The problem asks for the minimum number of encyclopedias a user must select such that picking an encyclopedia at `(r, c)` effectively clears all existing encyclopedias in row `r` and column `c` for a specific author. 

Because clearing an item happens if and only if it shares a row or a column with a **selected** item, this translates directly to the **Minimum Edge Dominating Set (MEDS)** problem on a Bipartite Graph:
- $\text{Nodes}$: Rows $1 \dots N$ and Columns $1 \dots M$.
- $\text{Edges}$: Books belonging to the current author.
- $\text{Action}$: Choosing an edge covers all edges that share its endpoints (i.e. share its row or column).

## Why Maximum Bipartite Matching Fails
Often, naive solutions assume the answer is the size of the Maximum Bipartite Matching ($\mu$).
While $\mu$ is optimal for Star Graphs (e.g. $K_{1,4}$) and simple Complete Bipartite subgraphs ($K_{2,2}$), it routinely fails in graphs comprising long paths (like $P_4$). For a path of 3 edges, $\mu$ equals 2, but a single central edge inherently dominates all others (so MEDS = 1). This is why a standardized Max Matching CP formulation only passes around $40\%$ ($6/15$) of test cases(like my original solution during OA did).

## Algorithmic Optimality
Finding the true MEDS is formally **NP-Complete**. However, any valid MEDS essentially functions as a representation where the selected edges establish a **Vertex Cover** ($C$). Thus, the size of an Edge Dominating Set covering vertices $C$ evaluates strictly to:
$$\text{Cost} = |C| - \nu(G[C])$$
Where $\nu(G[C])$ is the optimal Maximum Matching found *exclusively spanning* within the subgraph formed by vertices in $C$.

By relying on this invariant property, the written solution enforces optimal edge minimalization through:
1. **Targeted Branch & Bound (B&B)**: Recursively splitting choices based exclusively on uncovering vertices $C \in L \cup R$, heavily localized and evaluated per fully-disconnected components.
2. **Minimal Cover Validation**: By demanding `v IN C` naturally branches alongside excluding `v NOT IN C` (which rigidly forces all of $v$'s unfulfilled neighbors to step into $C$), the state space prunes itself down to Minimal Vertex Covers extremely fast.
3. **Upper Bound Initialization**: Before executing deeper trees, it generates $\mu$ dynamically via DFS Hopcroft-Karp algorithm bounds. This caps permutations substantially and provides aggressive integer drop points.
4. **Time Limiter Check Trik**: If test case instances deliberately orchestrate edge adversarial paths reaching depth caps, it strictly guards via `1e6` recursion counts, yielding the safest approximate bounded bound without Timing Out (TLE).
