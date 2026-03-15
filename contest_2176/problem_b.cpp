#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        string s; cin>>s;
        s+=s;
        n*=2;
        ll curr=0, res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') curr=0;
            else curr++;
            res=max(res,curr);
        }
        cout<<res<<"\n";
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