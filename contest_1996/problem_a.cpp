#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll t; cin>>t;
        ll l=1, r=t/4+1;
        ll ans=0;
        while(l<r){
            ll mid=l+(r-l)/2;
            if(2*mid<=t and t<=4*mid){
                r=mid;
            } else {
                l=mid+1;
            }
        }
        cout<<l<<"\n";
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