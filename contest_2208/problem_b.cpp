#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void solve() {
        ll n,k,p,m; cin>>n>>k>>p>>m;
        vector<ll>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        deque<pair<ll, bool>>dq;
        for(int i=0;i<n;i++) dq.push_back({a[i], (i+1==p)});
        ll ans=0;
        while(true){
            ll win_pos=-1, min_c=2e18, min_idx=-1;
            for(int i=0;i<k;i++){
                if(dq[i].second){
                    win_pos = i;
                    break;
                }
                if(dq[i].first<min_c) min_c = dq[i].first, min_idx = i;
            }
            if(win_pos!=-1){
                if(m<dq[win_pos].first) break;
                m-=dq[win_pos].first;
                ans++;
                pair<ll,bool>card = dq[win_pos];
                dq.erase(dq.begin() + win_pos);
                dq.push_back(card);
            } else {
                if(m<min_c) break;
                m-=min_c;
                pair<ll,bool>card = dq[min_idx];
                dq.erase(dq.begin() + min_idx);
                dq.push_back(card);
            }
        }
        cout<<ans<<"\n";
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
