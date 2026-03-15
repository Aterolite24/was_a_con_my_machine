#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,q; cin>>n>>q;
        string s; cin>>s;
        for(int i=0;i<q;i++){
            ll qi; cin>>qi;
            ll l=0,r=qi,ans=qi;
            while(l<=r){
                ll mid=l+(r-l)/2;
                ll x=qi;
                for(ll i=0;i<mid and x>0;i++){
                    if(s[i%n]=='A') x--;
                    else x/=2;
                }
                if(x==0){
                    ans=mid;
                    r=mid-1;
                } else {
                    l=mid+1;
                }
            }
            cout<<ans<<"\n";
        }
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