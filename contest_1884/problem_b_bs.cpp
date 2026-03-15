#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; string s; cin>>n>>s;
        vector<ll> p(n+1, 0);
        for(int i=0; i<n; i++) p[i+1] = p[i] + (s[i]=='0');
        ll tot=p[n]; ll res=0;
        for(int i=1; i<=n; i++){
            if(i>tot){
                cout<<-1<<(i==n?"":" ");
                continue;
            }
            ll l=1, r=n, pos=-1, target=tot-i+1;
            while(l<=r){
                ll m=l+(r-l)/2;
                if(p[m]>=target) pos=m, r=m-1;
                else l=m+1;
            }
            res += (ll)((n-i)-(pos-1));
            cout<<res<<(i==n?"":" ");
        }
        cout<<"\n";
    }
};

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}
