#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<int>v(n);
        ll cnt_e=0, cnt_o=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            cnt_e+=(v[i]%2==0);
            cnt_o+=(v[i]%2==1);
        }
        if(cnt_e>0 and cnt_o>0){
            sort(v.begin(), v.end());
            for(auto num:v)cout<<num<<" ";cout<<"\n";
        }
        else{
            for(auto num:v)cout<<num<<" ";cout<<"\n";
        }
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