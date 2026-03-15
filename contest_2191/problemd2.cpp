#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define int long long 
#define fr(i,s,f) for(int i=s;i<f;i++)
#define dr(i,s,f) for(int i=s;i>=f;i--)
#define prnt(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define db cout<<"db: "
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define all(v) v.B,v.E
#define sz(v) (int)((v).size())
#define vi vector<int>
#define vii vector< pair<int,int> >
const int MOD=998244353;
//1e18~2^60 ok remember this for bitwise and for any left shift or right shift for value~1e18 use (1LL<<x) instead of (1<<x) and declare every varaible of long long type explicitly
//so if shifting 1 for any m>31 upto 60 use(1LL<<m)
//remove 3 for loop by sorting then two pointer and check the index for the neccessary condition
//4 1 2
//a1,a2,a3,a4,a5,a6
//a1*a2+a1*a3+a1*a4+a1*a5+a1*a6
//a1(a2+a3+a4+a5+a6)
//a1*(sum(an)-a1)
//a2*(sum(an-prefix sum(ai)));
//6=110
//a1=010=2
//a2=100=4
//a3=010=6
//000
// 11=3
//  1=1
//  1=1
//  1=1
// 10=2

//
//case 1-n=even and ith bit should be zero ith bit of all number is also zero
//case 2- n==even and ith=1 n-1 tak 0 and nth will be 1
//
//-------------------------------------TIPS---------------------------------------------------//
//1.if u want to find number in range[a,b] first precompute then either think about lower and upper bound or think about prefix sum to find the count using s[b]-s[a-1]=count
//2.some time map of int,vector is also usefull 
//3.for MEx u can maintain a set of (x+1) for each x value until x+1 is not in the original set to find the mex and then take lower bound
//4.dealing with fraction either store them in pair of int ,int rahter than calulating a/b ie stay far away from floating point errors
//5.dealing with fraction also take /0 under case and also deal with the negatives think about reducing the fraction etc
//6.make a class or struct for handling the fraction
//7.sometime in greedy in sorting we use exchange argument type think about it also
//printf("%02d:%02d\n", h, mi); this help to print int upto digit like 5->05 ansd 2->02 etc
//instead of erasing a value from the vector we have a start varaible pointing to start of the vector and then move it ahead if we want to delete the first value of the vector
//for finding some number in range of l->r first find from (1->r)-(1->l-1) this will be the ans
//u can also see the multiple of that number
//anything smaller in +ve is always greater in -ve so use this for sorting techniques
//if asked for non-overlapping forget the previous val and consider the array to be new and reset every thing like sum,map,prefixsum etc
//fixed << setprecision(10) here fixed fources the double value to print the decimal value and setprecision tell how many values after decimal of the double are to be printed
//------------------------------------bit manupilation----------------------------------------//
/*
int have base 10 while bit have base 2
operator are used for bitmanupilation 
AND(&)= two same thing give 1
OR(|)
left shift(<<)=multiply the given number with two to the power the number of place to be shifted or add 0 at the begining
right shift(>>)=devide the given number with two to the power the number of place to be shifted or add 0 at the end
so to check for the i th bit to be set then 
if x & (1 << i)==0 i th bit is not set
to set the i th bit of a number then take or of that number with left shifting 1 to i bits
to unset a set bit we take a xor it 1^1==0
and if we dont know what the bit is then take & with the complement of the left shifted bit to i th position
12=1100
12-1=1011
12&(12-1)=1000 so the right most bit is unset 
ie for unsetting the right most bit of a number take x&(x-1)
similarly if we have 
32=10000
32-1=01111
take 32&(32-1)==00000
so for chaecking if a number is in the power of 2 s then x&(x-1)==0
OR operation also increases while and always decreases or is equal
if we have tow number then xor of number is same then it will give 0 else will give the number of non similar bit in the two 
if u want to add 2 things but for diff i like if i is even then something else other thing and i should keep on increasing then use xor for t=0 t^=1 so t becomes 1,0,1,0.....
*/


