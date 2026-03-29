#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        if(n==1){
            if(b[0]>=1 and (b[0]>1 or a[0]!=1)) cout<<1<<"\n";
            else cout<<0<<"\n";
            return;
        }
        vector<ll>g(n-1);
        for(int i=0;i<n-1;i++) g[i]=__gcd(a[i],a[i+1]);
        vector<ll>L(n);
        L[0]=g[0];
        L[n-1]=g[n-2];
        for(int i=1;i<n-1;i++) L[i]=(g[i-1]/__gcd(g[i-1],g[i]))*g[i];
        vector<ll>bad_l(n,1),bad_r(n,1);
        for(int i=0;i<n;i++){
            if(i>0) bad_l[i]=L[i-1]/g[i-1];
            if(i<n-1) bad_r[i]=L[i+1]/g[i];
        }
        vector<vector<pair<ll,int>>>c(n);
        for(int i=0;i<n;i++){
            ll unchanged=a[i]/L[i];
            c[i].push_back({unchanged,0});
            ll limit=b[i]/L[i];
            int added=0;
            if(1!=unchanged and 1<=limit){
                c[i].push_back({1,1});
                added++;
            }
            for(ll x=2;x<=limit and added<5;x++){
                if(x==unchanged) continue;
                if(__gcd(x,bad_l[i])==1 and __gcd(x,bad_r[i])==1){
                    c[i].push_back({x,1});
                    added++;
                }
            }
        }
        vector<int>dp_prev(c[0].size());
        for(int j=0;j<(int)c[0].size();j++) dp_prev[j]=c[0][j].second;
        for(int i=1;i<n;i++){
            vector<int>dp_curr(c[i].size(),-1);
            for(int j=0;j<(int)c[i].size();j++){
                for(int k=0;k<(int)c[i-1].size();k++)
                    if(dp_prev[k]!=-1 and __gcd(c[i][j].first,c[i-1][k].first)==1)
                        dp_curr[j]=max(dp_curr[j],dp_prev[k]+c[i][j].second);
            }
            dp_prev=move(dp_curr);
        }
        int gcdcode=0;
        for(int j=0;j<(int)dp_prev.size();j++) gcdcode=max(gcdcode,dp_prev[j]);
        cout<<gcdcode<<"\n";
    }
};

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}