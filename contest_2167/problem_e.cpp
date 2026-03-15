#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k,x; cin>>n>>k>>x;
        vector<ll>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        a.push_back(-1e9);
        a.push_back(1e9);
        n+=2;
        sort(a.begin(),a.end());
        ll l=0,r=x+1;
        while(l+1<r){
            ll m=l+(r-l)/2;
            ll cnt=0;
            a[0]=-m, a[n-1]=x+m;
            for(int i=1;i<n;i++) cnt+=max(0ll, a[i]-a[i-1]-2*m+1);
            if(cnt>=k)l=m;
            else r=m;
        }
        a[0]=-l, a[n-1]=x+l;
        ll j=0;
        for(int i=1;i<n;i++){
            for(j=max(j,a[i-1]+l);j<=min(a[i]-l,x) and k; j++)
                cout<<j<<" ", k--;
        }
        cout<<"\n";
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