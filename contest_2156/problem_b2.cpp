#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,q; cin>>n>>q;
        string s; cin>>s;
        ll cnta=0,cntb=0;
        for(auto ch:s) if(ch=='A')cnta++; else cntb++;
        while (q--){
            ll qi; cin>>qi;
            if(cntb==0){
                cout<<qi<<"\n";
                break;
            } else {
                ll ans=0,i=0;
                while(i>=0){
                    if(qi==0) break;
                    ans++;
                    if(s[i]=='A')qi--;
                    else qi/=2;
                    i=(i+1)%n;
                }
                cout<<ans<<"\n";
            }
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