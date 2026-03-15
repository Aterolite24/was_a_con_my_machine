#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        vector<ll>maxi(n);maxi[0]=v[0];
        for(int i=1;i<n;i++)maxi[i]=max(maxi[i-1],v[i]);
        ll cnt=0;
        for(int i=0;i<n;i++)if(i+1==maxi[i])cnt++;
        if(cnt==1){
            for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<"\n";
        }else{
            ll mx_idx=max_element(v.begin(),v.end())-v.begin();
            ll mx=v[mx_idx];
            swap(v[mx_idx],v[0]);
            for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<"\n";
        }
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