#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        bool flag67=false;
        int n; cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        for(int i=0;i<n;i++) {
            if(vec[i]==67) flag67=true;
        }
        if(flag67) cout<<"YES\n";
        else cout<<"NO\n";
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