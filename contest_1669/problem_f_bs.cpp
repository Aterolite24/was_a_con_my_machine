#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>v(n); for(int i=0;i<n;i++) cin>>v[i];
        vector<ll>pf(n); for(int i=0;i<n;i++) pf[i]=v[i]+(i?pf[i-1]:0LL);
        vector<ll>sf(n); for(int i=0;i<n;i++) sf[i]=v[n-i-1]+(i?sf[i-1]:0LL);
        ll res=0;
        for(int i=0;i<n;i++){
            ll target=pf[i];
            ll l=0,r=n-i-2,ans=-1;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(sf[mid]==target){
                    ans=mid;
                    break;
                } else if(sf[mid]<target) l=mid+1;
                else r=mid-1;
            }
            if(ans!=-1){
                res=max(res, (ll)i+ans+2);
            }
        }
        cout<<res<<"\n";
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