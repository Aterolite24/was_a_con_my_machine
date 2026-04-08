#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 676767677;

class Solution{
public:
    void solve(){
        ll n,m; cin>>n>>m;
        vector<ll>b(n+1);
        vector<ll>cnt(m+1,0);
        for(int i=1;i<=n;i++){
            cin>>b[i];
            cnt[b[i]]++;
        }
        vector<ll>n_t(m+1,0);
        ll cur=0;
        for(int t=0;t<=m;t++){
            n_t[t]=cur;
            cur+=cnt[t];
        }
        ll ans=1;
        for(int i=1;i<=n;i++){
            if(b[i]==0) continue;
            ll m_i=2e9;
            if(i>1) m_i=min(m_i,b[i-1]);
            if(i<n) m_i=min(m_i,b[i+1]);
            if(b[i]<=m_i){
                ans=0;
                break;
            }
            if(b[i]>m_i+1){
                ans=(ans*(n_t[b[i]]-n_t[b[i]-1]))%MOD;
            }else{
                ans=(ans*n_t[b[i]])%MOD;
            }
        }
        cout<<ans<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}