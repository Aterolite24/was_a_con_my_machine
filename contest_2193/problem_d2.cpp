#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    int n;
    vector<int> a, b;
    vector<ll> pf;

    bool can(ll s){
        for(int i=0; i<n;){
            int x=a[i];
            int swords=n-i;
            ll k = (s+x-1)/x;
            if(k>n){
                while(i<n and a[i]==x)i++;
                continue;
            }
            if(pf[k-1]<=swords)return true;
            while(i<n and a[i]==x)i++;
        }
        return false;
    }

    void solve(){
        cin >> n;
        a.resize(n), b.resize(n), pf.resize(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        sort(a.begin(),a.end());
        pf[0] = b[0];
        for(int i=1; i<n; i++) pf[i] = pf[i-1] + b[i];
        ll lo = 0, hi = (ll)1e9 * n, ans=0;
        while(lo <= hi){
            ll mid = (lo + hi)/2;
            if(can(mid)){
                ans = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        cout << ans << "\n";
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