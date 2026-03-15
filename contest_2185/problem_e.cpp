#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n,m,k; cin>>n>>m>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int>b(m);
        for(int i=0;i<m;i++) cin>>b[i];
        sort(b.begin(), b.end());
        string str; cin>>str;
        int delta=0;
        map<int, int>ans;
        int ptr=0;
        for(auto c : str){
            if (c == 'R') delta++;
            else delta--;
            if (!ans.count(delta)) ans[delta] = ptr;
            ptr++;
        }
        vector<int> ret(k + 1);
        for (int i = 0; i < n; i++) {
            int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            int when = k;
            if (id < (int) b.size() and ans.count(b[id] - a[i])) when = min(when, ans[b[id] - a[i]]);
            if (id > 0 and ans.count(b[id - 1] - a[i])) when = min(when, ans[b[id - 1] - a[i]]);
            ret[when]--;
        }
        int as=n;
        for(int i = 0; i < k; i++) as += ret[i], cout<<as<<" "; cout<<"\n";
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