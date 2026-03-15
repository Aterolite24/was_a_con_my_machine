#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        // x prob => 5*1 + 5*2 + ... + 5*x
        //          = 5*(x+1)*x/2
        // 4 hrs = 4*60 = 240
        // 240 - k - sx >= 0
        ll l=0,r=n,ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(240 - k - (5*(mid+1)*mid)/2 >= 0){
                ans=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        cout<<ans;
    }
};

int main(){
    int t=1;
    // cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}