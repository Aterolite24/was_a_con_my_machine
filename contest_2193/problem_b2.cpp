#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin >> n;
        vector<int> v(n); for(int i=0; i<n; i++) cin >> v[i];
        vector<int> id(n+1); for(int i=0; i<n; i++) {
            id[v[i]] = i;
        }
        int l_end = -1, r_end=-1;
        for(int i=0; i<n; i++){
            int target = n-i;
            if(v[i] != target){
                l_end = i;
                r_end = id[target];
                break;
            }
        }
        // cout << l_end << " ends " << r_end << "\n";
        if(l_end != -1 and r_end != -1)
        reverse(v.begin()+l_end, v.begin()+r_end+1);
        for(auto i: v) cout << i << " "; cout << endl;
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