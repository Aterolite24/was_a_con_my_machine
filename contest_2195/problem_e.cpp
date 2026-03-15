#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;

class Solution{
public:
    vector<ll>dp,l,r;
    void dfs1(ll t){
        dp[t]=1;
        if(l[t]!=-1){
            dfs1(l[t]);
            dp[t]=(dp[t]+dp[l[t]]+1)%MOD;
        }
        if(r[t]!=-1){
            dfs1(r[t]);
            dp[t]=(dp[t]+dp[r[t]]+1)%MOD;
        }
    }
    void dfs2(ll t){
        if(l[t]!=-1){
            dp[l[t]]=(dp[t]+dp[l[t]])%MOD;
            dfs2(l[t]);
        }
        if(r[t]!=-1){
            dp[r[t]]=(dp[t]+dp[r[t]])%MOD;
            dfs2(r[t]);
        }
    }
    void solve(){
        ll n; cin>>n;
        dp.assign(n+1, 0);
        l.assign(n, -1);
        r.assign(n, -1);
        for(int i=0;i<n;i++)cin>>l[i]>>r[i],l[i]--,r[i]--;
        dfs1(0);
        dfs2(0);
        for(int i=0;i<n;i++)cout<<dp[i]<<" ";cout<<"\n";
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