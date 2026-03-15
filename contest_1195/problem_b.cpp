#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        ll l=0, r=n;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(mid*(mid+1)/2 - (n-mid) == k){
                cout<<n-mid<<"\n";
                return;
            } else if(mid*(mid+1)/2 - (n-mid) < k) l=mid+1;
            else r=mid-1;
        }
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