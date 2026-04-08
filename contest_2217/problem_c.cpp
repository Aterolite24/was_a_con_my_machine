#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,m,a,b; cin>>n>>m>>a>>b;
        ll l=0,r=1,ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            bool can=false;
            if(mid==0) can=true;
            else if(__gcd(n,a)==1 and __gcd(m,b)==1 and __gcd(n,m)<=2) can=true;
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