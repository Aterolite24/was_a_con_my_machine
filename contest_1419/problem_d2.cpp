#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    bool possible(ll k, vector<ll>v){
        ll n=v.size();
        for(int i=0;i<k;i++){
            if(v[i]>=v[n-k+i-1]) return false;
        }
        return true;
    }
    void solve(){
        ll n; cin>>n;
        vector<ll> v(n); for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        vector<pair<ll,ll>>mp;
        ll curr=0, last=v[0];
        for(int i=0;i<n;i++){
            if(v[i]==last) curr++;
            else{
                mp.push_back({last,curr});
                last=v[i];
                curr=1;
            }
        }
        mp.push_back({last,curr});
        // for(auto [ele,cnt]:mp){
        //     cout<<ele<<","<<cnt<<"\n";
        // }
        ll l=0, r=(n-1)/2, ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(possible(mid,v)){
                ans=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        if(n>2) cout<<ans<<"\n";
        else cout<<0<<"\n";
        vector<ll>b;
        int pos_a=0, pos_b=n-(ans+1);
        for(int i=0;i<2*ans+1;i++){
            if(i%2==0){ b.emplace_back(v[pos_b]);
                ++pos_b;
            }
            else{ b.emplace_back(v[pos_a]);
                ++pos_a;
            }
        }
        for(int i=pos_a;i<n-(ans+1);i++) b.emplace_back(v[i]);
        for(auto c:b)cout<<c<<" ";cout<<"\n";
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