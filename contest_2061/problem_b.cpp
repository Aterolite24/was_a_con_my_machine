#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>a(n); for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        // a: equal sides
        // x: smaller parallel
        // y: longer parallel
        // x <= y < (2*a + x)
        ll ans=-1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                vector<ll>b=a;
                ll s1=a[i];
                b.erase(b.begin()+i);
                b.erase(b.begin()+i-1);
                for(int j=0;j<n-2;j++){
                    ll x=b[j];
                    ll l=j+1,r=n-3;ans=-1;
                    while(l<=r){
                        ll mid=l+(r-l)/2;
                        if(b[mid]<(2*s1+x)){
                            ans=mid;
                            l=mid+1;
                            break;
                        } else {
                            r=mid-1;
                        }
                    }
                    if(ans!=-1) {
                        cout<<s1<<" "<<s1<<" "<<x<<" "<<b[ans]<<"\n";
                        return;
                    }
                }
            }
        }
        if(ans==-1) cout<<"-1\n";
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