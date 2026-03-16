#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin >> n;
        string s; cin >> s;
        ll l=0,r=n-1;
        while(l<r){
            ll mid=l+(r-l)/2;
            bool found=false;
            for(int j=l;j<=mid;j++){
                if(s[j]=='L'){
                    found=true;
                    break;
                }
            }
            if(found) r=mid;
            else l=mid+1;
        }
        cout<<l+1<<"\n";
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