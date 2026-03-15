#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n;
        cin>>n;
        vector<int>v(n);
        int maxi=INT_MIN, mini=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>v[i];
            maxi=max(maxi,v[i]);
            mini=min(mini,v[i]);
        }
        vector<int>b=v;
        sort(b.begin(),b.end());
        int flag=1;
        for(auto i:v)if(v[i]!=b[i])flag=0;
        if(flag)cout<<"-1\n";
        else{
            int ans=1e9;
            for(int i=1;i<=n;++i){
                if(v[i]!=b[i])
                    ans=min(ans,max(v[i]-mini,maxi-v[i]));
            }
            cout<<ans<<endl;
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