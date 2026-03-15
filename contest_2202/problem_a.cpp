#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll x, y; cin>>x>>y;
        if((y>=0 and x-2*y<0) or (y<0 and x+4*y<0) or (x-2*y)%3!=0) cout<<"NO\n";
        else cout<<"YES\n";
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}