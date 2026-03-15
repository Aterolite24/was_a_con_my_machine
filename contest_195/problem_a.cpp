#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll a,b,c; cin>>a>>b>>c;
        // size(data to watch) per sec > size(data downloaded) per sec
        ll need=a*c;
        // ll can_be_done = ((need+b-1)/b) * b;
        // ll max_time=can_be_done/b;
        // ll wait_time=max_time-c;
        // cout<<wait_time<<"\n";

        ll l=0, r=need,ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if((mid+c)*b>=need){
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
    int t=1;
    // cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}