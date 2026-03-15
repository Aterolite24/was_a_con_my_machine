#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void solve() {
        ll n; cin>>n;
        vector<bitset<5005>>out(n);
        vector<ll>sz(n);
        for(int i=0;i<n;i++){
            string s; cin>>s;
            for(int j=0;j<n;j++) if(s[j]=='1') out[i].set(j);
            sz[i] = out[i].count();
        }
        for(int i=0;i<n;i++) {
            if(!out[i][i]) {
                cout<<"No\n";
                return;
            }
            for(int j=0;j<n;j++)
                if(i!=j and out[i][j] and out[j][i]) {
                    cout<<"No\n";
                    return;
                }
        }
        vector<pair<ll,ll>>edges;
        for(int u=0;u<n;u++) {
            vector<int>Reach;
            for(int v=0;v<n;v++) if(u!=v and out[u][v]) Reach.push_back(v);
            sort(Reach.begin(), Reach.end(), [&](int a, int b){
                return sz[a]>sz[b];
            });
            bitset<5005>covered;
            for(int v:Reach) if(!covered[v]) edges.push_back({u+1,v+1}), covered |= out[v];
            if((ll)covered.count() != sz[u]-1){
                cout<<"No\n";
                return;
            }
        }
        if((ll)edges.size() != n-1){
            cout<<"No\n";
            return;
        }
        vector<vector<ll>>uadj(n+1);
        for(auto &e:edges) uadj[e.first].push_back(e.second), uadj[e.second].push_back(e.first);
        vector<ll>vis(n+1,0);
        ll cnt=0;
        queue<ll>q; q.push(1); vis[1]=1;
        while(!q.empty()) {
            ll u = q.front(); q.pop(); cnt++;
            for(ll v:uadj[u]) if(!vis[v]) vis[v]=1, q.push(v);
        }
        if(cnt!=n){
            cout<<"No\n";
            return;
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