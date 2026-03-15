#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,s; cin>>n>>s;
        ll l=0, r=2*s, ans=r;
        while(l<=r){
            ll mid=l+(r-l)/2;
            ll k=n - (n+1)/2 + 1;
            if(mid*k<=s){
                ans=mid;
                l=mid+1;
            } else {
                r=mid-1;
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