//-----------------------------------------STL-----------------------------------------------//
//sort(arr,arr+x); goes till lenght x exclusive of x
//reverse(arr,arr+x)
//next_permutation(arr,arr+x);gives the next permutation of the arr element in the length this make the next permutation and return a value in bool if the permutation exist or not
//.find() and .count  are usefulas they do the work in logn rather than O(n) time complexity
//sort(v.begin(),v.end(),greater<int>()) this will sort the vector in descending order and greater works like a custom comparitor
//a comparator function in c++ does not include= on comparision as because a comparator should be irreflexive,asymmetric and transitive
//if we wNant a cut point in any array like to find median so we can maintain to multiset out of which one will contain the smaller element and the other will contain the larger element and shifting will occur between them
//similarly in case of finding element with highest frequency in a dynamic seqeuence we can use a combination of map and multiset as multiset will contain pair of element as (freq,element) and to delete and insert an element with changing freq map will be used
//if sorted array and prefix sum u can also think about lower and upper bound
//we can also use array of vectors
// in priority queue of pair the elements get sorted according to the first element then it is sorted by the second element
// we can not modify the container like multitset or map while iterating over it
// want to find high or low value with respect to something then use upper or lower bound
//prev is also used to find the itreatore to the pervious element of some other itreator in map ,set or multiset
//mp.find() if mp is a multipmap then it give the first occuranfe of the variable ot be found no all the occurence so for that we use mp.equal_range iterator and iterate using for loop over all the ocurences of the variable
// sort(v.begin(),v.end()); sort the vector element in a lexicographical order ie if v={{x,y},z} the first x is checked followed by y if x is equal for some entry then z is checked after y 
//now if u want to store the last occurence of any element use the same way ie mp[v[i]]=i but if u want to store the first occurence of the element use count() function mp.count==0
//if u want to modify something in map then use auto &it:mp as without the reference & operator it will create a coy and modify that so modify the referenced value of map







//-------------------------------------Bit manupilaation------------------------------------//
//__builtin_popcountll(x); function which directly give the number of set bit in x as count;
//1.2^N==1<<n
//use >> shift for bit masking and << for converting in power of 2
//we can make [1,1] also by[-1,0,1] as 2^i+2^(i+1)==2^(i+1)-2^(i-1) 
//xor for a range then use prefix xor array ie xor from 1 to n=a1^a2^a3....an 
//there is an observation also if n%4==1 then xor for the range of n is 1 for n%4=2 or 0 is n+1 , n%4==3 then ans=0 else 
//now if for a range from l to r the xor can be calculated using prefix xor same as prefix sum ie xor(l,r)=xor(l-1)^xor(r)
//as xor(l-1)=a1^a2^a3...al-1
//and xor(r)=a1^a2^a3....ar
//so now a1,a2.. al-1 get cancelled out as they become 0 and only al^al+1...ar remains
//similarly if for array a we have all the prefix xor like xor0=0,xor1=a1,xor2=a1^a2,xor3=a1^a2^a3 then if we have this prefix xoor array
//we can build the original array a by taking xor of adjacent elements like a4 will be xor3^xor4=a1^a2^a3^a1^a2^a3^a4=a4 only so ai=xor(i-1)^xor(i)
//if we have number from 1 to n then for the dth bit the 1 to 2^d-1 number will have 0 in the dth bit while the next 2^d to 2^(d+1)-1 will have the bit set to 1 so this make a block of 2^(d+1) length having 2^d zeroes and 2^d ones 
//similarly if we have a range [l,r] then if floor(l/(2^(d+1)))!=floor(r/(2^(d+1)))that mean there has been a block of 2^(d+1) have 2^d zeroes and ones so the bit must have changed from 0 to 1
//sliding window for or,gcd,lcm and min,max is non inversive that is the operation like if we have a window of length k then on adding a number to get the result of the new window wont be like previous-arr[i]+arr[new] here +,- are the operation like gcd,lcm,or..etc
//so to find the OR or min max can be done using pre_or[k] ie for each segment of length k find the prefixOR and similarly calculate the sufixOR for the same segment edgecase( in case of suffix if the last segment is not of lenght k then so for that case initially put suffix[n-1]=arr[i])
//for prefix_OR if the length of window is already k then for the new segment if (i%k==0 ie new segment start) pref_or[i]=arr[i] else pref_or[i]=pref_or[i-1]|arr[i] 
//similarly for the suff_or if new segement is starting ie (i%k==k-1) then suff_or[i]=arr[i] else suff_or[i]=suff[i+1]|arr[i] 
//now in order to calculate the or of the sliding window of lenght k until end-start+1<k keep increasing the end pointer and continue the if it is greater then for the lenght of k window or of the window=pref_or[end]|suff_or[end-k+1]

