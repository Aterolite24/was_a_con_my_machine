#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        vector<pair<ll,ll>>v(n); for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
        sort(v.begin(),v.end(),[](pair<ll,ll>&a,pair<ll,ll>&b){
            if(a.first>b.first){
                return true;
            } else if(a.first==b.first){
                if(a.second<b.second){
                    return true;
                }
            }
            return false;
        });
        ll p_k=v[k-1].first, t_k=v[k-1].second;
        ll l=0, r=n-1, L=k-1, R=k-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(v[mid].first>p_k or (v[mid].first==p_k and v[mid].second<t_k)){
                l=mid+1;
            } else {
                if(v[mid].first==p_k and v[mid].second==t_k){
                    L=mid;
                }
                r=mid-1;
            }
        }
        l=L, r=n-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(v[mid].first<p_k or (v[mid].first==p_k and v[mid].second>t_k)){
                r=mid-1;
            } else {
                if(v[mid].first==p_k and v[mid].second==t_k){
                    R=mid;
                }
                l=mid+1;
            }
        }
        cout<<R-L+1<<"\n";
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