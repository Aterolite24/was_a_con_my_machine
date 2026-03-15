#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,k,x; cin>>n>>k>>x;
        vector<ll>a(n); for(int i=0;i<n;i++) cin>>a[i];
        vector<ll>pre(n+1); pre[0]=0;
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i-1];
        ll cnt=0, limit=pre[n]*k;
        if(x>limit){
            cout<<"0\n";
            return;
        }
        for(int i=1;i<=n*k;i++){
            ll l=0,r=n-1,target=x+pre[i-1];
            ll lookup_idx=(target+pre[n]-1)/pre[n];
            if(lookup_idx>k){
                continue;
            } else {
                vector<ll>space(n);
                for(int i=1;i<=n;i++)space[i-1]=(lookup_idx*pre[n] + pre[i]);
                bool flag=false;
                while(l<=r){
                    ll mid=l+(r-l)/2;
                    if(space[mid]>=target){
                        flag=true;
                        r=mid-1;
                        break;
                    } else l=mid+1;
                }
                if(flag) cnt++;
            }
        }
        cout<<cnt<<"\n";
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