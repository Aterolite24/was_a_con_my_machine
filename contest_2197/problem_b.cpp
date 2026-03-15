#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin>>n;
        vector<int> a1(n),b1(n);
        for(int i=0;i<n;i++)cin>>a1[i];
        for(int i=0;i<n;i++)cin>>b1[i];
        vector<int> a(n),b(n);
        for(auto i:a1)if(a.empty()||a.back()!=i)a.push_back(i);
        for(auto i:b1)if(b.empty()||b.back()!=i)b.push_back(i);
        // bool f1=true;
        // for(int i=0;i<n;){
        //     int j=i;
        //     while(j<n and b[j]==b[i]) j++;
        //     bool f2=false;
        //     for(int k=i;k<j;k++){
        //         if(a[k]==b[i]){
        //             f2=true;
        //             break;
        //         }
        //     }
        //     if(!f2) {f1=false;break;}
        //     i=j;
        // }
        // cout << (f1?"YES\n":"NO\n");
        // unordered_set<int>st(a.begin(),a.end());
        // for(int i=0; i<n;i++){
        //     if(!st.count(b[i])){
        //         cout<<"NO\n";
        //         return;
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(a[i]!=b[i]){
        //         bool f1=false;
        //         if(i>0 and b[i]==b[i-1])f1=true;
        //         if(i+1<n and b[i]==b[i+1])f1=true;
        //         if(!f1){
        //             cout<<"NO\n";
        //             return;
        //         }
        //     }
        // }
        // cout<<"YES\n";
        int pa=0,pb=0;
        int sz_a=a.size(), sz_b=b.size();
        while(pa<sz_a and pb<sz_b) if(a[pa]==b[pb]) {++pa;++pb;} else ++pa;
        if(pb == sz_b) cout << "YES\n";
        else cout << "NO\n";
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