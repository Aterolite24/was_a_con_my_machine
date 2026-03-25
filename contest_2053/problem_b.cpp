#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<pair<ll,ll>>v(n);
        map<ll,ll>freq;
        for(int i=0;i<n;i++) {
            cin>>v[i].first>>v[i].second;
            if(v[i].first == v[i].second) freq[v[i].first]++;
        }
        vector<ll>singletons;
        for(auto const& [val, count] : freq) singletons.push_back(val);
        string ans="";
        for(int i=0;i<n;i++) {
            ll l=v[i].first, r=v[i].second;
            if(l==r) {
                if(freq[l]==1) ans+='1';
                else ans+='0';
            } else {
                ll lb=singletons.size(), low=0, high=(ll)singletons.size()-1;
                while(low<=high){
                    ll mid=low+(high-low)/2;
                    if(singletons[mid]>=l){
                        lb=mid;
                        high=mid-1;
                    }
                    else low=mid+1;
                }
                ll ub=singletons.size(); low=0; high=(ll)singletons.size()-1;
                while(low<=high){
                    ll mid=low+(high-low)/2;
                    if(singletons[mid]>r){
                        ub=mid;
                        high=mid-1;
                    }
                    else low=mid+1;
                }
                ll count=ub-lb;
                if(count<(r-l+1)) ans+='1';
                else ans+='0';
            }
        }
        cout<<ans<<endl;
    }
};

int main(){
    int t=1;
    cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}