#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        vector<ll>x(k); for(int i=0;i<k;i++) cin>>x[i];
        sort(x.rbegin(),x.rend());
        vector<ll>mn(k); mn[0]=n-x[0];
        for(int i=1;i<k;i++) mn[i]=mn[i-1]+(n-x[i]);
        // mice: 0 3 7 13
        // catt: -1 2 6 12
        // xcat: 0 1 3 6
        // (n**2 + n) / 2 >= d cat ahead
        ll l=0, r=k, ans=-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(mid==0){
                ans=0;
                l=1;
                continue;
            }
            if(mn[mid-1]<n){
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
    int t;
    cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}