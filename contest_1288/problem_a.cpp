#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,d; cin>>n>>d;
        ll l=0,r=n,ans=-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(mid+(d+mid)/(mid+1) <= n){
                ans=mid;
                break;
            } else l=mid+1;
        }
        if(ans==-1) cout<<"NO\n";
        else cout<<"YES\n";
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