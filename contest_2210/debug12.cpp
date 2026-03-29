#include<bits/stdc++.h>
using namespace std;
bool isRBS(const string& s){int d=0;for(char c:s){if(c=='(')d++;else{d--;if(d<0)return false;}}return d==0;}
set<string> bfs(string start){
    set<string> vis;queue<string> q;vis.insert(start);q.push(start);
    while(!q.empty()){
        string b=q.front();q.pop();int m=b.size();
        for(int l1=0;l1<m;l1++)for(int r1=l1+1;r1<m;r1++){
            if(!isRBS(b.substr(l1,r1-l1+1)))continue;
            for(int l2=r1+1;l2<m;l2++)for(int r2=l2+1;r2<=m-1;r2++){
                if(!isRBS(b.substr(l2,r2-l2+1)))continue;
                string s1=b.substr(l1,r1-l1+1),s2=b.substr(l2,r2-l2+1);
                string res=b.substr(0,l1)+s2+b.substr(r1+1,l2-r1-1)+s1+b.substr(r2+1);
                if(!vis.count(res)){vis.insert(res);q.push(res);}
            }
        }
    }
    return vis;
}
vector<int> leafDepths(const string& s){
    vector<int>d;int depth=0;
    for(int i=0;i<(int)s.size()-1;i++){
        if(s[i]=='(')depth++;if(s[i]=='('&&s[i+1]==')')d.push_back(depth);if(s[i]==')')depth--;
    }
    sort(d.begin(),d.end());return d;
}
// Tree signature: recursively build sorted children
string treeSig(const string& s, int& pos){
    pos++;vector<string>ch;
    while(pos<(int)s.size()&&s[pos]=='(')ch.push_back(treeSig(s,pos));
    pos++;sort(ch.begin(),ch.end());
    string r="(";for(auto&c:ch)r+=c;r+=")";return r;
}
string fullTreeSig(const string& s){
    int pos=0;vector<string>tops;
    while(pos<(int)s.size())tops.push_back(treeSig(s,pos));
    sort(tops.begin(),tops.end());string r;for(auto&t:tops)r+=t;return r;
}
void gen(int n,string cur,int o,int c,vector<string>&all){
    if((int)cur.size()==n){all.push_back(cur);return;}
    if(o<n/2)gen(n,cur+"(",o+1,c,all);if(c<o)gen(n,cur+")",o,c+1,all);
}
int main(){
    int n=12;
    vector<string>all;gen(n,"",0,0,all);
    map<string,int>cid;int nc=0;
    vector<vector<string>>classes;
    for(auto&s:all){
        if(cid.count(s))continue;
        auto reached=bfs(s);
        vector<string>cls(reached.begin(),reached.end());
        for(auto&r:reached)cid[r]=nc;
        classes.push_back(cls);nc++;
    }
    // Find the conflict: classes with leafDepths [2,3,3]
    for(int ci=0;ci<nc;ci++){
        auto ld=leafDepths(classes[ci][0]);
        if(ld==vector<int>({2,3,3})){
            cout<<"Class "<<ci<<" (size="<<classes[ci].size()<<"):";
            for(auto&s:classes[ci])cout<<" "<<s<<"[ts="<<fullTreeSig(s)<<"]";
            cout<<endl;
        }
    }
}
