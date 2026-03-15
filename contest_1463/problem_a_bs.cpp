#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem A: Dungeon
 * Solution Using Binary Search
 * 
 * Logic:
 * Each 7-shot cycle deals 6 * 1 (regular) + 3 * 1 (enhanced) = 9 damage.
 * The total health sum must be a multiple of 9.
 * Let x be the number of cycles (number of enhanced shots).
 * Then 9 * x = sum(a, b, c).
 * Also, each monster must have at least x health points to survive until the x-th enhanced shot.
 * So x <= min(a, b, c).
 * 
 * We use binary search to find x such that 9 * x = a + b + c.
 */

void solve() {
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return;

    long long sum = a + b + c;
    long long min_health = min({a, b, c});

    // Binary search for the number of enhanced shot cycles x
    long long low = 0, high = 1e9; // 1e8 is enough since health <= 1e8
    long long x = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (9 * mid == sum) {
            x = mid;
            break;
        } else if (9 * mid < sum) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (x != -1 && x <= min_health) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
