#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll target,a,b,c; cin>>target>>a>>b>>c;
        ll s=a+b+c;
        // a+b+c = 3 days
        //      1= 3/(a+b+c) days
        // target= 3*target/(a+b+c) days
        ll l=0;
        ll r=target/min({a,b,c}) + 5;
        ll ans=0;
        while(l<r){
            ll mid=l+(r-l)/2;
            ll cnt[3]={mid/3,mid/3,mid/3};
            ll rem=mid%3;
            for(int i=0;i<3 and rem>0;i++)cnt[i]++,rem--;
            if(cnt[0]*a+cnt[1]*b+cnt[2]*c>=target){
                r=mid;
            } else {
                l=mid+1;
            }
        }
        cout<<l<<"\n";
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