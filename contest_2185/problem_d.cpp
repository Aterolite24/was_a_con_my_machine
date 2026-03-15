#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n,m,h; cin>>n>>m>>h;
        vector<ll> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        vector<ll> original = v;
        vector<pair<int,int>> q(m);
        for(int i=0;i<m;i++) cin>>q[i].first>>q[i].second;
        vector<vector<pair<int, int>>> sr(n);
        for(int i=0;i<m;i++){
            int x=q[i].first, c=q[i].second;
            sr[x-1].push_back({c,i});
        }
        cout<<"\n\nsr:\n";
        for(auto a:sr){
            for(auto p:a){
                cout<<"("<<p.first<<","<<p.second<<"), "; 
            }
            cout<<endl;
        }
        int maxi=-1;
        int sr_sz=sr.size();
        for(int i=0;i<sr_sz;i++){
            int sz=sr[i].size();
            ll sum=0;
            for(int j=sz-1;j>=0;j--){
                sum+=sr[i][j].first;
                if(sum+v[i]>h){
                    cout<<"thrs: " << sum+v[i]<<"\n";
                    maxi=max(maxi,sr[i][j].second);
                    break;
                }
            }
        }
        cout<<maxi+1<<"\n";
        int start=maxi+1;
        if(start < 0) start = 0;
        if(start > m) start = m-1;
        for(int i=start;i<m;i++){
            v[q[i].first - 1] += q[i].second;
        }
        for(int i=0; i<n; i++) cout<<v[i]<<" ";cout<<"\n";
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