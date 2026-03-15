#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll x; cin>>x;
        ll ans=-1;
        for(ll i=1; i*i*i<x; i++){
            ll l=1, r=10000, target=x-i*i*i;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(mid*mid*mid==target){
                    ans=mid;
                    break;
                }
                else if(mid*mid*mid<target) l=mid+1;
                else r=mid-1;
            }
            if(ans!=-1) break;
        }
        cout<<(ans==-1?"NO\n":"YES\n");
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