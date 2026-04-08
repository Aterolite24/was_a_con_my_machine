#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(int t){
        ll x,y; cin>>x>>y;
        if(t==2) x++;
        ll n=x+y; bool ok=false;
        if(n%2==0){
            if(x>=1 and x<=n/2) ok=true;
        } else{
            if(x>=0 and x<=(n-1)/2) ok=true;
        }
        if(ok){
            cout<<"YES"<<endl;
            int num_pairs=(n%2==0)?x-1:x;
            int cur_node=2;
            for(int i=0;i<num_pairs;i++){
                cout<<1<<" "<<cur_node<<endl;
                cout<<cur_node<<" "<<cur_node+1<<endl;
                cur_node+=2;
            }
            while(cur_node<=n){
                cout<<1<<" "<<cur_node<<endl;
                cur_node++;
            }
        }else cout<<"NO"<<endl;
    }
};

int main(){
    int t=1;
    cin >> t;
    int tt=t;
    while(t--){
        Solution sol;
        sol.solve(tt);
    }
    return 0;
}