#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int N, M;
        cin >> N >> M;
        int V = N+M+1;
        vector<int> A(N), B(M);
        for(auto& x : A) cin >> x;
        for(auto& x : B) cin >> x;
        vector<int> freq(V);
        for(int x : A) freq[x] += 1;
        vector<int> nmult(V);
        for(int i = 1; i < V; i++){
            for(int j = i; j < V; j += i){
                nmult[j] += freq[i];
            }
        }
        int nA = 0, nB = 0, nAB = 0;
        for(int x : B){
            if(nmult[x] == N){
                nA++;
            } else if(nmult[x] == 0){
                nB++;
            } else {
                nAB++;
            }
        }
        nAB %= 2;
        nA += nAB;
        nAB = 0;
        if(nA > nB){
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
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