//------------------------------------MOD OPERATION------------------------------------------//
//#define MOD (10^9)+7// we take this a s because first the no is prime number and the inverse modulo required during devide is unique for every number and exit;
//(a+b)%MOD=((a%m)+(b%m))%m
//Lcm(a,b)*hcf(a,b)=a*b
//similar for multiplication
//(a*b*c)%mod=(((a%Mod)*(b%mod))%MOD*(c%MOD))%mod
//(a-b)%MOD=((a%mod)-(b%mod)+mod)%mod
//(a^b)%MOD=if b=0->a%mod;
//else if b=even->cal pw(a,b/2,m); pw is a recursive function
/*
int pow(int a,long long int b,int m){
    if(b==0){
    return 1;
    int half=pow(a,b/2,m);
    if(b%2==0){
        return 1LL*half*half%m;
        }
    else{
        return (1LL*half*half)%m*a%m;
        }
}
for a/b%m= a * (b)^-1
when m is prime
so we fermatt little theroem so according to which inverse_modulow of(x)=pow(x,m-2,m)
or a^p-1%p=1 where p is a prime number
therefore ******a/b%m== a * inverse_modulow(b)== a * pow(b,m-2,m) % m ....ans
when m is not prime then we can use euler totient function

4 rule to deal with modulo expression that too large one 
1.make expression tree
2.deal with input like if they are alredy in overflow range than take modulo at the starting onyly
3.check for negative outputs
4.check while merging the ans of decision tree

*/



//----------------------------------SOME VECTOR OPERATIONS----------------------------------------//
//to find the first index where the sequence changes us the following function
//for finding form begining
//int x1 = find_if_not(v.begin(), v.end(), [&](int num){ return num == v[0]; }) - v.begin() - 1;
// Find last position where elements change
//int y1 = n - (find_if_not(v.rbegin(), v.rend(), [&](int num){ return num == v[n-1]; }) - v.rbegin());
// lambda function [capture clause](para){funct def}
//all_of(v.begin(),v.end(),lmbda fun)
//any_of(v.begin(),v.end(),lmbda fun)
//none_of(v.begin(),v.end(),lmbda fun)
// if u only want to check existence in a set u can also use .count() fun in place of .find() for a set
// instead of using a set to count the unique elements we can use a vector and then use the following line of code to remove all duplicates from the vector
// ******* but first have to sort the vector as because it only remove the consequtive duplicate from the vector v.resize(unique(v.begin(),v.end())-v.begin()); this is much faster than set
//in sliding window the length of the window is equal to end-start+1=k and the number of window =n-k+1 for sliding window inside the second while loop if (end-start+1<k) keep continuing and increase the end else add the new element and remove the element pointed by the start pointer 


//---------------------------------STRING OPERATION FUNCTIONS-------------------------------------//
//how to take substring of a string
//s.substr(i,j-i+1);/where i is the starting point of the substring and j is the last char of the substring
// s.substr(i,length) where i is the starting index of the substring and length of the substring you want 
// s.find(string p) is used to find the string in the string s if it is not present then the function will give string::npos with no () at end
// so compair s.find(p)!=string::npos npos stand for null pos in the string
//s.substr(l-1,r-l+1)for substring bte l and r index inclusive
//use a dummy getline to remove the '\n'after a cin else the \n will be first taken by the getline then the next or the actual line 
//dummy getline== make an unintialised variable temp then use the getline to store the \n in temp like this getline(cin,temp);
//getline(cin,variable)
//stringstream ss(variable) make a string stream of the word seprated by space hence used when want the words to be seprated by spacess
//these are then stored in other string variable like ss>>v1 or ss>>v2 ..... so on 
// similarly if u want a part of string to be seprate by any char then use getline(ss,segment,'char') here ss is the string stream segment is a string to store the string seprated by the character
//this can also be done using simple cin>>variable in while loop and to print the word with spaces btw them we can use a flag
//we can use s.erase(i+1,1) ie this remove the character or str starting form index i+1 and of length 1. lenght can be more than one also
//master theorum= t(n)=a*t(n/b)+c find a,b,c for a program
//p.find(t,start)=gives the index in p of the first occurence of t starting from the index start ie p.find()>=0 if not equal to npos()

