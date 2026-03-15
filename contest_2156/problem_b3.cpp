#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        ll n,q; cin>>n>>q;
        string s; cin>>s;
        ll cnta=0,cntb=0;
        for(auto ch:s) if(ch=='A') cnta++; else cntb++;
        vector<pair<char, ll>>seqs;
        char last=s[0];
        ll curr=1;
        for(int i=1;i<n;i++) if(s[i]==last) curr++; else {
            seqs.push_back({last,curr});
            curr=1;
            last=s[i];
        } 
        if(curr!=0) seqs.push_back({last,curr});
        while(q--){
            ll qi; cin>>qi;
            if(cntb==0) cout<<qi<<"\n";
            else{
                ll ans=0;
                while(qi){
                    for(auto [ch,cnt]:seqs){
                        if(qi==0) break;
                        if(ch=='A'){
                            cnt=min(cnt,qi);
                            qi-=cnt;
                            ans+=cnt;
                        } else {
                            ll p=0,x=qi;
                            while(x){
                                x/=2;
                                p++;
                            }
                            cnt=min(cnt,p);
                            ans+=cnt;
                            qi>>=cnt;
                        }
                    }
                }
                cout<<ans<<"\n";
            }
        }
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