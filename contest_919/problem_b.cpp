#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    ll sum_dig(ll n){
        ll ans=0;
        while(n){
            ll digit=n%10;
            n/=10;
            ans+=digit;
        }
        return ans;
    }
    void solve(){
        ll k; cin >> k;
        ll count = 0;
        ll current = 18;
        while(count < k){
            current++;
            if(sum_dig(current) == 10){
                count++;
            }
        }
        cout << current << endl;
    }
};

int main(){
    Solution sol;
    sol.solve();
    return 0;
}