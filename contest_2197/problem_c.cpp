#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll p,q; cin>>p>>q;
        if(3ll*p == 2ll*q) {cout << "Bob\n"; return;}
        ll d=q-p;
        if(d>=1 and d<=p/2) {cout << "Bob\n"; return;}
        cout << "Alice\n";
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