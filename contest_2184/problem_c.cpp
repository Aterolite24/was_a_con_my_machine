#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n,k;cin>>n>>k;
        int l=n,r=n;
        int cnt=0;
        while(r!=1){
            if(l<=k and k<=r)break;
            l/=2;
            r=r/2+r%2;
            cnt++;
        }
        cout<<((l<=k and k<=r) ? cnt : -1)<<"\n";
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