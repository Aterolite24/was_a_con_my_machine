#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n, x, y; cin >> n >> x >> y;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        ll ans=0, sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(ll)(v[i]/x)*(ll)y;
        }
        for(int i=0;i<n;i++){
            ll val=sum-(ll)(v[i]/x)*(ll)y+v[i];
            ans=max(ans,val);
        }
        cout << ans << "\n";
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