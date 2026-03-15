#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXA = 1000005;
int spf[MAXA];

void sieve() {
    spf[1] = 1;
    for(int i=2;i<MAXA;i++) spf[i]=i;
    for(int i=4;i<MAXA;i+=2) spf[i]=2;
    for(int i=3;i*i<MAXA;i++){
        if(spf[i]==i) for(int j=i*i;j<MAXA;j+=i) if(spf[j]==j) spf[j]=i;
    }
}

int get_base(int x){
    if(x==1) return 1;
    int p=spf[x];
    while(x%p==0) x/=p;
    if(x==1) return p;
    return -1;
}

class Solution{
public:
    void solve(){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        bool is_sorted=true;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                is_sorted=false;
                break;
            }
        }
        if(is_sorted){
            cout<<"Bob\n";
            return;
        }
        vector<int>b(n);
        for(int i=0;i<n;i++){
            b[i]=get_base(a[i]);
            if(b[i]==-1){
                cout<<"Alice\n";
                return;
            }
        }
        int start_idx=0;
        while(start_idx<n and a[start_idx]==1) start_idx++;
        for(int i=start_idx; i<n;i++){
            if(a[i]==1){
                cout<<"Alice\n";
                return;
            }
        }
        for(int i=start_idx;i<n-1;i++){
            if(b[i]>b[i+1]){
                cout<<"Alice\n";
                return;
            }
        }
        cout<<"Bob\n";
    }
};

int main(){
    sieve();
    int t;
    if(cin >> t){
        while(t--){
            Solution sol;
            sol.solve();
        }
    }
    return 0;
}