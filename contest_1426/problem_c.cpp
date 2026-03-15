#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        ll l=0,r=2*n+1;
        ll ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if((mid*mid)/4>=n){
                ans=mid;
                r=mid-1;
            } else l=mid+1;
        }
        cout<<ans-2<<"\n";
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