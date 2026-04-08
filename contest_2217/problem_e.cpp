#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>p(n+1),d(n+1);
        for(int i=1;i<=n;i++) cin>>p[i];
        for(int i=1;i<=n;i++) cin>>d[i];
        vector<ll>ord(n);
        for(int i=0;i<n;i++) ord[i]=i+1;
        sort(ord.begin(),ord.end(),[&](ll a,ll b){
            return p[a]>p[b];
        });
        vector<ll>q;
        bool ok=true;
        for(ll i:ord){
            ll cnt=0;
            for(ll x:q) if(x>i) cnt++;
            if(d[i]>cnt){
                ok=false;
                break;
            }
            ll c=0,pos=q.size();
            for(int j=q.size()-1; j>=0; j--){
                if(q[j]>i){
                    c++;
                    if(c==d[i]){
                        pos=j;
                        break;
                    }
                }
            }
            q.insert(q.begin()+pos,i);
        }
        if(!ok)cout<<"-1\n";
        else{
            vector<ll>ans(n+1);
            for(int i=0;i<n;i++) ans[q[i]]=i+1;
            for(int i=1;i<=n;i++) cout<<ans[i]<<(i==n?"":" ");
            cout<<"\n";
        }
    }
};

int main(){
    int t=1;
    cin >> t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}