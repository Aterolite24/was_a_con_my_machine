#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        ll need=((n+k-1)/k)*k;
        ll l=1,r=k,ans=r;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(mid*n>=need){
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