#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll l,r; cin>>l>>r;
        // vector<ll>seq;
        // seq.push_back(l);
        // seq.push_back(l+1);
        // ll idx=1;
        // ll nxt = 2*seq[idx]-seq[idx-1]+1;
        // while(nxt<=r){
        //     seq.push_back(nxt);
        //     idx++;
        //     nxt=2*seq[idx]-seq[idx-1]+1;
        // }
        // for(auto i:seq)cout<<i<<" ";cout<<"\n";
        ll ans=0;
        ll s=0, e=r-l+1;
        while(s<e){
            ll mid=s+(e-s)/2;
            ll curr=mid*(mid+1)/2;
            if(curr>r-l){
                e=mid;
            } else {
                s=mid+1;
                ans=s;
            }
        }
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