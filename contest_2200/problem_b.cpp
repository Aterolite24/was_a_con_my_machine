#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        ll f=1;
        for(int i=0;i+1<n;i++) if(v[i]>v[i+1]){f=0;break;}
        cout<<(f?n:1)<<"\n";
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