#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        string s,t;cin>>s>>t;
        ll l=0, r=min(s.length(), t.length());
        vector<bool>mp(r,false);
        for(int i=0; i<r; i++){
            if(s[i]==t[i]) mp[i]=true;
            else break;
        }
        ll ans=0, x=0;
        ll i=0;
        while(l<r){
            // cout<<"i: "<<i<<"\n";
            ll mid=l+(r-l)/2;
            if(mp[mid]){
                ans=mid;
                // cout<<ans<<"\n";
                l=mid+1;
            } else{
                // cout<<r<<"\n";
                r=mid;
            }
        }
        if(ans==0){
            if(mp[ans]){
                x=1;
            } else {
                x=0;
                cout<<s.length()+t.length()<<"\n";
                return;
            }
        } else {
            x=ans+1;
        }
        cout<<s.length()+t.length()-x+1<<"\n";
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