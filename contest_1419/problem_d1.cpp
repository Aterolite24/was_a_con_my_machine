#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        // 1 = 0
        // 1 2 = 0
        // 1 2 3 = 3 1 2 = 1
        // 1 2 3 4 = 4 1 3 2 = 1
        // 1 2 3 4 5 = 5 1 4 2 3 = 2
        // 1 2 3 4 5 6 = 6 1 5 2 4 3 = 2
        // 1 2 3 4 5 6 7 = 7 1 6 2 5 3 4 = 3
        // 1 2 3 4 5 6 7 8 = 8 1 7 2 6 3 5 4 = 3
        ll m,n; cin>>m; n=m;
        vector<ll>v(n); for(int i=0;i<n;i++) cin>>v[i];
        if(n%2==0)n=n-1;
        cout<<n/2<<"\n";
        sort(v.begin(),v.end());
        ll l=0,r=m-1,i=0;
        while (l<=r)
        {
            if(i%2==0){
                cout<<v[r]<<" ";
                r--;
            } else {
                cout<<v[l]<<" ";
                l++;
            }
            i++;
        }
        cout<<"\n";
    }
};

int main(){
    int t=1;
    // cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}