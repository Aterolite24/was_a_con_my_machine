#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem: Haunted House (1884B)
 * Goal: Minimum adjacent swaps to make number divisible by 2^i for i=1..n.
 * Approach: Binary Search (O(n log n))
 * 
 * Divisibility by 2^i requires the last i bits to be '0'.
 * We greedily pick the i rightmost '0's and move them to the last i positions.
 * To find the position of the k-th '0' from the right, we use binary search 
 * on the prefix sums of '0' counts.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Precalculate prefix sums of '0's
    // p[i] = number of '0's in s[0...i-1]
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + (s[i] == '0' ? 1 : 0);
    }

    int total_zeros = p[n];
    long long total_cost = 0;

    for (int i = 1; i <= n; ++i) {
        if (i > total_zeros) {
            cout << -1 << (i == n ? "" : " ");
            continue;
        }

        // We need the i-th '0' from the right.
        // This is the (total_zeros - i + 1)-th '0' from the left.
        int target_rank = total_zeros - i + 1;

        // Binary search for the index 'idx' such that p[idx] == target_rank
        // and p[idx-1] < target_rank.
        int low = 1, high = n;
        int pos = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (p[mid] >= target_rank) {
                pos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // pos is 1-indexed (position in original string s)
        // Adjusting to 0-indexed: actual_pos = pos - 1
        int actual_pos = pos - 1;
        
        // Target position for this '0' is (n - i)
        // Cost to move from actual_pos to (n - i)
        total_cost += (long long)((n - i) - actual_pos);
        
        cout << total_cost << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
