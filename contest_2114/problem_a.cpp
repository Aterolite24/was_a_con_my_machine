#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    ll to_num(string s){
        ll ans=0, l=s.length();
        ll pow=1;
        for(int i=l-1;i>=0;i--){
            ans+=(s[i]-'0')*pow;
            pow*=10;
        }
        return ans;
    }
    void solve(){
        string s; cin>>s;
        ll num = to_num(s);
        // a+b ** 2 = x
        // a+b = rx
        // a = rx - b
        // ll l_a=0, r_a=sqrt(num)/2+1;
        // ll l_b=0, r_b=sqrt(num)/2+1;
        // while(l_a<r_a and l_b<r_b){
        //     ll mid_a=l_a+(r_a-l_a)/2;
        //     ll mid_b=l_b+(r_b-l_b)/2;
        //     if((mid_a + mid_b)*(mid_a + mid_b) <= num){
        //         l_a=mid_a;
        //         l_b=mid_b;
        //     } else {
        //         r_a=mid_a-1;
        //         r_b=mid_b-1;
        //     }
        // }
        // if((l_a + l_b)*(l_a + l_b) == num) cout<<l_a<<" "<<l_b<<"\n";
        // else cout<<-1<<"\n";
        ll l=1,r=100;
        ll ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(mid!=0 and mid*mid==num){
                cout<<0<<" "<<mid<<"\n";
                return;
            }
            else if(mid==0 or mid*mid<num) {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(ans*ans==num)cout<<0<<" "<<ans<<"\n";
        else cout<<-1<<"\n";
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