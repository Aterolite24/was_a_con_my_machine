#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        int ta=0,tb=0;
        if(n==2)cout<<"2\n";
        if(n==3)cout<<"3\n";
        if(n>3)cout<<n%2<<"\n";
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