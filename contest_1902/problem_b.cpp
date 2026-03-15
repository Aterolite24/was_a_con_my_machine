#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,P,l,t; cin>>n>>P>>l>>t;
        ll tasks=(n+6)/7;
        ll lo=0, hi=n;
        while(lo<hi) {
            ll mid=(lo+hi)/2;
            ll solved=min(tasks, 2*mid);
            ll points=mid*l + solved*t;
            if (points>=P) hi=mid;
            else lo = mid + 1;
        }
        cout<<n-lo<<"\n";
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