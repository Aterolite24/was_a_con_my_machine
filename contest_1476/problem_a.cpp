#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k; cin>>n>>k;
        if(n>k){
            k=((n+k-1)/k)*k;
        }
        cout<<(n+k-1)/n<<"\n";
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