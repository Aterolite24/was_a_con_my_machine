#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        vector<int> v(n+1);
        for(int i=1; i<=n; i++) cin>>v[i];
        ll ans=0;
        for(int i=1; i<=n; i++){
            int ai = v[i];
            if(ai==0)continue;
            if(ai>n) continue;
            int maxk = (n-i)/ai;
            for(int k=1;k<=maxk;k++){
                int j=i+ai*k;
                if(j<=n and v[j]==k)ans++;
            }
        }
        cout << ans <<"\n";
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