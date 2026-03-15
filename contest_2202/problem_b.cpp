#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        string s; cin>>s;
        if(n%2){
            if(s[0]=='b'){
                cout<<"NO\n";
                return;
            }
            for(int i=1;i<n;i+=2){
                if(s[i]!='?' and s[i+1]!='?' and s[i]==s[i+1]){
                    cout<<"NO\n";
                    return;
                }
            }
        } else {
            for(int i=0;i<n;i+=2){
                if(s[i]!='?' and s[i+1]!='?' and s[i]==s[i+1]){
                    cout<<"NO\n";
                    return;
                }
            }
        }
        cout<<"YES\n";
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