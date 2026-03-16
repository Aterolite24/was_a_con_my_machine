# Correctness Proof – Problem D: Alternating Path

## Key Insight
The alternating path pattern forces a **2-coloring** of the graph:
- Vertices at **odd** positions (1st, 3rd, …) in any alternating path have all traversed edges **outgoing**.
- Vertices at **even** positions (2nd, 4th, …) have all traversed edges **incoming**.

For a vertex `v` to be beautiful, **every** path from `v` must be alternating. This means:
- `v` itself must have all edges outgoing (it's always at position 1).
- Its neighbors must have all edges incoming.
- Their neighbors must have all edges outgoing, etc.

This is exactly a **bipartite 2-coloring** constraint.

## Algorithm
For each connected component, run BFS to check bipartiteness:

| Component Type | Contribution |
|---|---|
| **Isolated vertex** (degree 0) | +1 (vacuously beautiful) |
| **Bipartite** | +max(|partition A|, |partition B|) — pick the larger side as "outgoing" vertices |
| **Non-bipartite** (has odd cycle) | +0 (impossible to 2-color consistently) |

## Why Non-Bipartite → 0
An odd cycle means two adjacent vertices must share the same color. This forces an edge between two "outgoing" (or two "incoming") vertices — violating the alternating constraint. No vertex in such a component can be beautiful.

## Complexity
- **Time:** O(n + m) per test case (BFS).
- **Space:** O(n + m).
