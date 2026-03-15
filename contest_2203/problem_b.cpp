#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll x; cin>>x;
        vector<ll>digits;
        ll sum=0;
        while(x>0){
            ll d=x%10;
            digits.push_back(d);
            sum+=d;
            x/=10;
        }
        if(sum<=9){
            cout<<"0\n";
            return;
        }
        ll need=sum-9;
        digits.back()-=1;
        sort(digits.rbegin(), digits.rend());
        int moves=0;
        for(auto d:digits){
            if(need<=0)break;
            need-=d;
            moves++;
        }
        cout<<moves<<"\n";
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