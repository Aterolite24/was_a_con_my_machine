#include<bits/stdc++.h>
using namespace std;
bool isRBS(const string& s){
    int d=0;
    for(char c:s){if(c=='(') d++; else{d--;if(d<0)return false;}}
    return d==0;
}
set<string> bfs(string start){
    set<string> visited;
    queue<string> q;
    visited.insert(start); q.push(start);
    while(!q.empty()){
        string b=q.front();q.pop();
        int m=b.size();
        for(int l1=0;l1<m;l1++)
        for(int r1=l1+1;r1<m;r1++){
            if(!isRBS(b.substr(l1,r1-l1+1)))continue;
            for(int l2=r1+1;l2<m;l2++)
            for(int r2=l2+1;r2<=m-1;r2++){
                if(!isRBS(b.substr(l2,r2-l2+1)))continue;
                string s1=b.substr(l1,r1-l1+1),s2=b.substr(l2,r2-l2+1);
                string res=b.substr(0,l1)+s2+b.substr(r1+1,l2-r1-1)+s1+b.substr(r2+1);
                if(!visited.count(res)){visited.insert(res);q.push(res);}
            }
        }
    }
    return visited;
}
void gen(int n,string cur,int o,int c,vector<string>&all){
    if((int)cur.size()==n){all.push_back(cur);return;}
    if(o<n/2)gen(n,cur+"(",o+1,c,all);
    if(c<o)gen(n,cur+")",o,c+1,all);
}
int main(){
    for(int n=4;n<=10;n+=2){
        vector<string>all;gen(n,"",0,0,all);
        map<string,int>cid;int nc=0;
        cout<<"n="<<n<<" total="<<all.size()<<endl;
        vector<vector<string>>cls;
        for(auto&s:all){
            if(cid.count(s))continue;
            auto reached=bfs(s);
            for(auto&r:reached)cid[r]=nc;
            cls.push_back(vector<string>(reached.begin(),reached.end()));
            nc++;
        }
        cout<<"  classes="<<nc<<endl;
        for(int i=0;i<nc;i++){
            cout<<"  class "<<i<<":";
            for(auto&s:cls[i])cout<<" "<<s;
            cout<<endl;
        }
    }
}
