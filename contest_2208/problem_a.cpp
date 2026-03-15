#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll> v(n*n);
        for(int i=0;i<n*n;i++) cin>>v[i];
        if(n==1){
            cout<<"NO\n";
            return;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n*n;){
            ll l=i,r=n*n,ans=n*n, target=v[i];
            while(l<r){
                ll mid=l+(r-l)/2;
                if(v[mid]>target) ans=mid, r=mid;
                else l=mid+1;
            }
            ll cnt=ans-i;
            if(cnt>n*n-n){
                cout<<"NO\n";
                return;
            }
            i+=cnt;
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
