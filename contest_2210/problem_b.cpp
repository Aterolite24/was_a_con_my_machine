#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>p(n+1);
        ll cnt_lte=0;
        for(int i=1;i<=n;i++){
            cin>>p[i];
            if(p[i]<=i) cnt_lte++;
        }
        ll l=0,r=n,ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(mid<=cnt_lte){
                ans=mid;
                l=mid+1;
            } else r=mid-1;
        }
        cout<<ans<<endl;
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