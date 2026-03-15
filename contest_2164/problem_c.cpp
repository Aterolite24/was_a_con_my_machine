#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n,m;cin>>n>>m;
        vector<int>a(n),b(m),c(m);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        for(int i=0;i<m;i++)cin>>c[i];
        int ans=0;
        vector<int> ord1, ord2;
        for(int i=0;i<m;i++) if(c[i]==0) ord2.push_back(i); else ord1.push_back(i);
        multiset<int> mst(a.begin(), a.end());
        sort(ord1.begin(),ord1.end(), [&](const int &i, const int &j){
            return b[i]<b[j];
        });
        for(auto i:ord1){
            auto it=mst.lower_bound(b[i]);
            if(it==mst.end())break;
            int x=*it;
            mst.erase(it);
            ans++;
            mst.insert(max(x,c[i]));
        }
        for(auto i:ord2){
            auto it=mst.lower_bound(b[i]);
            if(it==mst.end())continue;
            mst.erase(it);
            ans++;
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