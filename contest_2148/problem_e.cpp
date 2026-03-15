#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        vector<ll> v(n); for(int i=0;i<n;i++) cin>>v[i];
        vector<ll> cnt(n+1, 0); for(int i=0;i<n;i++) cnt[v[i]]++;
        bool f=true;
        for(int i=1;i<=n;i++) 
            if(cnt[i]%k!=0){
                f=false;
                break;
            }
        if(!f){
            cout<<"0\n";
            return;
        }
        vector<ll>req(n+1,0); for(int i=1;i<=n;i++) req[i]=cnt[i]/k;
        vector<vector<ll>>pos(n+1); for(int i=0;i<n;i++) pos[v[i]].push_back(i);
        vector<ll>bad(n);
        for(int i=0;i<n;i++){
            ll l=0,r=pos[v[i]].size()-1,idx=r+1;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(pos[v[i]][mid]>=i){
                    idx=mid;
                    r=mid-1;
                } else l=mid+1;
            }
            ll viol_idx=idx+req[v[i]];
            if(viol_idx<pos[v[i]].size()) bad[i]=pos[v[i]][viol_idx];
            else bad[i]=n;
        }
        vector<ll>min_bad(n+1);
        min_bad[n]=n;
        for(int i=n-1;i>=0;i--) min_bad[i] = min(bad[i],min_bad[i+1]);
        ll ans=0;
        for(int l=0;l<n;l++) ans+=(min_bad[l]-l);
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