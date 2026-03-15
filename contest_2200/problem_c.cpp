#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; string s; cin>>n>>s;
        string s2;
        for(auto ch:s){
            if(!s2.empty() and s2.back()==ch)s2.pop_back();
            else s2.push_back(ch);
        }
        cout<<(s2.empty()?"YES\n":"NO\n");
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
