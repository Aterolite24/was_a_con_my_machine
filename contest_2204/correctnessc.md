# Correctness Proof – Problem C: Spring

## Problem Modeling
- Alice visits on multiples of `a`, Bob on `b`, Carol on `c`.
- 1 visitor → 6L each. 2 visitors → 3L each. 3 visitors → 2L each.
- Compute total liters for each person over `[1, m]`.

## Inclusion-Exclusion Counting
Let `f(x, d) = ⌊x/d⌋` = number of multiples of `d` in `[1, x]`.

For Alice's liters in `[1, x]`:
- **Only Alice** visits: `f(x,a) − f(x,ab) − f(x,ac) + f(x,abc)` → contributes 6L each
- **Alice + Bob only**: `f(x,ab) − f(x,abc)` → contributes 3L each
- **Alice + Carol only**: `f(x,ac) − f(x,abc)` → contributes 3L each
- **All three**: `f(x,abc)` → contributes 2L each

Where `ab = lcm(a,b)`, `ac = lcm(a,c)`, `bc = lcm(b,c)`, `abc = lcm(a,b,c)`.

Symmetric formulas for Bob and Carol.

## LCM Cycle + Binary Search
The pattern repeats every `L = lcm(a,b,c)` days. We binary search for the largest `k` such that `k × L ≤ m` (number of full cycles). The remainder `m − k × L` is handled separately.

**Binary search predicate:** `mid ≤ ⌊m / L⌋` — monotone and decreasing, so standard binary search applies.

Total for each person = `k × (liters per cycle) + (liters in remainder)`.

## Complexity
- **Time:** O(log m) for binary search + O(1) per inclusion-exclusion computation = O(log m) per test case.
- **Space:** O(1).
