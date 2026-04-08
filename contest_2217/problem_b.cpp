#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        vector<ll>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        ll p1; cin>>p1;
        ll x=a[p1-1];
        vector<ll>c(n+2,0);
        for(int i=1;i<=n;i++) c[i]=(a[i-1]!=x);
        vector<ll>d(n+2,0);
        for(int i=1;i<=n+1;i++) d[i]=c[i]^c[i-1];
        ll s0=0,s1=0;
        for(int i=1;i<=n+1;i++){
            if(i<=p1) s0+=d[i];
            else s1+=d[i];
        }
        ll l=0,r=n+1,ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            bool can=false;
            if(mid>=max(s0,s1)) can=true;
            if(can){
                ans=mid;
                r=mid-1;
            } else l=mid+1;
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