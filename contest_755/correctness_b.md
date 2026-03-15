# Correctness of Binary Search Approach for PolandBall and Game

## Problem Recap
PolandBall and EnemyBall take turns saying words from their respective known lists. A word cannot be repeated. PolandBall plays first. The player who cannot say a new word loses. Both play optimally.

## Optimal Strategy
When a player makes a move, they have a choice:
1. Play a word that only they know (a unique word).
2. Play a word that both players know (a common word).

If a player plays a unique word, it only decreases their own pool of available words by 1.
If a player plays a common word, it decreases their own pool of available words by 1, AND it also decreases the opponent's pool of available words by 1, because the opponent can no longer say that word.

Therefore, the **optimal strategy** for both players is to prioritize saying the **common words** first. Doing so is strictly better (or at least as good) as playing a unique word, because it denies an option to the opponent while securing a valid move for themselves.

## Game Resolution
Let $C$ be the number of common words both players know.
Let $N$ be the total number of words PolandBall knows.
Let $M$ be the total number of words EnemyBall knows.

Since both players optimally play common words first, they will alternate picking from the pool of $C$ common words.
- PolandBall plays the 1st common word.
- EnemyBall plays the 2nd common word.
- PolandBall plays the 3rd common word.
... and so on.

### Case 1: $C$ is even
If the number of common words is even, say $2k$, then PolandBall will play exactly $k$ common words, and EnemyBall will play exactly $k$ common words.
After all common words are exhausted, it will be PolandBall's turn. 
At this point:
- PolandBall has $N - C$ unique words left.
- EnemyBall has $M - C$ unique words left.

Since it is PolandBall's turn, PolandBall will win if and only if they have strictly more unique words than EnemyBall.
Condition for PolandBall to win: $N - C > M - C$ $\implies$ $N > M$.

### Case 2: $C$ is odd
If the number of common words is odd, say $2k + 1$, then PolandBall will play $k + 1$ common words, and EnemyBall will play $k$ common words.
After all common words are exhausted, it will be EnemyBall's turn (since PolandBall took the last common word).
At this point:
- PolandBall has $N - C$ unique words left.
- EnemyBall has $M - C$ unique words left.

Since it is EnemyBall's turn, EnemyBall will win if they have strictly more unique words than PolandBall. Thus, PolandBall will win if they have greater than or equal unique words to EnemyBall.
Condition for PolandBall to win: $N - C \ge M - C$ $\implies$ $N \ge M$.

## Using Binary Search Objectively
The only unknown in this formula is $C$, the number of common words. 
Instead of using a `std::set` (which involves overhead for node allocation and pointers), we can use a more cache-friendly array or vector and `std::binary_search`.

1. Store EnemyBall's $M$ words in a `std::vector<string>`.
2. Sort the vector in $O(M \log M)$ string comparisons.
3. For each of PolandBall's $N$ words, use `std::binary_search` against EnemyBall's sorted vector to check if it's a common word. Each query takes $O(\log M)$ string comparisons.

**Correctness:**
The sorting puts EnemyBall's words in lexicographical order. The `std::binary_search` correctly checks for string presence in a sorted collection. The formula using $N$, $M$, and $C \pmod 2$ perfectly matches the game theoretic optimal behavior.

**Time Complexity:** 
- Sorting EnemyBall's array: $O(M \log M \times \text{length})$
- Binary searching $N$ words: $O(N \log M \times \text{length})$
Total Time: $O((N+M) \log M \times \text{length})$. Since $N, M \le 1000$, this is extremely fast and easily passes within the 1-second limit.
Space Complexity: $O(N \times \text{length} + M \times \text{length})$ to store the strings.
