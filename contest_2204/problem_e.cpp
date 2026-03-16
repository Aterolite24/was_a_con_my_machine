#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        string s; cin>>s;
        ll n=s.size();
        if(n==1){
            cout<<s<<"\n";
            return;
        }
        ll fq[10]={};
        ll T=0;
        for(char c:s) fq[c-'0']++, T+=(c-'0');
        for(int d1=1;d1<=T;d1++){
            ll cs=0, cur=d1;
            string c_str="";
            while(true){
                cs+=cur;
                string t=to_string(cur);
                c_str+=t;
                if(cur<=9) break;
                int nxt=0;
                while(cur>0) nxt+=cur%10,cur/=10;
                cur=nxt;
            }
            if(cs+cur!=T) continue;
            ll cf[10]={};
            for(char c:c_str) cf[c-'0']++;
            ll rf[10]={}, rc=0, rs=0;
            bool ok=true;
            for(int d=0;d<10;d++) {
                rf[d]=fq[d]-cf[d];
                if(rf[d]<0){
                    ok=false;
                    break;
                }
                rc+=rf[d];
                rs+=d*rf[d];
            }
            if(!ok or rc==0 or rs!=d1) continue;
            bool nz=false;
            for(int d=1;d<10;d++) if(rf[d]>0) nz=true;
            if(!nz) continue;
            string x="";
            for(int d=9;d>=0;d--) while(rf[d]--) x+=(char)('0'+d);
            cout<<x<<c_str<<"\n";
            return;
        }
        cout<<s<<"\n";
    }
};

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}