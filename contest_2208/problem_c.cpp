#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void solve() {
        ll n; cin>>n;
        vector<pair<ll,ll>>v(n);
        for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
        long double dp=0;
        for(int i=n-1;i>=0;i--){
            long double p=v[i].second/100.0;
            dp=max(dp, (long double)v[i].first + (1.0-p)*dp);
        }
        cout<<fixed<<setprecision(10)<<(double)dp<<"\n";
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
