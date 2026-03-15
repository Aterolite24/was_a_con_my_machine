#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin >> n;
        // vector<int>v(n);
        // for(int i=0;i<n;i++)cin>>v[i];
        // int cnt_z=0,cnt_o=0;
        // for(int i=0;i<n;i++){
        //     if(v[i]==0)cnt_z++;
        //     cnt_o+=(v[i]==1);
        // }
        // if(cnt_z==0) cout <<"NO\n";
        // else if (cnt_z==1)cout<<"YES\n";
        // else{
        //     if(cnt_o) cout<<"YES\n";
        //     else cout<<"NO\n";
        // }
        int a[2]={0};
        for(int i=0; i<n; i++){
            int x; cin>>x;
            if(x<2) a[x]++;
        }
        cout << ((a[0]==1 || a[1] and a[0]) ? "YES\n" : "NO\n");
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