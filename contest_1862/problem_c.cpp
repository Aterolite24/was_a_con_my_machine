#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        // sort(a.begin(), a.end());
        // if(n==1){
        //     if(a[0]==1) cout<<"YES\n";
        //     else cout<<"NO\n";
        //     return;
        // }
        // else{
        //     ll sum=a[0]+a[n-1];
        //     ll l=1, r=n-2;
        //     while(l<r){
        //         if(a[l]+a[r]!=sum){
        //             cout<<"NO\n";
        //             return;
        //         }
        //         l++,r--;
        //     }
        //     if(n%2 and l==r){
        //         if(a[l]+a[r]!=sum){
        //             cout<<l<< " " << a[l] << " " << a[r] << " " << sum << " NO here\n";
        //             return;
        //         }
        //     }
        //     cout<<"YES\n";
        // }
        ll m=a[0];
        for(int i=0;i<m;i++){
            ll target=i;
            ll l=0,r=n-1,ans=0;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(a[mid]>target){
                    ans=mid;
                    l=mid+1;
                } else r=mid-1;
            }
            if(ans+1!=a[i]){
                cout<<"NO\n";
                return;
            }
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