#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,x,y; cin>>n>>x>>y;
        vector<ll>a(n); ll sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a.begin(), a.end());
        ll L=sum-y;
        ll R=sum-x;
        ll ans=0;
        for(int i=0;i<n;i++){
            ll targetL=L-a[i];
            ll targetR=R-a[i];
            ll lb=n, low=i+1, high=n-1;
            while(low<=high){
                ll mid=low+(high-low)/2;
                if(a[mid]>=targetL){
                    lb=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            ll ub=-1, low2=i+1, high2=n-1;
            while(low2<=high2){
                ll mid2=low2+(high2-low2)/2;
                if(a[mid2]<=targetR){
                    ub=mid2;
                    low2=mid2+1;
                }
                else high2=mid2-1;
            }
            if(lb<=ub and lb!=n and ub!=-1) ans+=(ub-lb+1);
        }
        cout<<ans<<endl;
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