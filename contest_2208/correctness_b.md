# Correctness Analysis - Cyclists

## Problem Understanding
Maximize win-condition card plays given that only the first $k$ cards are playable and playing a card moves it to the bottom of the deck.

## Greedy Strategy
1. **Prioritize Win-Condition**: If the win-condition card is within the first $k$ positions, play it immediately. This directly increments the count and is optimal because any other play would cost energy without providing a direct benefit to the win count, and wouldn't necessarily make future win-condition plays cheaper.
2. **Cheapest Progress**: If the win-condition card is NOT in the first $k$ positions, play the card with the minimum cost among the first $k$ positions. Each play shifts the deck by 1, bringing the target card closer to the top. Minimizing the cost of these "gap-filler" plays preserves the most energy for the win-condition.

## Complexity
- In each step, we either play a win-condition or a non-win-condition.
- The win-condition card is initially at $p$.
- Total energy $m \le 5000$, and costs $a_i \ge 1$.
- Max iterations per test case $\le m$.
- Each iteration involves searching the first $k$ elements and a `vector::erase` (or similar), taking $O(n)$.
- Total complexity $O(\sum m \cdot n)$, which is $\approx 2.5 \cdot 10^7$ for the given constraints ($m \le 5000, n \le 5000, \sum n \le 5000$). This fits within the 1-second time limit.

## Implementation Details
- Used a `std::deque` (or vector) to simulate the deck.
- Tracked the win-condition using a boolean flag in a pair `(cost, is_win)`.
- Used `long long` for all numerical variables to avoid overflow and match the user's preferred style.
