#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void dfs(int u, vector<ll>& vis, vector<vector<ll>>& uadj, ll& cnt) {
        vis[u]=1;
        cnt++;
        for(int v:uadj[u]) if(!vis[v]) dfs(v, vis, uadj, cnt);
    }

    void solve() {
        ll n; cin>>n;
        vector<bitset<500>> out(n), in(n);
        for(int i=0;i<n;i++){
            string s; cin>>s;
            for(int j=0;j<n;j++)
                if(s[j]=='1'){
                    out[i].set(j);
                    in[j].set(i);
                }
        }
        for(int i=0;i<n;i++) if(!out[i][i]) {
            cout<<"No\n";
            return;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j and out[i][j] and out[j][i]) {
                    cout<<"No\n";
                    return;
                }
        vector<pair<ll,ll>>edges;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j or !out[i][j]) continue;
                if((out[i]&in[j]).count()==2) edges.push_back({i+1,j+1});
            }
        }
        if(edges.size()!=n-1) {
            cout<<"No\n";
            return;
        }
        vector<vector<ll>>adj(n+1), uadj(n+1);
        for(auto &e:edges){
            adj[e.first].push_back(e.second);
            uadj[e.first].push_back(e.second);
            uadj[e.second].push_back(e.first);
        }
        vector<ll>vis(n+1,0);
        ll cnt=0;
        dfs(1, vis, uadj, cnt);
        if(cnt!=n) {
            cout<<"No\n";
            return;
        }
        for(int i=1;i<=n;i++) {
            bitset<500>cur;
            vector<ll>q = {i};
            cur.set(i-1);
            ll head=0;
            while(head<q.size()){
                ll u = q[head++];
                for(int v:adj[u]) if(!cur[v-1]) cur.set(v-1), q.push_back(v);
            }
            if(cur!=out[i-1]){
                cout<<"No\n";
                return;
            }
        }
        cout<<"Yes\n";
        for(auto &e:edges) cout<<e.first<<" "<<e.second<<"\n";
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