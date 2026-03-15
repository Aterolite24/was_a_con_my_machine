#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void solve() {
        ll n,m,mx = 0; cin>>n>>m;
        vector<ll>a(n); for (int i=0;i<n;i++) cin>>a[i], mx=max(mx, a[i]);
        ll max_k=mx+m;
        ll l=mx,r=mx+m,min_k=mx+m;
        while(l<=r){
            ll mid=l+(r-l)/2;
            ll req=0;
            for(int i=0;i<n;i++) req+=max(0LL, mid-a[i]);
            if (req>=m){
                min_k=mid;
                r=mid-1;
            } else l=mid+1;
        }
        cout<<min_k<<" "<<max_k<<"\n";
    }
};

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution sol;
        sol.solve();
    }
    return 0;
}