#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,m; cin>>n>>m;
        vector<ll>a(n); for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        vector<ll>pf(n); pf[0]=a[0];
        for(int i=1;i<n;i++) pf[i]=pf[i-1]+a[i];
        ll ans=0;
        for(int i=0;i<n;i++){
            ll l=i, r=n-1, j=i;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(a[mid]-a[i]<=1){
                    j=mid;
                    l=mid+1;
                } else r=mid-1;
            }
            ll L=i, R=j, best=i-1;
            while(L<=R){
                ll mid=L+(R-L)/2;
                ll sum=pf[mid]-(i?pf[i-1]:0LL);
                if(sum<=m){
                    best=mid;
                    L=mid+1;
                } else R=mid-1;
            }
            if(best>=i){
                ll sum=pf[best]-(i?pf[i-1]:0LL);
                ans=max(ans,sum);
            }
        }
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