//------------------BASIC MATH-----------------------------------------//
//GCD PROPERUTES
//1.gcd(a,b)==gcd(a,b%a)==gcd(a,b-a) as if a number /a and b then it eill also devide their difference and this can also give the gcd -ve
//so gcd(x+a,y+a,z+a...)=gcd(x+a,y-x,z-x.....) using above property
//number of diagonal in a n sided polygon=n*(n-2)/2
//double x;
//cin>>x;
//cout<<fixed<<setprecision(2);
/*. FIXED-> means everything next happens for after the floating point part only.
  setprecision(2) -> Now on, every print will happen with roundoff to 2 decimal places. */
//cout<<x<<'\n'; // will print the number. 
//cin>>n; 
// ceil=a+b-1/b and  floor=a/b round of =2*a+b/2*b
//long double is used for preciese calculation of the floating point or we also use an epcilen value like 1e-10 etc and add it to the result
/*string s;
        cin>>s;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count++;
            }
        }
        cout<<count<<endl;
// if we want to find a pair of n different variable then we can do it by fixing one and then iterating over the min and max possible value of the fixed variable and then find the range or the nimber of pair possible for the changing varaibles
//there is an identity called Bezouts identity according to which there will be int value satisfying the equation ax+by=c if and ony if the gcd(a,b) will devide c compeletly ie ax+by=gcd(a,b) ie the samllest c will be the gcd of both a and b ex= if a=3 and b=2 then the equation 3x+2y can give us 1 and -1 and zero if x=0 ans y=0 
reduction of sum of digit mean to take % with 9 as sum will be reduce until sum is less than 10

//n+1c2 is smae as n(n+1)/2


//-----------------------------------------SOME MATH ALGORITHM AND FUNCITON------------------------------//        
// prime number using square root tc=O(n*sqrt(n))
so if iis a factor of n ie 
n%i==0 and i<sqrt(n) then the other factor ie n/i will be >sqrt(n) hence this factor also give n%n/i==0 therfore these will be the two factor other than 1 and n
hence if we found a factor between 2 to sqrt(n) then there must be a factor whihc will be greater than the sqrt(n) hence the number wont be a prime number
therefore to declare a number non prime we have to find a factor till sqrt(n)
code:
for(int i=2;i<=n;i++){
    for(int j=2;j*j<=i;j++){
        if(i%j==0){
            non prime
        }
    }
}
// to take log with base 2=log(x)/log(2);
or recursive deivde by 2
    //seive of erthothenes
        vector<bool>v(120001,true);
    v[0]=v[1]=false;
    int n=v.size();
    for(int i=2;i<n;i++){
        if(v[i] && i*i<n){
            for(int j=i*i;j<n;j+=i){
                v[j]=false;
            }
        }
    }
    //
    my code for seive
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=0;
    for(int i=2;i<=n;i++){
        if(prime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    binary pow exponent=if(eg 2^13->2*2^12->2*4^6->2*16^3->2*16*16^2->32*256  TC=O(n/2) and if you have to take modular with any number then take modular while multilpying with result and in case of odd and even)

    //--------ITERATIVE BINARY SEARCH------------------------------------//
    //use upper bound function to find the just larger element than ai in a sorted array in log n time upper_bound(v.begin(),v.end(),no to be found),similar for lower bound
    int binary_s(vector<int>&v,int low,int high,int& d,int &ans){
    while(low<=high){
        int mid=low+(high-low)/2;
        if(pos(v,d,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    //sorted element and finding the first or last occurence of some element if multiple values are present then think about lower and upper bound
}
 */
