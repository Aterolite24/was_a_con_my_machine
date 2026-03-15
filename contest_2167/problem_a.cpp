#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        vector<ll>sides(4);
        for(int i=0;i<4;i++) cin>>sides[i];
        for(int i=1;i<4;i++){
            if(sides[i]!=sides[0]){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
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