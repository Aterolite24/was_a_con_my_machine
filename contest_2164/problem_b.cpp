#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n;cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((v[i]%v[j])%2==0){
                    cout<<v[j]<<" "<<v[i]<<"\n";
                    return;
                }
            }
        }
        cout<<"-1\n";
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