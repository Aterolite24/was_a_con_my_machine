#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n; cin >>n;
        string b; cin >> b;
        int cz=0;
        for(int i=0; i<n; i++) cz += (b[i] == '0');
        vector<int> idx;
        for(int i=0; i<n; i++){
            if(i<cz and b[i]=='1') idx.push_back(i+1);
            else if(i>=cz and b[i]=='0') idx.push_back(i+1);
        }
        if(idx.size()==0) cout<<"Bob\n";
        else{
            cout<<"Alice\n";
            cout << idx.size() << "\n";
            for(auto i:idx)cout << i << " "; cout << "\n";
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