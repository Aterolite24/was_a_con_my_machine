#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        ll cnt=0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i]>v[j]){
                    cnt++;
                    v.erase(v.begin()+j);
                    j--;
                }
            }
        }
        cout<<cnt<<"\n";
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