#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>a(n); for(int i=0;i<n;i++) cin>>a[i];
        // vector<ll>u(n); u[0]=1; 
        // for(int i=1;i<n;i++) u[i]=u[i-1]+(a[i]==a[i-1]);
        // ll tu=u[n],maxl=-1,maxr=-1;
        // for(int i=0;i<n;i++){
        //     ll l=i, r=n-1, ans=-1;
        //     while(l<=r){
        //         ll mid=l+(r-l)/2;
        //         if(mid-i+1==u[mid]-u[i]+1){
        //             ans=mid;
        //             break;
        //         } else if(mid-i+1<u[mid]-u[i]+1) l=mid+1;
        //         else r=mid-1;
        //     }
        //     if(ans!=-1){
        //         if(ans-i>maxr-maxl){
        //             maxl=i;
        //             maxr=ans;
        //         }
        //     }
        // }
        // if(maxl!=-1 and maxr!=-1) cout<<maxl+1<<" "<<maxr+1<<"\n"; //1-based
        // else cout<<"0\n";
        unordered_map<ll,ll>freq; for(int i=0;i<n;i++) freq[a[i]]++;
        ll best=0,start=0,l=-1,r=-1;
        ll curr=0;
        for(int i=0;i<n;i++){
            if(freq[a[i]]==1){
                if(curr==0) start=i;
                curr++;
                if(curr>best){
                    best=curr;
                    l=start;
                    r=i;
                }
            } else curr=0;
        }
        if(best==0) cout<<"0\n";
        else cout<<l+1<<" "<<r+1<<"\n";
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