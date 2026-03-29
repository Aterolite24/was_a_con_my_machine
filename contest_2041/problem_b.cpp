#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll w,b; cin>>w>>b;
        ll t=w+b;
        ll l=0,r=sqrt(2*t),ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(mid*(mid+1)/2<=t){
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