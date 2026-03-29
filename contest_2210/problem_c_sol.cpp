#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Choice {
    ll x;
    int cost;
};

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    if (n == 1) {
        if (b[0] >= 1 && (b[0] > 1 || a[0] != 1)) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
        return;
    }

    vector<ll> g(n - 1);
    for (int i = 0; i < n - 1; i++) {
        g[i] = std::gcd(a[i], a[i + 1]);
    }

    vector<ll> L(n);
    L[0] = g[0];
    L[n - 1] = g[n - 2];
    for (int i = 1; i < n - 1; i++) {
        L[i] = (g[i - 1] / std::gcd(g[i - 1], g[i])) * g[i];
    }

    vector<vector<Choice>> C(n);
    for (int i = 0; i < n; i++) {
        ll unchanged = a[i] / L[i];
        C[i].push_back({unchanged, 0});
        int added = 0;
        for (ll x = 1; x * L[i] <= b[i] && added < 40; x++) {
            if (x == unchanged) continue;
            bool ok = true;
            if (i > 0 && std::gcd(x, L[i - 1] / g[i - 1]) > 1) ok = false;
            if (i < n - 1 && std::gcd(x, L[i + 1] / g[i]) > 1) ok = false;
            if (ok) {
                C[i].push_back({x, 1});
                added++;
            }
        }
    }

    vector<int> dp_prev(C[0].size());
    for (size_t j = 0; j < C[0].size(); j++) {
        dp_prev[j] = C[0][j].cost;
    }

    for (int i = 1; i < n; i++) {
        vector<int> dp_curr(C[i].size(), -1);
        for (size_t j = 0; j < C[i].size(); j++) {
            for (size_t k = 0; k < C[i - 1].size(); k++) {
                if (dp_prev[k] != -1 && std::gcd(C[i][j].x, C[i - 1][k].x) == 1) {
                    dp_curr[j] = max(dp_curr[j], dp_prev[k] + C[i][j].cost);
                }
            }
        }
        dp_prev = move(dp_curr);
    }

    int gcdcode = 0;
    for (size_t j = 0; j < dp_prev.size(); j++) {
        gcdcode = max(gcdcode, dp_prev[j]);
    }
    cout << gcdcode << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
