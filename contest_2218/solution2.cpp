#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        vector<ll>a(7);
        ll mx=-1e18,sum=0;
        for(int i=0;i<7;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
            sum+=a[i];
        }
        cout<<2*mx-sum<<endl;
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