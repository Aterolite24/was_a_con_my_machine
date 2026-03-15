#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,q; cin>>n>>q;
        vector<ll>v(n); for(int i=0;i<n;i++) cin>>v[i];
        sort(v.rbegin(),v.rend());
        vector<ll>pf(n); for(int i=0;i<n;i++) pf[i]=v[i]+(i?pf[i-1]:0LL);
        for(int i=0;i<q;i++){
            ll qi; cin>>qi;
            ll l=0,r=n-1,ans=-1;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(pf[mid]>=qi){
                    ans=mid;
                    r=mid-1;
                } else l=mid+1;
            }
            cout<<(ans==-1?-1:ans+1)<<"\n";
        }
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