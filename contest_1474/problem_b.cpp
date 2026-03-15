#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2*10000+1000;
vector<ll>primes;
void sieve(){
    bool isprime[M];
    memset(isprime, true, sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<M;i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=i*i;j<M;j+=i){
                isprime[j]=false;
            }
        }
    }
}

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        // cout<<(1*(1+n)*(1+2*n))<<"\n";
        // i ignored the fact that it works only when these are prime
        ll l=0, r=primes.size()-1;
        ll p,q;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(primes[mid]-1>=n){
                p=primes[mid];
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        l=0, r=primes.size()-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(primes[mid]-p>=n){
                q=primes[mid];
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        cout<<(ll)p*q<<"\n";
    }
};

int main(){
    int t;
    cin >> t;
    sieve();
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}