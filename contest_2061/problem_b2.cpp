#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>a(n); for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        for(int i=1;i<n;i++){
            if(a[i-1]==a[i]){
                ll eq=a[i];
                vector<ll>b;
                for(int j=0;j<n;j++){
                    if(j==i || j==i-1) continue;
                    else b.push_back(a[j]);
                }
                for(int j=1;j<n-2;j++){
                    ll x=b[j-1];
                    ll y=b[j];
                    if(y-x<2*eq){
                        cout<<eq<<" "<<eq<<" "<<x<<" "<<y<<"\n";
                        return;
                    }
                }
            }
        }
        cout<<"-1\n";
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