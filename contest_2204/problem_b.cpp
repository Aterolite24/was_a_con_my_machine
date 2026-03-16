#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>a(n); for(int i=0;i<n;i++) cin>>a[i];
        vector<ll> pmx(n);
        pmx[0]=a[0];
        for(int i=1;i<n;i++) pmx[i]=max(pmx[i-1],a[i]);
        vector<vector<ll>>pos(n+1);
        for(int i=0;i<n;i++) pos[a[i]].push_back(i);
        ll cnt=0;
        ll R=n-1;
        while(R>=0){
            ll mx=pmx[R];
            ll l=0,r=(ll)pos[mx].size()-1;
            ll best=-1;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(pos[mx][mid]<=R){
                    best=mid;
                    l=mid+1;
                } else {
                    r=mid-1;
                }
            }
            R=pos[mx][best]-1;
            cnt++;
        }
        cout<<cnt<<"\n";
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