#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i].first;
            v[i].second=i;
        }
        sort(v.begin(), v.end());
        for(int i=1; i<n; i++){
            if((v[i].second%2) == (v[i-1].second%2)){
                cout <<"NO\n"; return;
            }
        }
        cout << "YES\n";
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