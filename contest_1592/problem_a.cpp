#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,h; cin>>n>>h;
        vector<ll>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        sort(v.rbegin(),v.rend());
        ll a=v[0],b=v[1];
        ll l=1, r=2*h, ans=r;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(h - a*((mid+1)/2) - b*(mid/2)<=0){
                ans=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        cout<<ans<<"\n";
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