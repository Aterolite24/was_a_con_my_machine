#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin >> n;
        string v; cin >> v;
        vector<bool> available(n, true);
        int ans=0;
        for(int i=0; i<n; i++){
            if(v[i]=='1'){
                available[i]=false;
                ans++;
                if(i-1>=0) available[i-1]=false;
                if(i+1<n) available[i+1]=false;
            }
        }
        for(int i=0; i<n;){
            int j=i;
            while(j<n and available[j]) j++;
            int sz = j-i;
            ans += (sz+2)/3;
            while(j<n and !available[j]) j++;
            i=j;
        }
        cout<<ans<<endl;
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