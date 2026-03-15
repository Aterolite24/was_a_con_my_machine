#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n,h,l; cin>>n>>h>>l;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int cnt_h=0,cnt_l=0;
        for(int i=0;i<n;i++) cnt_h+=(v[i]<=h), cnt_l+=(v[i]<=l);
        // cout << "counts: "<<cnt_h<<" "<<cnt_l<<endl;
        if(cnt_h==cnt_l){
            cout<<cnt_h/2<<"\n";
        } else{
            cout<<min(max(cnt_h,cnt_l)/2, min(cnt_h, cnt_l))<<"\n";
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