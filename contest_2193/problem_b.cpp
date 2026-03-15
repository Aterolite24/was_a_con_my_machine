#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        if(n == 1) cout << v[0] << "\n";
        else{
            vector<int> l_max(n);
            vector<int> l_max_idx(n);
            l_max[n-1] = v[n-1];
            l_max_idx[n-1] = n-1;
            for(int i=n-2; i>=0; i--) {
                if(v[i] > l_max[i+1]){
                    l_max[i] = v[i];
                    l_max_idx[i] = i;
                } else {
                    l_max[i] = l_max[i+1];
                    l_max_idx[i] = l_max_idx[i+1];
                }
            }
            // cout << "l_max:\n";
            // for(auto i : l_max) cout << i << " "; cout << "\n";
            int l_end = 0, r_end = n-1;
            for(int i=0; i<n; i++){
                if(v[i]>=l_max[i]) continue;
                else{
                    l_end = i;
                    r_end = l_max_idx[i];
                    break;
                }
            }
            for(int i=0; i<n; i++){
                if(l_max[i] > v[i]){
                    reverse(v.begin()+l_end, v.begin()+r_end+1);
                    break;
                }
            }
            for(auto i:v)cout << i << " ";cout <<"\n";
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