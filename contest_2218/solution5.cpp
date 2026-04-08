#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=300005;
const int BITS=30;

struct Node{
    int child[2];
};

Node trie[MAXN*(BITS+1)];
int nodes_cnt;

void insert(int x){
    int cur=0;
    for(int i=BITS-1;i>=0;i--){
        int b=(x>>i)&1;
        if(!trie[cur].child[b]){
            trie[cur].child[b]=nodes_cnt++;
            trie[trie[cur].child[b]].child[0]=trie[trie[cur].child[b]].child[1]=0;
        }
        cur=trie[cur].child[b];
    }
}

int query(int x){
    int cur=0,res=0;
    for(int i=BITS-1;i>=0;i--){
        int b=(x>>i)&1;
        if(trie[cur].child[1-b]){
            res|=(1<<i);
            cur=trie[cur].child[1-b];
        }else if(trie[cur].child[b]){
            cur=trie[cur].child[b];
        }else return 0;
    }
    return res;
}

class Solution{
public:
    void solve(){
        int n; cin>>n;
        vector<int>a(n);
        nodes_cnt=1;
        trie[0].child[0]=trie[0].child[1]=0;
        int max_xor=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i>0) max_xor=max(max_xor,query(a[i]));
            insert(a[i]);
        }
        cout<<max_xor<<endl;
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