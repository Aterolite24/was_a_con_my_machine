#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        vector<ll>v(n); for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        ll l=0,r=1e9,ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            ll sum=0;
            for(int i=0;i<n;i++){
                sum+=min(mid,v[i]);
            }
            if(sum>=k){
                ans=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        ll res=0, now=0;
        for(int i=0;i<n;i++){
            if(v[i]<ans) res+=v[i], now+=v[i], res++;
            else{
                res+=min(ans,k-now);
                now+=ans;
                if(now>=k) break;
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