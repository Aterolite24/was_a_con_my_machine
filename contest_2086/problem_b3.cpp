#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n,k,x; cin>>n>>k>>x;
    vector<ll>a(n); for(ll &i:a) cin>>i;
    vector<ll>pre(n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i-1];
    ll s = pre[n];
    ll ans=0;
    for(int i=0;i<n;i++){
        ll suffix = s - pre[i];
        ll l=0,r=k-1;
        ll need=k;
        while(l<=r){
            ll mid=(l+r)/2;
            if(suffix + mid*s >= x){
                need=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        if(need<k) ans += (k - need);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--) solve();
}