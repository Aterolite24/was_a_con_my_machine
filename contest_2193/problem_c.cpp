#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n, q; cin >> n >> q;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++) a[i] = max(a[i], b[i]);
        if(n>1) for(int i=n-2; i>=0; i--) a[i] = max(a[i], a[i+1]);
        vector<int> sum(n+1);
        sum[0] = 0;
        for(int i=1; i<n+1; i++) sum[i] = sum[i-1]+a[i-1];
        // cout << "sum\n";
        // for(auto i: sum) cout<<i << " ";cout <<"\n";
        while(q--){
            int l, r; cin >> l >> r;
            l--;
            cout << sum[r] - sum[l] << " ";
        } cout << "\n";
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