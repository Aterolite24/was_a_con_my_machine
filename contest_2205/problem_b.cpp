#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define mkunique(x) sort(all(x));x.erase(unique(all(x)),(x).end())
const ll MAX=300005;
vector<ll>prime;
vector<bool>is_prime(MAX, true);
void sieve(ll n){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
}

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        ll tar=n, ans=1;
        for(int i=2;i*i<=n;i++){
            if(tar%i==0){           // target divisible by i
                ans*=i;
                while(tar%i==0)tar/=i;
            }
        }
        ans*=tar;
        cout<<ans<<"\n";
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