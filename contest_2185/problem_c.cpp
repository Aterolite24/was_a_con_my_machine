#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        vector<int> v(n);
        set<int> st;
        for(int i=0; i<n; i++) cin>>v[i], st.insert(-v[i]);
        int ans=0;
        for(int x:st){
            set<int>nums;
            for(int y:v)nums.insert(y+x);
            int mex=0;
            for(int i=0; ;i++){
                if(!nums.count(i)){
                    mex=i;break;
                }
            }
            ans=max(ans,mex);
        }
        cout<<ans<<"\n";
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