#include<bits/stdc++.h>
using namespace std;
#define ll long long

static const int INF = 1e9;
const ll MAXI = 3e5 + 7;

class Solution{
public:
    int n;
    vector<ll> a;
    vector<vector<ll>>fact;
    void precompute(){
        fact.resize(MAXI+1);
        for(ll i=1; i<=MAXI; i++){
            for(ll j=i; j<=MAXI; j+=i){
                fact[j].push_back(i);
            }
        }
    }
    void solve(){
        cin>>n;
        a.resize(n);
        vector<ll>exists(n+1,0);
        for(ll i=0; i<n; i++){
            cin >> a[i];
            exists[a[i]] = 1;
        }
        vector<ll> ans(n+1, INT_MAX/10);
        for(ll i=1; i<=n; i++){
            if(exists[i]==1){ans[i]=1; continue;}
            for(ll d : fact[i]){
                if(d>1 and exists[d]==1){
                    ans[i] = min(ans[i], 1+ans[i/d]);
                }
            }
        }
        for(ll i=1; i<=n; i++){
            if(ans[i]==INT_MAX/10) cout<<"-1 ";
            else cout<<ans[i]<<" ";
        }
        cout << "\n";
    }
};

int main(){
    int t;
    cin >> t;
    Solution sol;
    sol.precompute();
    while(t--){
        
        sol.solve();
    }
    return 0;
}