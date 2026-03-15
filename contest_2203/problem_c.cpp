#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll S, M;
        cin >> S >> M;
        ll INF = 1.01e18;
        ll s = -1;
        ll e = INF;
        while(s+1 < e){
            ll m = (s+e) / 2;
            ll need = S;
            for(int b = 62; b >= 0; b--){
                if((M >> b) & 1){
                    need -= min(need >> b, m) << b;
                }
            }
            if(need == 0){
                e = m;
            } else {
                s = m;
            }
        }
        if(e == INF){
            cout << -1 << '\n';
        } else {
            cout << e << '\n';
        }
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