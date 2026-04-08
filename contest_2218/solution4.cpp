#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXPRIME=200000;
vector<int>primes;

void get_primes(){
    vector<bool>is_prime(MAXPRIME+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int p=2;p*p<=MAXPRIME;p++) if(is_prime[p]) for(int i=p*p;i<=MAXPRIME;i+=p) is_prime[i]=false;
    for(int p=2;p<=MAXPRIME;p++) if(is_prime[p]) primes.push_back(p);
}

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>a(n);
        a[0]=primes[0];
        for(int i=1;i<n;i++) a[i]=(ll)primes[i-1]*primes[i];
        for(int i=0;i<n;i++) cout<<a[i]<<(i==n-1?"":" ");
        cout<<endl;
    }
};

int main(){
    int t=1;
    cin >> t;
    get_primes();
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}
