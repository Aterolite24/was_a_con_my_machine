#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        vector<int> v(n);
        int l = 1, r = n;
        bool flag = true;
        for(int i=n-1; i>=0; i--){
            if(flag){
                flag = !flag;
                v[i] = r;
                r--;
            } else {
                flag = !flag;
                v[i] = l;
                l++;
            }
        }
        for(int i=0; i<n; i++) cout << v[i] << " "; cout << endl;
    }
};
// 1 2 3 4 5
// 3 2 4 1 5

int main(){
    int t;
    cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}