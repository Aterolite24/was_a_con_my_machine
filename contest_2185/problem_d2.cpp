#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n,m,h; 
        cin>>n>>m>>h;
        vector<ll> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        vector<ll> original = v;
        vector<int> vis(n, -1); 
        int tt = 0; 
        for(int i=0;i<m;i++){
            int b,c; 
            cin>>b>>c;
            b--;
            if(vis[b] != tt){
                v[b] = original[b];
                vis[b] = tt;
            }
            v[b] += c;
            if(v[b] > h){
                tt++;
            }
        }
        for(int i=0; i<n; i++){
            if(vis[i] == tt) cout<<v[i]<<" ";
            else cout<<original[i]<<" ";
        }
        cout<<"\n";
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