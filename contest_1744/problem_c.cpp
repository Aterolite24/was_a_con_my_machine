#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        char curr; cin>>curr;
        string s; cin>>s;
        if(curr=='g') {cout<<0<<"\n"; return;}
        s+=s;
        int maxi=-1;
        vector<int>nextg(2*n,INT_MAX);
        int last=0;
        for(int i=2*n-1;i>=0;i--){
            if(s[i]=='g') last=i;
            nextg[i]=last;
        }
        for(int i=n;i>=0;i--){
            if(s[i]==curr){
                maxi=max(maxi,nextg[i]-i);
            }
        }
        cout<<maxi<<"\n";
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