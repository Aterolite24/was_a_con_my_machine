#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,m; cin>>n>>m;
        vector<ll>a(n); for(int i=0;i<n;i++)cin>>a[i];
        vector<ll>b(m); for(int i=0;i<m;i++)cin>>b[i];
        sort(b.begin(),b.end());
        ll prev=LLONG_MIN;
        for(int i=0;i<n;i++){
            ll best=LLONG_MAX;
            if(a[i]>=prev) best=min(best,a[i]);
            ll l=0, r=m-1, ans=-1;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(b[mid]>=prev+a[i]){
                    ans=mid;
                    r=mid-1;
                } else {
                    l=mid+1;
                }
            }
            // auto it = lower_bound(b.begin(),b.end(),prev+a[i]);
            // if(it!=b.end())
            if(ans!=-1) best=min(best,b[ans]-a[i]);
            if(best==LLONG_MAX){
                cout<<"NO\n";
                return;
            }
            prev=best;
        }
        cout<<"YES\n";
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