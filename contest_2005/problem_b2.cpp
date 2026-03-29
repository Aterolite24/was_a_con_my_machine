#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n,m,q; cin>>n>>m>>q;
        vector<int>b(m);
        for(int i=0;i<m;i++) cin>>b[i];
        sort(b.begin(),b.end());
        while(q--){
            int a; cin>>a;
            int idx=m, l_ptr=0, r_ptr=m-1;
            while(l_ptr<=r_ptr){
                int mid=l_ptr+(r_ptr-l_ptr)/2;
                if(b[mid]>a){
                    idx=mid;
                    r_ptr=mid-1;
                } else l_ptr=mid+1;
            }
            if(idx==0) cout<<b[0]-1<<"\n";
            else if(idx==m) cout<<n-b[m-1]<<"\n";
            else{
                int r=b[idx];
                int l=b[idx-1];
                cout<<(r-l)/2<<"\n";
            }
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