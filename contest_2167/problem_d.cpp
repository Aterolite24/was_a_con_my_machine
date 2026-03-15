#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 100;
bool isprime[maxn+1];
vector<ll>primes;
void sieve(){
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=maxn;i++)
        if(isprime[i])
            for(int j=i*i;j<=maxn;j+=i)
                isprime[j]=false;
    for(int i=2;i<=maxn;i++) if(isprime[i]) primes.push_back(i);
}
class Solution{
public:
    void solve(){
        ll n; cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        ll mini=*min_element(a.begin(),a.end());
        ll res=LLONG_MAX;
        if(mini==1)cout<<"2\n";
        else {
            for(auto num:a)
            for(auto prime:primes){
                if(num%prime!=0){
                    res=min(res,prime);
                }
            }
            cout<<res<<"\n";
        }
    }
};

int main(){
    int t;
    cin >> t;
    sieve();
    // cout<<primes.size()<<"\n";
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}