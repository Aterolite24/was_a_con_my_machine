#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    ll dig_sum(ll n){
        ll s=0;
        while(n){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    void solve(){
        ll x; cin>>x;
        ll cnt=0;
        for(ll y=x;y<=x+81;y++){
            if(y-dig_sum(y)==x){
                cnt++;
            }
        }
        cout <<cnt<<"\n";
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