#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        for(int i=1; i<=n; i++) cout<<n+2*i<<" "<<i<<" "<<n+2*i-1<<(i==n?"":" ");
        cout<<endl;
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