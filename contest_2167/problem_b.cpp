#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        string inp; cin>>inp;
        string name; cin>>name;
        vector<ll> mp1(26,0); for(auto ch:inp) mp1[ch-'a']++;
        vector<ll> mp2(26,0); for(auto ch:name) mp2[ch-'a']++;
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i]){
                cout<<"NO\n";
                return;
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