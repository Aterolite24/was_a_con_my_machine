#include<bits/stdc++.h>
using namespace std;
bool isRBS(const string& s){
    int d=0;for(char c:s){if(c=='(')d++;else{d--;if(d<0)return false;}}return d==0;
}
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
    vector<int> d;int depth=0;
    for(int i=0;i<(int)s.size()-1;i++){
        if(s[i]=='(')depth++;
        if(s[i]=='('&&s[i+1]==')')d.push_back(depth);
        if(s[i]==')')depth--;
    }
    sort(d.begin(),d.end());return d;
}
void gen(int n,string cur,int o,int c,vector<string>&all){
    if((int)cur.size()==n){all.push_back(cur);return;}
    if(o<n/2)gen(n,cur+"(",o+1,c,all);if(c<o)gen(n,cur+")",o,c+1,all);
}
int main(){
    for(int n=4;n<=12;n+=2){
        vector<string>all;gen(n,"",0,0,all);
        // Check: same leafDepths <==> same equivalence class?
        map<string,int>cid;int nc=0;
        for(auto&s:all){
            if(cid.count(s))continue;
            auto reached=bfs(s);
            for(auto&r:reached)cid[r]=nc;nc++;
        }
        // Group by leafDepths
        map<vector<int>,set<int>> ldToClasses;
        for(auto&s:all){
            ldToClasses[leafDepths(s)].insert(cid[s]);
        }
        bool ok=true;
        for(auto&[ld,cls]:ldToClasses){
            if(cls.size()!=1){ok=false;break;}
        }
        cout<<"n="<<n<<" classes="<<nc<<" leafDepths_is_invariant="<<(ok?"YES":"NO")<<endl;
        if(!ok){
            for(auto&[ld,cls]:ldToClasses){
                if(cls.size()>1){
                    cout<<"  CONFLICT ld=[";
                    for(int i=0;i<(int)ld.size();i++){if(i)cout<<",";cout<<ld[i];}
                    cout<<"] maps to classes:";
                    for(int c:cls)cout<<" "<<c;cout<<endl;
                }
            }
        }
    }
}
