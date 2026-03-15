#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        vector<ll>v(n); for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        // vector<ll>p=v;
        // for(int i=1;i<n;i++) p[i]-=p[i-1];
        ll idx=0, sum=0, diff=0;
        for(int i=0;i<n;i++){
            if(i>0) diff=v[i]-v[i-1];
            else diff=v[i];
            sum+=diff*(n-i);
            if(sum>=k){
                break;
            }
            idx++;
        }
        cout<<k+idx<<"\n";
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