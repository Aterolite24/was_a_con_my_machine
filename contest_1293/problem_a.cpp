#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void solve() {
        ll n,s,k; cin>>n>>s>>k;
        vector<ll>a(k);
        for (int i=0;i<k;i++) cin>>a[i];
        sort(a.begin(), a.end());
        ll l=0,r=k+1,ans=k+1;
        while(l<=r) {
            ll mid=l+(r-l)/2;
            ll L=max(1LL, s-mid), R=min(n, s+mid);
            ll cnt=upper_bound(a.begin(), a.end(), R) - lower_bound(a.begin(), a.end(), L);
            if (cnt<R-L+1){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<"\n";
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Solution sol;
        sol.solve();
    }
    return 0;
}