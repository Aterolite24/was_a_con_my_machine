#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,m; cin>>n>>m;
        vector<pair<ll,ll>>d(n);
        for(int i=0;i<n;i++)cin>>d[i].first;
        for(int i=0;i<n;i++)cin>>d[i].second;
        sort(d.begin(),d.end());
        
        ll ans=0;
        for(int i=0;i<n;i++){
            ll a1 = d[i].first, c1 = d[i].second;
            ll k1 = min(c1, m/a1);
            ans = max(ans, k1 * a1);
            
            if(i + 1 < n && d[i+1].first == a1 + 1){
                ll a2 = d[i+1].first, c2 = d[i+1].second;
                ll low = 0, high = c1 + c2;
                while(low <= high){
                    ll k = low + (high - low) / 2;
                    // For a fixed total k = k1 + k2, we want to maximize k2
                    // k2 >= k - c1, k2 <= c2, k2 <= m - k*a1
                    ll min_k2 = max(0LL, k - c1);
                    ll max_k2 = min({k, c2, m - k * a1});
                    
                    if(min_k2 <= max_k2){
                        ans = max(ans, k * a1 + max_k2);
                        low = k + 1;
                    } else {
                        if (k * a1 > m) high = k - 1;
                        else {
                            // Even with min_k2, it might be impossible if k - c1 > c2
                            if (k - c1 > c2) high = k - 1;
                            else low = k + 1; // This case shouldn't really happen with correct bounds
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
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