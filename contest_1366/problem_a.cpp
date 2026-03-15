#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll a,b; cin>>a>>b;
        ll l=0, r=2e9; // Safe upper bound
        ll ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(mid <= a and mid <= b and 3*mid <= a+b){
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
    int t=1;
    cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}