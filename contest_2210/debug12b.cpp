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
// For each pair, compute depths of leaves in its subtree
struct Node{int l,r,depth;vector<int> children;};
vector<Node> buildTree(const string& s){
    vector<Node> nodes;
    stack<int> st;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='('){
            int id=nodes.size();
            nodes.push_back({i,-1,(int)st.size()+1,{}});
            if(!st.empty()) nodes[st.top()].children.push_back(id);
            st.push(id);
        } else {
            nodes[st.top()].r=i;st.pop();
        }
    }
    return nodes;
}
// Compute a hash/canonical form that captures the tree structure
// Try: for each node, compute sorted multiset of children's canonical forms
map<vector<int>,int> canon_map;
int next_id=0;
int canonize(vector<Node>& nodes, int id){
    vector<int> child_canons;
    for(int c:nodes[id].children) child_canons.push_back(canonize(nodes,c));
    sort(child_canons.begin(),child_canons.end());
    if(!canon_map.count(child_canons)){canon_map[child_canons]=next_id++;}
    return canon_map[child_canons];
}
// Full canonical: sorted list of top-level tree canons
vector<int> fullCanon(const string& s){
    auto nodes=buildTree(s);
    vector<int> tops;
    // Find top-level nodes (those at depth 1)
    for(int i=0;i<(int)nodes.size();i++) if(nodes[i].depth==1) tops.push_back(canonize(nodes,i));
    sort(tops.begin(),tops.end());
    return tops;
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
    // Print the conflicting classes (leaf depths [2,3,3])
    auto ld=[&](const string& s)->vector<int>{
        vector<int>d;int depth=0;
        for(int i=0;i<(int)s.size()-1;i++){
            if(s[i]=='(')depth++;if(s[i]=='('&&s[i+1]==')')d.push_back(depth);if(s[i]==')')depth--;
        }
        sort(d.begin(),d.end());return d;
    };
    for(int ci=0;ci<nc;ci++){
        auto depths=ld(classes[ci][0]);
        if(depths==vector<int>({2,3,3})){
            cout<<"Class "<<ci<<" (size="<<classes[ci].size()<<"): members=";
            int cnt=0;
            for(auto&s:classes[ci]){
                auto fc=fullCanon(s);
                cout<<s<<"[canon=";for(int i=0;i<(int)fc.size();i++){if(i)cout<<",";cout<<fc[i];}
                cout<<"] ";
                if(++cnt>=5){cout<<"...";break;}
            }
            cout<<endl;
        }
    }
}
