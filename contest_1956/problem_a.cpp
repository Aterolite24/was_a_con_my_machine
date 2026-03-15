#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll k,q; cin>>k>>q;
        vector<ll>a(k); for(int i=0;i<k;i++) cin>>a[i];
        ll l=a[0]-1,qi;
        for(int i=0;i<q;i++)cin>>qi,cout<<min(qi,l)<<" ";cout<<"\n";
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