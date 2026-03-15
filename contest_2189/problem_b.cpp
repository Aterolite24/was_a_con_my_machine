#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,x;cin>>n>>x;
        ll a,b,c,w=0;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            x-=(b-1)*a;
            w=max(w,a*b-c);
        }
        if(x<=0)cout<<"0\n";
        else if(w==0)cout<<"-1\n";
        else cout<<(x+w-1)/w<<"\n";
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