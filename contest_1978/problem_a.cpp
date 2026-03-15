#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,a,b; cin>>n>>a>>b;
        ll l=0, r=min(n,b);
        while(l<r){
            ll mid=l+(r-l)/2;
            ll s1=a*n+mid*(b-a)-(mid-1)*mid/2;
            ll s2=a*n+(mid+1)*(b-a)-(mid+1)*mid/2;
            if(s1<s2){
                l=mid+1;
            } else {
                r=mid;
            }
        }
        ll maxi=a*n+l*(b-a)-(l-1)*l/2;
        cout<<maxi<<"\n";
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