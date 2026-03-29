#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll k; cin>>k;
        ll l=1, r=2e18, ans=r;
        while(l<=r){
            ll mid=l+(r-l)/2;
            ll sq=sqrtl(mid);
            while(sq*sq>mid) sq--;
            while((sq+1)*(sq+1)<=mid) sq++;
            if(mid-sq>=k){
                ans=mid;
                r=mid-1;
            } else l=mid+1;
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