#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    __int128_t get_res(ll k, vector<ll>& a) {
        __int128_t sum = 0;
        for (int i = 0; i < a.size(); i++) {
            __int128_t side = 2 * (__int128_t)k + a[i];
            sum += side * side;
            if (sum > (__int128_t)2e18) return sum;
        }
        return sum;
    }
    void solve(){
        ll n,c; cin>>n>>c;
        vector<ll>a(n); for(int i=0;i<n;i++) cin>>a[i];
        ll l=1,r=1e9,ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if (get_res(mid, a) <= (__int128_t)c) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        cout<<ans<<"\n";
    }
};

int main(){
    int t=1;
    cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}