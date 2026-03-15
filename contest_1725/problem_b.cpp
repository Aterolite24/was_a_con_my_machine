#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,d; cin>>n>>d;
        vector<ll>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.rbegin(),a.rend());
        // ll sz=n,i=0, cnt=0;
        // while(sz>0 and i<n){
        //     ll num=(a[i]+d-1)/a[i];
        //     if(sz>=num){
        //         sz-=num;
        //         cnt++;
        //     } else break;
        //     i++;
        // }
        // cout<<cnt<<"\n";

        vector<ll>sums(n);
        sums[0]=d/a[0]+1;
        for(int i=1;i<n;i++){
            ll need=d/a[i] +1;
            sums[i]=sums[i-1]+need;
        }
        ll l=0,r=n-1,ans=-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(sums[mid]<=n){
                ans=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        cout<<ans+1<<"\n";
    }
};

int main(){
    int t=1;
    // cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}