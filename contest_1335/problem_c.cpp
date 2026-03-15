#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>v(n); for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        vector<pair<ll,ll>>mp;
        for(int i=0;i<n;){
            ll cnt=0,curr=v[i],j=i;
            while(j<n and v[j]==curr)cnt++,j++;
            mp.push_back({cnt,curr});
            i=j;
        }
        // for(auto [c,num]:mp) cout<<c<<" "<<num<<"\n";
        sort(mp.rbegin(),mp.rend());
        ll max_cnt=mp[0].first, remain=mp.size()-1;
        ll ans=max(min(max_cnt,remain), min(max_cnt-1,remain+1));
        cout<<ans<<"\n";
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