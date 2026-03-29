#include<bits/stdc++.h>
using namespace std;
// Faster BFS using bit representation
// For n=12, there are 132 Catalan(6) RBS strings
// Use adjacency to build reachability

bool isRBS(const string& s,int l,int r){
    int d=0;
    for(int i=l;i<=r;i++){if(s[i]=='(')d++;else{d--;if(d<0)return false;}}
    return d==0;
}
void gen(int n,string cur,int o,int c,vector<string>&all){
    if((int)cur.size()==n){all.push_back(cur);return;}
    if(o<n/2)gen(n,cur+"(",o+1,c,all);if(c<o)gen(n,cur+")",o,c+1,all);
}
int main(){
    int n=12;
    vector<string>all;gen(n,"",0,0,all);
    map<string,int> idx;
    for(int i=0;i<(int)all.size();i++) idx[all[i]]=i;
    int N=all.size();
    // Union-Find
    vector<int> par(N);iota(par.begin(),par.end(),0);
    function<int(int)> find=[&](int x)->int{return par[x]==x?x:par[x]=find(par[x]);};
    auto unite=[&](int a,int b){par[find(a)]=find(b);};
    
    // For each string, try all swaps and unite
    for(int si=0;si<N;si++){
        string& b=all[si];
        int m=b.size();
        // Precompute valid RBS ranges
        vector<vector<bool>> valid(m,vector<bool>(m,false));
        for(int l=0;l<m;l++){
            int d=0;
            for(int r=l;r<m;r++){
                if(b[r]=='(')d++;else d--;
                if(d<0)break;
                if(d==0&&r>l) valid[l][r]=true;
            }
        }
        for(int l1=0;l1<m;l1++)for(int r1=l1+1;r1<m;r1++){
            if(!valid[l1][r1])continue;
            for(int l2=r1+1;l2<m;l2++)for(int r2=l2+1;r2<m;r2++){
                if(!valid[l2][r2])continue;
                string s1=b.substr(l1,r1-l1+1),s2=b.substr(l2,r2-l2+1);
                string res=b.substr(0,l1)+s2+b.substr(r1+1,l2-r1-1)+s1+b.substr(r2+1);
                if(idx.count(res)) unite(si,idx[res]);
            }
        }
    }
    // BFS/transitive closure through union-find is already handled
    // But union-find only captures direct swaps, not transitive chains
    // Need to iterate until convergence
    bool changed=true;
    while(changed){
        changed=false;
        for(int si=0;si<N;si++){
            string& b=all[si];int m=b.size();
            vector<vector<bool>> valid(m,vector<bool>(m,false));
            for(int l=0;l<m;l++){int d=0;for(int r=l;r<m;r++){if(b[r]=='(')d++;else d--;if(d<0)break;if(d==0&&r>l)valid[l][r]=true;}}
            for(int l1=0;l1<m;l1++)for(int r1=l1+1;r1<m;r1++){
                if(!valid[l1][r1])continue;
                for(int l2=r1+1;l2<m;l2++)for(int r2=l2+1;r2<m;r2++){
                    if(!valid[l2][r2])continue;
                    string s1=b.substr(l1,r1-l1+1),s2=b.substr(l2,r2-l2+1);
                    string res=b.substr(0,l1)+s2+b.substr(r1+1,l2-r1-1)+s1+b.substr(r2+1);
                    if(idx.count(res)){
                        int a=find(si),bb=find(idx[res]);
                        if(a!=bb){unite(si,idx[res]);changed=true;}
                    }
                }
            }
        }
    }
    // Actually union-find + direct edges IS correct for transitive closure
    // since we process all strings. But we need to also process newly discovered equivalences...
    // Actually the issue is we only process each string's direct neighbors.
    // For transitive closure we need BFS from each component.
    // Let's just use BFS but faster.
    
    // Reset and do proper BFS
    map<int,set<int>> groups;
    for(int i=0;i<N;i++) groups[find(i)].insert(i);
    
    // print
    int nc=groups.size();
    cout<<"n="<<n<<" total="<<N<<" classes="<<nc<<endl;
    
    // For each class, compute leaf depths
    auto ld=[&](const string& s)->vector<int>{
        vector<int>d;int depth=0;
        for(int i=0;i<(int)s.size()-1;i++){
            if(s[i]=='(')depth++;if(s[i]=='('&&s[i+1]==')')d.push_back(depth);if(s[i]==')')depth--;
        }
        sort(d.begin(),d.end());return d;
    };
    
    map<vector<int>,set<int>> ldToClasses;
    for(auto&[rep,members]:groups){
        auto depths=ld(all[*members.begin()]);
        ldToClasses[depths].insert(rep);
    }
    for(auto&[depths,reps]:ldToClasses){
        if(reps.size()>1){
            cout<<"CONFLICT ld=[";
            for(int i=0;i<(int)depths.size();i++){if(i)cout<<",";cout<<depths[i];}
            cout<<"]: "<<reps.size()<<" classes"<<endl;
            for(int r:reps){
                auto& m=groups[r];
                cout<<"  class(size="<<m.size()<<"): ";
                int cnt=0;
                for(int i:m){cout<<all[i]<<" ";if(++cnt>=3){cout<<"...";break;}}
                cout<<endl;
            }
        }
    }
}
