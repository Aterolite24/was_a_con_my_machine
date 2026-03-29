#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    bool isValid(int x, int n, vector<ll>& res){
        res.clear();
        res.push_back(x);
        for(int i=n;i>=1;i--) if(i!=x) res.push_back(i);
        for(int i=0;i<n-2;i++) if((res[i]%res[i+1])<(res[i+1]%res[i+2])) return false;
        return true;
    }

    void solve(){
        ll n; cin>>n;
        ll l=1,r=n,ans=n;
        vector<ll>res;
        while(l<=r){
            ll mid=l+(r-l)/2;
            vector<ll>temp;
            if(isValid(mid,n,temp)){
                ans=mid;
                res=temp;
                r=mid-1;
            } else l=mid+1;
        }
        if(res.empty()) isValid(n,n,res);
        for(int i=0;i<n;i++) cout<<res[i]<<(i==n-1?"":" ");
        cout<<endl;
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