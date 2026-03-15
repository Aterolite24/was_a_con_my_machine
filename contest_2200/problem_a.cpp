#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>v(n);
        ll tot=0;
        for(int i=0;i<n;i++) cin>>v[i], tot+=v[i];
        set<int> st;
        for(int i=0;i<n;i++){
            vector<ll>b=v;
            ll r=tot, c=i;
            while(true){
                if(b[c]>0){
                    b[c]-=1,r-=1;
                    if(r==0){
                        st.insert(c);
                        break;
                    }
                }
                c=(c+1)%n;
            }
        }
        cout<<(ll)st.size()<<"\n";
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