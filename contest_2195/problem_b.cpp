#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        int flag=0;
        for(int i=1;i<=n;i++){
            int a; cin>>a;
            while(a%2==0)a/=2;
            int d=i;
            while(d%2==0)d/=2;
            if(a!=d){
                flag=1;
                // cout<<a << " " << d<<"\n";
            }
        }
        if(flag) cout<<"NO\n";
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