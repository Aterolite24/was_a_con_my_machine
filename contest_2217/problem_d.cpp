#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n, k; cin>>n>>k;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<ll> p(k);
        for(int i=0;i<k;i++) cin>>p[i];
        ll x = a[p[0]-1]; 
        vector<ll>c(n+2, 0);
        for(int i=1;i<=n;i++) c[i]=(a[i-1]!=x);
        vector<ll>d(n+2, 0);
        for(int i=1;i<=n+1;i++) d[i]=c[i]^c[i-1];
        vector<ll>P; P.push_back(0);
        for(int i=0;i<k;i++) P.push_back(p[i]);
        P.push_back(n+1);
        ll s=0,max_s=0;
        for(int j=0;j<=k;j++){
            ll start=P[j]+1, end=P[j+1], current_s=0;
            for(ll i=start;i<=end;i++) current_s+=d[i];
            max_s=max(max_s,current_s);
            s+=current_s;
        }
        cout<<max(s/2,max_s)<<"\n";
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