#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        string s; cin>>s;
        vector<int>pre(n+1,0),suf(n+1,0);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i-1]=='(');
        for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]+(s[i]==')');
        int ans=-1;
        for(int i=1;i<=n;i++) if(s[i]==')' and pre[i]+1<=suf[i]-1) ans=max(ans,2*(suf[i]-1));
        cout<<ans<<"\n";
        return;
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