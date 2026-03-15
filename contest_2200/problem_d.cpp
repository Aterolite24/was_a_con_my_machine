#include<bits/stdc++.h>
using namespace std;
#define ll long long

class solution{
public:
    void solve(){
        ll n,x,y; cin>>n>>x>>y;
        vector<ll>p(n);
        for(ll i=0;i<n;i++) cin >> p[i];
        vector<ll>s; for(ll i=0;i<x;i++) s.push_back(p[i]);
        for(ll i=y;i<n;i++) s.push_back(p[i]);
        vector<ll>b; for(ll i = x; i < y; i++) b.push_back(p[i]);
        ll min_val = b[0], min_idx = 0;
        for(ll i=1;i<(ll)b.size();i++){
            if(b[i]<min_val){
                min_val=b[i];
                min_idx=i;
            }
        }
        vector<ll>b_min; for(ll i=min_idx;i<(ll)b.size();i++) b_min.push_back(b[i]);
        for(ll i=0;i<min_idx;i++) b_min.push_back(b[i]);
        ll k=0;
        while(k < (ll)s.size() && s[k] < b_min[0]) k++;
        vector<ll>ans; for(ll i=0;i<k;i++) ans.push_back(s[i]);
        for(ll i=0;i<(ll)b_min.size();i++) ans.push_back(b_min[i]);
        for(ll i=k;i<(ll)s.size();i++) ans.push_back(s[i]);
        for(ll i=0;i<n;i++) cout<<ans[i]<<(i==n-1?"":" ");
        cout << "\n";
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if(cin >> t){
        while(t--){
            solution sol;
            sol.solve();
        }
    }
    return 0;
}