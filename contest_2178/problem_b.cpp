#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
       std::string s;
    std::cin >> s;
    
    if (std::count(s.begin(), s.end(), 'Y') <= 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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