#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        string s; cin>>s;
        ll cnt0=0; for(int i=0;i<n;i++) cnt0+=(s[i]=='0');
        reverse(s.begin(),s.end());
        ll prev=0;
        vector<int>zero;
        for(int i=0;i<n;i++) if(s[i]=='0') zero.push_back(i);
        ll cost=0;
        for(int i=1;i<=n;i++){
            if(zero.size()<i){
                cout<<-1<<" ";
                continue;
            }
            cost+=zero[i-1]-(i-1);
            cout<<cost<<" ";
        }
        // for(int i=0;i<cnt0;i++){
        //     ll j=i+1;
        //     // cout<<i<<": "<<s<<"\n";
        //     if(s[i]=='1') {
        //         while(j<n and s[j]=='1') j++;
        //         if(j<n){
        //             cout<<j-i+prev<<" ";
        //             prev=j-i;
        //             swap(s[i],s[j]);
        //         }
        //     } else cout<<0<<" ";
        // } 
        // for(int i=cnt0;i<n;i++) cout<<"-1 ";
        cout<<"\n";
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