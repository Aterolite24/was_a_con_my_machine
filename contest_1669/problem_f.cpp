#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>v(n); for(int i=0;i<n;i++) cin>>v[i];
        vector<ll>pf(n); for(int i=0;i<n;i++) pf[i]=v[i]+(i?pf[i-1]:0LL);
        vector<ll>sf(n); for(int i=0;i<n;i++) sf[i]=v[n-i-1]+(i?sf[i-1]:0LL);
        ll l=0,r=0,ansl=0,ansr=0;
        while(l<n and r<n and l<n-r-1){
            if(pf[l]==sf[r]){
                ansl=l+1;
                ansr=r+1;
                l++,r++;
            } else if(pf[l]<sf[r]){
                l++;
            } else {
                r++;
            }
        }
        cout<<ansl+ansr<<"\n";
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