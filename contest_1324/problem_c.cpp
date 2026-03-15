#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        string s; cin>>s;
        ll n=s.size();
        vector<ll> v; v.push_back(0);
        for(int i=0;i<n;i++) if(s[i]=='R') v.push_back(i+1);
        v.push_back(n+1);
        ll l=1,r=n+1,ans=n+1;
        while(l<=r){
            ll mid=l+(r-l)/2,ok=1;
            for(int i=1;i<v.size();i++) if(v[i]-v[i-1]>mid) ok=0;
            if(ok){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<"\n";
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