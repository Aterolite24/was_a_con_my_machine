#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,m; cin>>n>>m;
        vector<ll>v(n); for(int i=0; i<n; i++) cin>>v[i];
        ll m0; cin>>m0;
        if(n<2){
            cout<<"YES\n";
            return;
        }
        ll limit=LLONG_MAX;
        for(int i=n-1;i>=0;i--){
            ll x=v[i], y=m0-v[i];
            ll maxi=max(x,y);
            ll mini=min(x,y);
            if(maxi<=limit) v[i]=maxi;
            else if(mini<=limit) v[i]=mini;
            else {
                cout<<"NO\n";
                return;
            }
            limit=v[i];
        }
        cout<<"YES\n";
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