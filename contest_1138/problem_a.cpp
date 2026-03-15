#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        vector<ll>blocks;
        ll cnt=1;
        for(int i=1;i<n;i++){
            if(v[i-1]==v[i]) cnt++;
            else {
                blocks.push_back(cnt); cnt=1;
            }
        }
        blocks.push_back(cnt);
        ll ans=0;
        // cout<<"BLOCKS:\n";
        // for(auto b:blocks)cout<<b<<" ";cout<<"\n";
        // for(int i=0;i+1<blocks.size();i++) ans=max(ans,2*(min(blocks[i+1],blocks[i])));
        // cout<<ans<<"\n";

        ll l=0, r=n/2+1;
        while(l+1<r){
            ll mid=l+(r-l)/2;
            bool possible=false;
            for(int i=1;i<blocks.size();i++){
                if(blocks[i-1]>=mid and blocks[i]>=mid){
                    possible=true;
                    break;
                }
            }
            if(possible)l=mid;
            else r=mid;
        }
        cout<<2*l<<"\n";
    }
};

int main(){
    int t;
    // cin >> t;
    t=1;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}