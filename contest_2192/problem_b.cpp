#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        ll c0=0,c1=0;
        string s; cin>>s;
        for(int i=0;i<n;i++){
            c0+=(s[i]=='0');
            c1+=(s[i]=='1');
        }
        if(c0%2==1){
            cout<<c0<<"\n";
            for(int i=0;i<n;i++) if(s[i]=='0')cout<<i+1<<" ";cout<<"\n";
            return;
        }
        if(c1%2==0){
            cout<<c1<<"\n";
            for(int i=0;i<n;i++) if(s[i]=='1')cout<<i+1<<" ";cout<<"\n";
            return;
        }
        cout<<"-1\n";
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