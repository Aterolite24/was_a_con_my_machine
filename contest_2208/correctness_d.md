# Correctness Analysis - Tree Orientation (Easy Version)

## Problem Understanding
Find a directed tree whose transitive closure matches a given reachability matrix $R$.

## Algorithm: Transitive Reduction

### 1. Prerequisite: Directed Acyclic Graph (DAG)
An oriented tree is always a DAG. If the input matrix $R$ has any cycle ($u \neq v$ where $R_{u,v}=1$ and $R_{v,u}=1$), it cannot be an oriented tree.

### 2. Identifying Tree Edges
In any DAG, the transitive reduction consists of exactly those edges $(u, v)$ that are not "shortcut" by any intermediate path.
- Edge $(u, v)$ is a tree edge if:
  1. $R_{u,v} = 1$ and $u \neq v$.
  2. There is no node $w$ such that $R_{u,w} = 1$, $R_{w,v} = 1$, $w \neq u$, and $w \neq v$.
- Using bitsets, let $O_u$ be the set of nodes reachable from $u$ (out-set) and $I_v$ be the set of nodes that can reach $v$ (in-set).
- The edge $(u, v)$ exists if $(O_u \cap I_v) = \{u, v\}$.

### 3. Verification
A set of $n-1$ directed edges forms an oriented tree if:
1. It has exactly $n-1$ edges.
2. The undirected graph formed by these edges is connected.
3. The transitive closure of these edges matches the input matrix $R$.

## Complexity
- **Time**: $O(n^3/w)$ using bitsets for $O_u \cap I_v$ intersection and $O(n \cdot (n + e))$ for transitive closure verification.
- **Space**: $O(n^2/w)$ for bitsets.
With $n=500$, this is well within the 3-second time limit.
