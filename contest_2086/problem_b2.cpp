#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    ll get_pref(ll idx, vector<ll>&pre, ll sumA, ll n){
        ll block=idx/n;
        ll pos=idx%n;
        return block*sumA+pre[pos];
    }

    void solve(){
        ll n,k,x; cin>>n>>k>>x;
        vector<ll>a(n); for(ll &i:a) cin>>i;
        vector<ll>pre(n+1); for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i-1];
        ll sumA=pre[n], total=n*k, ans=0;
        for(ll i=1;i<=total;i++){
            ll pref_before = get_pref(i-1,pre,sumA,n);
            ll target = pref_before + x;
            ll l=i, r=total, pos=-1;
            while(l<=r){
                ll mid=(l+r)/2;
                if(get_pref(mid,pre,sumA,n) >= target){
                    pos=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(pos!=-1) ans++;
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