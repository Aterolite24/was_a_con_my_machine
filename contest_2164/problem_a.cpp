#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n;cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int x;cin>>x;
        cout<< ((*min_element(v.begin(),v.end())<=x and x<=*max_element(v.begin(),v.end())) ? "YES\n":"NO\n");
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