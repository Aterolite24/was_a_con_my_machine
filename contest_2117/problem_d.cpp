#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int n;
        if(!(cin >> n)) return;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        bool possible = false;
        long long sum_a1_an = a[0] + a[n-1];
        if(sum_a1_an % (n + 1) == 0) {
            long long S = sum_a1_an / (n + 1);
            long long low = 0, high = S;
            long long x = -1;
            
            // Binary search for x in [0, S] such that a[0] = x + n * (S - x)
            while(low <= high) {
                long long mid = low + (high - low) / 2;
                long long val = mid + n * (S - mid);
                if(val == a[0]) {
                    x = mid;
                    break;
                } else if(val < a[0]) {
                    // Since val = mid(1-n) + nS and (1-n) is negative, mid increasing makes val decrease
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if(x != -1) {
                long long y = S - x;
                bool ok = true;
                for(int i = 0; i < n; i++) {
                    if(a[i] != x * (i + 1) + y * (n - i)) {
                        ok = false;
                        break;
                    }
                }
                if(ok) possible = true;
            }
        }

        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;
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