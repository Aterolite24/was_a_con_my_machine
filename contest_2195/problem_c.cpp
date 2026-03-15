#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int ans=0;
        for(int i=1;i<n;i++){
            if(v[i-1]==v[i] or v[i-1]+v[i]==7){
                ans++;
                i++;
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