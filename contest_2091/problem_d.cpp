#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n, m, k;
        cin>>n>>m>>k;
        ll l=1, r=m, ans=m;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(n*(m-m/(mid+1))>=k){
                ans=mid;
                r=mid-1;
            } else l=mid+1;
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