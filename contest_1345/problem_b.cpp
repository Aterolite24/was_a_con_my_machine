#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll x; cin>>x;
        ll diff=1e9,cnt=0;
        if(x==1){
            cout<<0<<"\n";
            return;
        }
        while(diff!=0 and diff!=1){
            ll l=0,r=sqrt(x),ans=-1;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(x >= (3*mid*mid + mid)/2){
                    ans=mid;
                    l=mid+1;
                } else r=mid-1;
            }
            diff=x - (3*ans*ans + ans)/2;
            x=diff;
            cnt++;
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