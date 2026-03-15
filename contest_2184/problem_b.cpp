#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int s,k,m;cin>>s>>k>>m;
        if(s<=k)cout<<max(0, s - m % k)<<"\n";
        else cout<<(((m % (2 * k)) < k) ? s - m % k : k - m % k)<<"\n";
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