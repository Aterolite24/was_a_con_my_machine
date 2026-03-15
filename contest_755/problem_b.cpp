#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,m; cin>>n>>m;
        set<string>p1,p2;
        string s;
        for(int i=0;i<n;i++) cin>>s, p1.insert(s); 
        for(int i=0;i<m;i++) cin>>s, p2.insert(s);
        set<string>common; set_intersection(p1.begin(),p1.end(),p2.begin(),p2.end(),inserter(common, common.begin()));
        ll common_sz=common.size();
        ll a_sz=p1.size()-common_sz;
        ll b_sz=p2.size()-common_sz;
        if(a_sz + (common_sz+1)/2 > b_sz + (common_sz)/2) cout<<"YES\n";
        else cout<<"NO\n";
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