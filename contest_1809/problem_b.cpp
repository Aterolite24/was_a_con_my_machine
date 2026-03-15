#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double PI=3.14159265358979323846;
// const double PI=180;

class Solution{
public:
    void solve(){
        ll n; cin>>n;
        // vector<double> angles; angles.push_back(360/n);
        // while(angles.back()<360) angles.push_back(angles.back()+360/n);
        // for(auto &angle:angles) angle*=PI/180;
        // double r=1/(2*sin(PI/n));
        // vector<pair<double,double>>pts;
        // for(auto angle:angles)pts.push_back({(r*cos(angle)),(r*sin(angle))});
        // for(auto [x,y]:pts)cout<<x<<","<<y<<"\n"; k->cost <-- (k+1)**2 points
        
        // min k: (k+1)**2 >= n
        ll l=0,r=n;
        ll ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if((mid+1)>=(n+mid)/(mid+1)){
                ans=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
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