#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,m; cin>>n>>m;
        vector<ll>axis(n+1); axis[0]=1;
        for(int i=1;i<=n;i++) cin>>axis[i], axis[i]+=axis[i-1];
        axis.push_back(LLONG_MAX);
        // cout<<"AXIS\n";
        // for(auto a:axis)cout<<a<<" ";cout<<"\n";
        for(int i=0;i<m;i++){
            ll qi; cin>>qi;
            ll l=0, r=n, ans=0;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(axis[mid]<=qi and qi<axis[mid+1]){
                    ans=mid;
                    break;
                } else if(qi>=axis[mid+1]){
                    l=mid+1;
                } else if(axis[mid]>qi){
                    r=mid-1;
                }
            }
            cout<<ans+1<<" "<<qi-axis[ans]+1<<"\n";
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