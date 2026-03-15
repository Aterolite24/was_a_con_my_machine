#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    vector<ll>a;
    ll check(ll n, ll p){
        ll s=0, mn=LLONG_MAX, mx=LLONG_MIN;
        for(int i=0;i<p;i++) s+=a[i],mn=min(mn,a[i]);
        for(int i=p;i<n;i++) mx=max(mx,a[i]);
        if(mn<mx) s=s-mn+mx;
        return s;
    }
    void solve(){
        // without swap
        //      s = sum(ai)
        //      full = n+k
        // fight possibility:
        //      1. full cycles
        //              ans = (h/s) * (n+k)
        //              h = h%s
        //              if(h==0) cout<<ans-k; bcz last reload not req
        //      2. one partial cycle
        //              the swap only affects last partial magazine
        //              we create a fn check(p) gives max possible damage using p bullets
        //              we swap min of p bullets with max outside prefix
        //              for(int i=0;i<n;i++) s+=a[i], mn=min(mn,a[i])
        //              for(int i=0;i<n;i++) mx=max(mx,a[i])
        //              if(mx>mn) s = s-mn+mx;
        //              we use binary search to kill enemy in smallest time p

        ll n,h,k; cin>>n>>h>>k;
        ll s=0, ans;
        a.resize(n);
        for(int i=0;i<n;i++)cin>>a[i], s+=a[i];
        ans=(h/s)*(n+k);
        h%=s;
        if(h==0){
            cout<<ans-k<<"\n";
            return;
        }
        ll l=0,r=n;
        while(r-l>1){
            ll mid=l+(r-l)/2;
            if(check(n,mid)>=h)r=mid;
            else l=mid;
        }
        ans+=r;
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