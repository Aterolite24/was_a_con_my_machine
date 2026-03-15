#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        ll x=round(sqrt(n));
        if(x*x>=n) cout<<2*x<<"\n";
        else cout<<2*x+1<<"\n";
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