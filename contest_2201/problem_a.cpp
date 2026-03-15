#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        vector<pair<int, int>> vals;
        for(int i=0;i<n;i++) vals.push_back({v[i], -i});
        sort(vals.rbegin(), vals.rend());
        vector<int>prv(n), nxt(n);
        for(int i=0;i<n;i++) prv[i]=i-1, nxt[i]=i+1;
        int ans=n;
        for(auto [a,i]:vals){
            i=-i;
            assert(v[i]==a);
            if(prv[i]!=-1 and v[prv[i]]==a-1){
                ans--;
                int p=prv[i], q=nxt[i];
                nxt[p]=q;
                if(n!=q) prv[q]=p;
            }
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