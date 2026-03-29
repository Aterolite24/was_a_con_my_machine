#include<bits/stdc++.h>
using namespace std;
void gen(int n,string cur,int o,int c,vector<string>&all){
    if((int)cur.size()==n){all.push_back(cur);return;}
    if(o<n/2)gen(n,cur+"(",o+1,c,all);if(c<o)gen(n,cur+")",o,c+1,all);
}
vector<int> leafDepths(const string& s){
    vector<int>d;int depth=0;
    for(int i=0;i<(int)s.size()-1;i++){
        if(s[i]=='(')depth++;if(s[i]=='('&&s[i+1]==')')d.push_back(depth);if(s[i]==')')depth--;
    }
    sort(d.begin(),d.end());return d;
}
// Number of internal nodes of each degree
map<int,int> degreeProfile(const string& s){
    // Build tree
    stack<int>st;vector<int>parent(s.size()/2,-1);vector<int>nchildren(s.size()/2,0);
    int id=0;
    vector<int>ids;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='('){int cur=id++;if(!st.empty()){parent[cur]=st.top();nchildren[st.top()]++;}st.push(cur);}
        else st.pop();
    }
    map<int,int>prof;
    for(int i=0;i<id;i++)prof[nchildren[i]]++;
    return prof;
}
int main(){
    int n=12;
    vector<string>all;gen(n,"",0,0,all);
    int N=all.size();
    map<string,int> idx;
    for(int i=0;i<N;i++) idx[all[i]]=i;
    vector<int> comp(N,-1);int nc=0;
    for(int start=0;start<N;start++){
        if(comp[start]!=-1)continue;
        queue<int>q;q.push(start);comp[start]=nc;
        while(!q.empty()){
            int si=q.front();q.pop();string& b=all[si];int m=b.size();
            for(int l1=0;l1<m;l1++){int d=0;for(int r1=l1;r1<m;r1++){
                if(b[r1]=='(')d++;else d--;if(d<0)break;
                if(d==0&&r1>l1){for(int l2=r1+1;l2<m;l2++){int d2=0;for(int r2=l2;r2<m;r2++){
                    if(b[r2]=='(')d2++;else d2--;if(d2<0)break;
                    if(d2==0&&r2>l2){
                        string s1=b.substr(l1,r1-l1+1),s2=b.substr(l2,r2-l2+1);
                        string res=b.substr(0,l1)+s2+b.substr(r1+1,l2-r1-1)+s1+b.substr(r2+1);
                        int ri=idx[res];if(comp[ri]==-1){comp[ri]=nc;q.push(ri);}
                    }
                }}}
            }}
        }
        nc++;
    }
    // Print conflicting classes
    map<vector<int>,vector<vector<int>>> ldToClasses; // ld -> list of class members
    for(int i=0;i<N;i++) ldToClasses[leafDepths(all[i])].push_back({comp[i],i});
    for(auto&[ld,entries]:ldToClasses){
        set<int> cls;for(auto&e:entries)cls.insert(e[0]);
        if(cls.size()>1){
            cout<<"CONFLICT ld=[";for(int i=0;i<(int)ld.size();i++){if(i)cout<<",";cout<<ld[i];}cout<<"]:"<<endl;
            for(int c:cls){
                cout<<"  Class "<<c<<":";
                for(auto&e:entries)if(e[0]==c){
                    auto dp=degreeProfile(all[e[1]]);
                    cout<<" "<<all[e[1]]<<"(deg={";
                    for(auto&[k,v]:dp)cout<<k<<":"<<v<<",";
                    cout<<"})";
                }
                cout<<endl;
            }
        }
    }
}
