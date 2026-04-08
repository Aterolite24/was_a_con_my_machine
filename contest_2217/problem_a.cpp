#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        vector<ll>a(n);
        ll s=0;
        for(int i=0;i<n;i++) cin>>a[i], s+=a[i];
        ll l=0,r=1,ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            bool can=false;
            if(mid==0) can=true;
            else if((s%2!=0)or((n*k)%2==0)) can=true;
            if(can){
                ans=mid;
                l=mid+1;
            } else r=mid-1;
        }
        cout<<(ans==1?"YES":"NO")<<"\n";
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