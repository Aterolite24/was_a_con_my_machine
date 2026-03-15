#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    ll n;
    vector<ll>h;
    ll tot(ll k){
        ll sum=0;
        for(int i=0;i<n;i++) sum+=(k<=h[i]?0LL:k-h[i]);
        return sum;
    }
    void solve(){
        ll x; cin>>n>>x;
        h.assign(n,0);
        for(int i=0;i<n;i++) cin>>h[i];
        sort(h.begin(), h.end());
        ll l=h[0],r=h[n-1]+x,ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(tot(mid)<=x){
                ans=mid;
                l=mid+1;
            } else r=mid-1;
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