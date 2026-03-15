#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,m; cin>>n>>m;
        vector<string>p1(n),p2(m);
        for(int i=0;i<n;i++) cin>>p1[i];
        for(int i=0;i<m;i++) cin>>p2[i];
        sort(p2.begin(), p2.end());
        ll common=0;
        for(const string &word : p1){
            ll l=0,r=m-1;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(p2[mid]==word){
                    common++;
                    break;
                } else if(p2[mid]<word) l=mid+1;
                else r=mid-1;
            }
        }
        if(common%2==1){
            if(n>=m) cout<<"YES\n";
            else cout<<"NO\n";
        } else {
            if(n>m) cout<<"YES\n";
            else cout<<"NO\n";
        }
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