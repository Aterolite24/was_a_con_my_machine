#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        string s; cin>>s;
        ll len=s.length();
        vector<pair<int,int>>mp(26,{0,0});
        for(auto ch:s){
            mp[ch-'a'].first=ch-'a';
            mp[ch-'a'].second++;
        }
        sort(mp.rbegin(),mp.rend());
        string res=string(mp[0].second, char(mp[0].first + 'a'));
        cout<<res;
    }
};

int main(){
    int t=1;
    // cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}