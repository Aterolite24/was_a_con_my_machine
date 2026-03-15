#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>v(n); for(int i=0;i<n;i++) cin>>v[i];
        ll q; cin>>q;
        sort(v.begin(),v.end());
        while(q--){
            ll qi;
            cin>>qi;
            ll l=0,r=n-1,ans=-1;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(v[mid]<=qi){
                    ans=mid;
                    l=mid+1;
                } else r=mid-1;
            }
            if(ans!=-1){
                cout<<ans+1<<"\n";
            } else cout<<"0\n";
        }
    }
};

int main(){
    int t=1;
    // cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}