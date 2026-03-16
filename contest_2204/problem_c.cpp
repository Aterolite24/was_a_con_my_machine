#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    ll gcd(ll x,ll y){
        while(y){
            ll t=y;
            y=x%y;
            x=t;
        }
        return x;
    }
    
    tuple<ll,ll,ll> compute(ll x,ll a,ll b,ll c,ll ab,ll ac,ll bc,ll abc){
        if(x<=0) return {0,0,0};
        ll a1=6*(x/a)-3*(x/ab)-3*(x/ac)+2*(x/abc);
        ll a2=6*(x/b)-3*(x/ab)-3*(x/bc)+2*(x/abc);
        ll a3=6*(x/c)-3*(x/ac)-3*(x/bc)+2*(x/abc);
        return {a1,a2,a3};
    }

    void solve(){
        ll a,b,c,m; cin>>a>>b>>c>>m;
        ll ab=a/gcd(a,b)*b;
        ll ac=a/gcd(a,c)*c;
        ll bc=b/gcd(b,c)*c;
        ll abc=ab/gcd(ab,c)*c;
        ll l=0,r=m/abc;
        while(l<r){
            ll mid=l+(r-l+1)/2;
            if(abc!=0 && mid<=m/abc){
                l=mid;
            } else {
                r=mid-1;
            }
        }
        ll fc=l;
        ll rem=m-fc*abc;
        l=0, r=m;
        while(l<r){
            ll mid=l+(r-l+1)/2;
            if(abc!=0 && mid<=m/abc){
                l=mid;
            } else {
                r=mid-1;
            }
        }
        auto [pA,pB,pC]=compute(abc,a,b,c,ab,ac,bc,abc);
        auto [rA,rB,rC]=compute(rem,a,b,c,ab,ac,bc,abc);
        ll ansA=fc*pA+rA;
        ll ansB=fc*pB+rB;
        ll ansC=fc*pC+rC;
        cout<<ansA<<" "<<ansB<<" "<<ansC<<"\n";
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