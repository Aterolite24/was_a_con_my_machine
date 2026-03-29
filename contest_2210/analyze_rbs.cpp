#include<bits/stdc++.h>
using namespace std;
// For each RBS, compute the number of () at each nesting depth
// and see if the SORTED multiset of leaf counts per depth is the invariant
vector<int> leafDepths(const string& s){
    vector<int> depths;
    int d=0;
    for(int i=0;i<(int)s.size()-1;i++){
        if(s[i]=='(') d++;
        if(s[i]=='(' && s[i+1]==')'){
            depths.push_back(d);
        }
        if(s[i]==')') d--;
    }
    sort(depths.begin(),depths.end());
    return depths;
}

// Count leaves
int countLeaves(const string& s){
    int c=0;
    for(int i=0;i<(int)s.size()-1;i++)
        if(s[i]=='(' && s[i+1]==')') c++;
    return c;
}

// Try: recursive tree signature (unordered)
string treeSignature(const string& s, int& pos){
    // s[pos] should be '('
    pos++; // skip '('
    vector<string> children;
    while(s[pos]=='('){
        children.push_back(treeSignature(s,pos));
    }
    pos++; // skip ')'
    sort(children.begin(),children.end());
    string res="(";
    for(auto&c:children) res+=c;
    res+=")";
    return res;
}

// Full tree sig for a sequence of top-level groups
string fullSig(const string& s){
    int pos=0;
    vector<string> tops;
    while(pos<(int)s.size()){
        tops.push_back(treeSignature(s,pos));
    }
    sort(tops.begin(),tops.end());
    string res;
    for(auto&t:tops) res+=t;
    return res;
}

void gen(int n,string cur,int o,int c,vector<string>&all){
    if((int)cur.size()==n){all.push_back(cur);return;}
    if(o<n/2)gen(n,cur+"(",o+1,c,all);
    if(c<o)gen(n,cur+")",o,c+1,all);
}

int main(){
    // For each class, print the signatures
    for(int n=4;n<=10;n+=2){
        vector<string>all;gen(n,"",0,0,all);
        cout<<"n="<<n<<endl;
        // Group by leaf count
        map<int,vector<string>> byLeaves;
        for(auto&s:all) byLeaves[countLeaves(s)].push_back(s);
        for(auto&[lc,strs]:byLeaves){
            cout<<"  leaves="<<lc<<":";
            for(auto&s:strs){
                auto ld=leafDepths(s);
                string ldstr="[";
                for(int i=0;i<(int)ld.size();i++){
                    if(i)ldstr+=",";
                    ldstr+=to_string(ld[i]);
                }
                ldstr+="]";
                cout<<" "<<s<<"(ld="<<ldstr<<",sig="<<fullSig(s)<<")";
            }
            cout<<endl;
        }
    }
}
