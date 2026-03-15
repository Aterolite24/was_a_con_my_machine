#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n, s, x;
        cin >> n >> s >> x;
        vector<int> v(n);
        int sum =0;
        for(int i=0; i<n; i++) cin >> v[i], sum+=v[i];
        if((s-sum)%x==0 and sum<=s) cout << "YES\n";
        else cout << "NO\n";
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