int gcd(int a,int b){
    if(b==0){// see if a=0 b=2 then a%b=0 which goes as b and a=2 therefore if u do a==0 return b then this will be missed and a%b will be calculated 
        return a; //which will cause floating point error
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return((a*b)/gcd(a,b));
}
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};//make matrix and then use these
int dx1[4]={-1,1,0,0};
int dy1[4]={0,0,-1,1};
bool sort_pair(const pair<int,int>&a,const pair<int,int>&b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    return a.second<b.second;
}
//vector<bool>v(1e7+1,true);
//unordered_set<int>s1;
/*void seive(){
    v[0]=v[1]=false;
        int n=v.size();
        for(int i=2;i<n;i++){
            if(v[i] && i*i<n){
                for(int j=i*i;j<n;j+=i){ so here u can see that for marking all multiples we are going till n so we only use root n when we 
                    v[j]=false;// want to check for the devisors of it
                }
            }
        }
}
class frac_red{
    public:
        pair<int,int>data;
        frac_red(int n,int d){
            data.first=n;
            data.second=d;
        }
        void red(){
            if(data.second<0){
                data.first=-1*data.first;
                data.second=-1*data.second;
            }
            if(data.second==0){
                data.first=1;
                data.second=0;//making 1/0 form as we will check for a and b
            }
            else if(data.first==0){
                data.second=1;
            }
            else{
                int gd=gcd(abs(data.first),abs(data.second));
                data.first/=gd;
                data.second/=gd;
            }
        }
};*/
/*int get_pow(int a,int b,int m){
    if(b==0){
        return 1;
    }
    int half=get_pow(a,b/2,m);
    if(b%2==0){
        return (half%m*half%m);
    }
    return (a%m*half%m*half%m)%m;
}*/
int log_fc(int x){
    int count=0;
    while(x>1){
        x=(x+1)/2;
        count++;
    }
    return count;
}
int get_pow_m(int a,int b,int m){
    if(b==0){
        return 1;
    }
    int half=get_pow_m(a,b/2,m);
    if(b%2==0){
        return (half%m*half%m);
    }
    return (a%m*half%m*half%m)%m;
}
int get_pow(int a,int b){
    if(b==0){
        return 1;
    }
    int half=get_pow(a,b/2);
    if(b%2==0){
        return (half*half);
    }
    return (a*half*half);
}
int freq[1001000];
/*void bubble_sort(vi &a,vector<pair<int,int>>&s1,int k){
    int n=a.size();
        fr(i,0,n-1){
            bool flag=true;
            fr(j,0,n-1-i){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    flag=false;
                    s1.push_back({k,j+1});
                }
            }
            if(flag){
                return;
            }
        }
}*/
bool valid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
//median of an array of length 3 is int a=max(v[i],v[i-1]),b=max(v[i],v[i+1]),c=max(v[i-1],v[i+1]); and median =min(a,min(b,c));
//subsequence of an array is the one in which order matters but not continuity
//eg-: 1 1 1 2 2 2 -> subsequences=111,112,112,122,222..etc  where as 121 is not a subsequence as no 2 comes before 1
//take any element but the order of the elements comming in the array is same as present in the original array
//for cyclic expression in clockwise dir=(q+r-1)%n+1, for anticlock dir=(q-r-1+n)%n+1;
//in c++ -1/2 ==0 not -1 so if you dont want to add any thing if -ve then then make a conditon for it as c++ truncates the -ve value not round off
template<class T>
struct Aggstack{
    stack<pair<T,T> >s;
    void push(T x){
        if(s.empty()){s.push(make_pair(x,x));}
        else{s.push(make_pair(x,x|s.top().second));}
    }
    T top(){
        return s.top().first;
    }
    T pop(){
        T ret=s.top().first;
        s.pop();
        return ret;
    }
    bool empty(){
        return s.empty();
    }
    int size(){
        return s.size();
    }
    T get(){
        return s.top().second;
    }
};
template<class T>
struct aggQueue{
    Aggstack<T>In,out;
    void push(T val){
        In.push(val);
    }
    //always pop from out stack
    T pop(){
        if(out.empty()){
            while(!In.empty()){
                out.push(In.pop());
            }
        }
        return out.pop();
    }
    T get(){
        if(In.empty()){return out.get();}
        if(out.empty()){return In.get();}
        return In.get()|out.get();
    }
};
vector<int>pre(2*1e5,0);
void pre_com(){
    for(int i=1;i<=2*1e5;i++){
        int x=i,ans=0;
        while(x!=0){
            ans+=x%10;
            x/=10;
        }
        pre[i]=pre[i-1]+ans;
    }
}
bool prefix(int val,int ind,int mid,int x){
    if(x>=((val+(mid-1)*(ind+1)))){
        return true; 
    }
    return false;
}
int binary_search(int last,set<int>&s1){
    int low=last,high=1e9,result=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(s1.count(mid)==0){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return result;
}
void dfs(vector<bool>&visited,stack<int>&s1,int i,vector< vector<int> >&adj){
    visited[i]=true;
    fr(j,0,adj[i].size()){
        if(!visited[adj[i][j]]){
            dfs(visited,s1,adj[i][j],adj);
        }
    }
    s1.push(i);
}
int get_parent(int i, vector<int> &parent){
    if(parent[i] == i) return i;
    return parent[i] = get_parent(parent[i], parent);   // FIXED compression
}

void union_by_size(vector<int> &parent, vector<int> &size, int pu, int pv){
    if(size[pu] >= size[pv]){
        size[pu] += size[pv];
        parent[pv] = pu;
    } else {
        size[pv] += size[pu];
        parent[pu] = pv;
    }
}
int get_child(vector<vector<int> >&adj,int i,vector<int>&ans,vector<bool>&vis){
    vis[i]=1;
    int x=0;
    for(int j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j]]){
            x+=(1+get_child(adj,adj[i][j],ans,vis));
        }
    }
    return ans[i]=x;
}
void spiral(vector<vector<int> >&adj,int r,int c,int l,int &val){
    int n=adj.size();
    if(l==0){
        return;
    }
    int r1=r,c1=c,r2=n-1-r,c2=n-1-c;
    for(int i=c1;i<=c2;i++){
        adj[r1][i]=val--;
    }
    r1++;
    for(int i=r1;i<=r2;i++){
        adj[i][c2]=val--;
    }
    c2--;
    for(int i=c2;i>=c1;i--){
        adj[r2][i]=val--;
    }
    r2--;
    for(int i=r2;i>=r1;i--){
        adj[i][c1]=val--;
    }
    return spiral(adj,r+1,c+1,l-1,val);
}
vector<bool>prime_no(1e7+10,true);
vector<int>lowest_pf(1e7+10);
void seive(){
    prime_no[2]=true;
    for(int i=2;i<prime_no.size();i++){
        if(prime_no[i]){
            lowest_pf[i]=1;
            for(int j=2*i;j<prime_no.size();j+=i){
                prime_no[j]=false;
                lowest_pf[j]+=1;//counting the number of distinct prime numbers that are devidding the number i ie these are the number of prime factors of the number 
            }
        }
    }
}
void pre_co(){
    for(int i=3;i<1e7+10;i++){
        lowest_pf[i]=lowest_pf[i-1]+lowest_pf[i];//this uses 
    }
}
int min_bi(int l1,int r1,int l2,int r2,int64_t p){
    int low = l1, high = r1, ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        int64_t prod = (int64_t)mid * p;
        if(prod >= l2 && prod <= r2){
            ans = mid;
            high = mid - 1;
        }
        else if(prod < l2){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
void LIS(){
    int n;
    cin>>n;
    int arr[n];
    vector<int>insertat,print;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>lis;
    for(int i=0;i<n;i++){
        auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
        if(it==lis.end()){
            lis.push_back(arr[i]);
            insertat[i]=lis.size();
        }
        else{
            *it=arr[i];
            insertat[i]=it-lis.begin()+1;
        }
        cout<<i<<" "<<": ";
        for(auto x:lis){
            cout<<x<<","<<" ";
        }
        cout<<"\n";
    }
    cout<<lis.size()<<"\n";
    int curlen=lis.size();
    for(int i=n-1;i>=0;i--){
        if(insertat[i]==curlen){
            print.push_back(arr[curlen]);
            curlen--;
        }
    }
    reverse(print.begin(),print.end());
    for(auto it:print){
        cout<<it<<" ";
    }
    cout<<"\n";
    return;
}
int max_bi(int l1,int r1,int l2,int r2,int64_t p){
    int low = l1, high = r1, ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        int64_t prod = (int64_t)mid * p;
        if(prod >= l2 && prod <= r2){
            ans = mid;
            low = mid + 1;
        }
        else if(prod < l2){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
int count_occ(string &t,string &p){
    int count=0;
    int start=0;
    while((start=p.find(t,start))!=p.npos){
        count++;
        start++;
    }
    return count;
}
int nth_root(int n,int pro){
    //can also be calculated using the prime factor as a number can always be decomposed into prime numbers so if all the prime number have power divisble by n then there is an intiger nth root exist of the number 
    int low=1,high=pro;
    while(low<=high){
        int mid=low+(high-low)/2,x=get_pow(mid,n);
        if(x==pro){
            return mid;
        }
        else if(x>pro){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
vector<int>get_factor(int x){
    vector<int>f;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            f.push_back(i);
            if(x/i!=i ){
                f.push_back(x/i);
            }
        }
    }
    return f;
}
int mod_art_mul(int a,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}
int np2(int x){
    int ans=1;
    for(int i=2;i<=x;i++){
        ans=mod_art_mul(ans,i);
    }
    return ans;
}
bool check(int mid,int x,int k){
    int sum;
    if(mid<=k){
        sum=(mid*(mid+1))/2;
    }
    else{
        int t=2*k-mid;
        sum=(k*(k+1))/2+((k-1)*k)/2-((t-1)*(t))/2;
    }
    return sum<x;
}
map<int,int>mp;
void prex(){
    for(int i=0;i<30;i++){
        mp[1<<i]=i;
    }
}
int dp[100100][5];
int rec(int i,int seen,string t,int &n){
    if(seen==t.size()){
        return 0;
    }
    if(i==n){
        return 1;
    }
    else if(dp[i][seen]!=-1){
        return dp[i][seen];
    } 
    int ans=rec(i+1,seen+1,t,n)+rec(i+1,0,t,n);
    return dp[i][seen]=ans;
}
void dfs(int i,vector<vector<int> >&adj,bool flag,int &ans,vector<bool>&vis){
    if(vis[i]){
        return;
    }
    vis[i]=true;
    if(flag){
        ans++;
    }
    for(int j=0;j<adj[i].size();j++){
        dfs(adj[i][j],adj,!flag,ans,vis);
    }
}
vector<vector<int> >dp1(200005,vector<int>(27,-1)),parent(200005,vector<int>(27,-1));
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>pre(n+1,0),suf(n+1,0),suf2(n+1,0);
    for(int i=1;i<=n;i++){
        if(s[i-1]=='('){
            pre[i]=pre[i-1]+1;
        }
        else{
            pre[i]=pre[i-1];
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]==')'){
            suf[i]=suf[i+1]+1;
        }
        else{
            suf[i]=suf[i+1];
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]==')'){
            suf[i]=suf[i+1]+1;
        }
        else{
            suf[i]=suf[i+1];
        }
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        if(s[i]==')' && pre[i]+1<=suf[i]-1){
            ans=max(ans,2*(suf[i]-1));
        }
    }
    cout<<ans<<"\n";
    return;
    //2^x+2^x=2^x+1
    //
    //1 2 7 4 9 6
    //9 9 9 9 9 6
    //10/5=2 2 3 2 3 
    //
    //p.s
    //3 3 3 3 1 1 4 2 1
    //1 2 3 4 5 6 7 8 9
    //1 1 2 2.2 2 2 2 3
    //3 1 4 2
    //2 6 3 6== 010 110 011 110
    //3 4 7 1== 011 100 111 001
    //1 4 6 1== 01 100 110 001
    //3 2 3 7== 011 010 011.  111
    //20 11 1 7 7 0==10100  01011 00001 00111 00111 00000
    //14 8 3 6 17 6==01110. 01000 00011 00110 10001 00110
    //a1 ,a2,a3,a4
    //a2-a1+a3-a2+a4-a3=a4-a1
    //1:count
    //2:count
    //4:count
    //5:count
    // x%k=k*n+p=p p<k 
    //8 3 4 5 6 7
    
    
    //even toh 2 se 0 
    //a0,a1,a2..an-1
    //
    //2 rem=0,1 if both odd and even are present so if even one odd is present then the ans=2
    //else
    //3 2 5 6 4 1
    //0->3
    //1->2
    //2->1

}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
    //3 4 5 2 1
    //1 2 3 4 5
    //1 2 3 4 5=0
    //5 4 3 2 1=12
    //2 1 3 4 5=2
    //3 2 1 4 5=4
    //4 2 3 1 5=6
    //5 2 3 4 1=8
    //5 3 2 4 1=10
    //1 2 3 4=0
    //4 3 2 1=8
    //2 1 3 4=2
    //3 2 1 4=4
    //4 2 3 1=6

}
/*
    problem:-2117E for stress testing
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    map<int,int>a1;
    map<int,int>b1;
    fr(i,0,n){
        cin>>a[i];
        a1[a[i]]=i;
    }
    fr(i,0,n){
        cin>>b[i];
        b1[b[i]]=i;
    }
    int ans=0;
    fr(i,0,n-1){ 
        if(a[i]==a[i+1] || b[i]==b[i+1] || a[i]==b[i]){
            ans=max(ans,i+1);
        }
    }
    for(auto it:a1){
        auto it2=b1.find(it.first);
        if(it2!=b1.end() && abs(it.second-it2->second)!=1){
            ans=max(ans,min(it.second,it2->second)+1);
        }
    }
    cout<<ans<<"\n";\ouwqo987u60[ vcv cx hgo9]
    */