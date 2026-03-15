#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        // solved for sum(ai) for ceil(n/2) people < (total_avg including x)*ceil(n/2)
        ll n; cin>>n;
        vector<ll>a(n); for(int i=0;i<n;i++)cin>>a[i];
        if(n<=2){
            cout<<"-1\n";
            return;
        }
        sort(a.begin(),a.end());
        ll sum=accumulate(a.begin(),a.end(),0ll);
        ll end=n/2 + 1;
        ll res=max(0LL, 2LL*n*a[end-1] - sum + 1);
        // if(res>=0) 
        cout<<res<<"\n";
        // else cout<<"-1\n";
    }
};

int main(){
    int t=1;
    cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}