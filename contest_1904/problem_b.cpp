#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>a(n+1), id(n+1);
        for(ll i=1;i<=n;i++) cin>>a[i], id[i]=i;
        sort(id.begin()+1,id.begin()+n+1,[&](ll x,ll y){
            return a[x]<a[y];
        });
        
        vector<ll>b(n+1), p(n+1);
        for(ll i=1;i<=n;i++)b[i]=a[id[i]], p[i]=p[i-1]+b[i];
        vector<ll>f(n+1); for(ll i=1;i<n;i++) f[i]=f[i-1]+(p[i]<b[i+1]);
        
        vector<ll>ans(n+1);
        for(ll i=1;i<=n;i++){
            ll l=i,r=n,res=i;
            while(l<=r){
                ll mid=(l+r)/2;
                if(f[mid-1]-f[i-1]==0){
                    res=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            ans[id[i]]=res-1;
        }
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