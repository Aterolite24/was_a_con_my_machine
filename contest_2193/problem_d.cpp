#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void solve() {
        int n; 
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        vector<ll> pref(n);
        pref[0] = b[0];
        for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + b[i];
        ll ans = 0;
        for(int i = 0; i < n; ) {
            int x = a[i];
            int swords = n - i;
            int levels = upper_bound(pref.begin(), pref.end(), swords) - pref.begin();
            ans = max(ans, (ll)x * levels);
            while(i < n && a[i] == x) i++;
        }
        cout << ans << "\n";
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}
