#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        ll sz,s=0;
        for(int i=0;i<n;i++)cin>>sz, s+=sz;
        ll l=1, r=sqrt(s)+1, ans=-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(mid*mid==s){ans=mid;break;}
            else if(mid*mid<s){l=mid+1;}
            else r=mid-1;
        }
        if(ans==-1 or ans*ans!=s) cout<<"NO\n";
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