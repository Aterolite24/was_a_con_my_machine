#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rsun(a) a.resize(unique(a.begin(),a.end())-a.begin())
#define all(x) x.begin(), x.end()
#define sz(x) ll(x.size())
#define ba(x) x.back()
#define endl '\n'

class Solution{
public:
    void solve(){
        // int n;cin>>n;
        // string s;cin>>s;
        // int l=0;int f=0;
        // int Ans=0;
        // for(int i=0;i<n;i++){
        //     int ans=0;
        //     rotate(s.begin(),s.begin()+1, s.end());
        //     for(int i=1;i<n;i++){
        //         if(s[i-1]!=s[i])ans++;
        //     }
        //     Ans=max(Ans,ans);
        // }
        // cout<<Ans<<"\n";

        ll n; cin>>n;
        string s; cin>>s;
        string s1=s;
        rsun(s1);
        if(s[0]==ba(s)) cout<<sz(s1)<<endl;
        else cout<<(sz(s)==sz(s1)? sz(s) : sz(s1)+1)<<endl;
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