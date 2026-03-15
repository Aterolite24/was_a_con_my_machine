#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f[300000], a[300000];
class Solution{
public:
    void solve(){
        ll n; cin>>n;
        for(int i=0;i<n;i++)cin>>f[i];
        for(int i=1;i<n-1;i++)a[i]=(f[i-1]+f[i+1]-2*f[i])/2;
        for(int i=1;i<n-1;i++){
            f[0]-=a[i]*(i);
            f[n-1]-=a[i]*(n-i-1);
        }
        a[0]=f[n-1]/(n-1);
        a[n-1]=f[0]/(n-1);
        for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";
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