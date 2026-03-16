#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,m; cin>>n>>m;
        vector<vector<ll>>adj(n+1);
        for(int i=0;i<m;i++){
            ll u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<ll>color(n+1,-1);
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(color[i]!=-1) continue;
            if(adj[i].empty()){
                ans++;
                color[i]=0;
                continue;
            }
            queue<ll> q;
            color[i]=0;
            q.push(i);
            ll cnt[2]={0,0};
            bool bipartite=true;
            while(!q.empty()){
                ll u=q.front(); q.pop();
                cnt[color[u]]++;
                for(auto v:adj[u]){
                    if(color[v]==-1){
                        color[v]=1-color[u];
                        q.push(v);
                    } else if(color[v]==color[u]) bipartite=false;
                }
            }
            if(bipartite) ans+=max(cnt[0],cnt[1]);
        }
        cout<<ans<<"\n";
    }
};

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}