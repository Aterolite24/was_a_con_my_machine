#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>a(n+1),id(n+1);
        for(ll i=1;i<=n;i++) cin>>a[i], id[i]=i;

        sort(id.begin()+1,id.begin()+n+1,[&](ll x,ll y){
            return a[x]<a[y];});

        vector<ll>b(n+1), pref(n+1);
        for(ll i=1;i<=n;i++) b[i]=a[id[i]], pref[i]=pref[i-1]+b[i];
        
        vector<ll>cnt(n+1);
        cnt[n]=n;
        for(ll i=n-1;i>=1;i--){
            if(pref[i]>=b[i+1]) cnt[i]=cnt[i+1];
            else cnt[i]=i;
        }
        
        vector<ll>ans(n+1);
        for(ll i=1;i<=n;i++) ans[id[i]]=cnt[i]-1;
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
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