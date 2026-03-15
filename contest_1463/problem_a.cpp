#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll a,b,c; cin>>a>>b>>c;
        ll sum=a+b+c;
        ll mini=min(a,min(b,c));
        ll d=sum/9;
        if(sum<9) cout<<"NO\n";
        else{
            if(sum%9==0 and mini>=d){
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
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