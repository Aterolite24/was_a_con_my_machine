#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        vector<int>v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int idx = max_element(v.begin(),v.end())-v.begin();
        swap(v[0],v[idx]);
        vector<int> pf(n); pf[0]=v[0];
        int sum = pf[0];
        for(int i=1; i<n; i++) pf[i]=max(pf[i-1], v[i]), sum+=pf[i];
        cout<<sum<<"\n";
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