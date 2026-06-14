#include <bits/stdc++.h>
using namespace std;

class Solution {
    int tot_dfs;
    struct edge {
        int u, v; 
    };
    
    bool bpm(int u, const vector<vector<int>>& adj, vector<int>& match, vector<bool>& seen) {
        for(int v : adj[u]){
            if(!seen[v]){
                seen[v] = 1;
                if(match[v] < 0 or bpm(match[v], adj, match, seen)){
                    match[v] = u;
                    return 1;
                }
            }
        }
        return 0;
    }
    
    int get_match(const vector<int>& cover, const vector<edge>& ed, int n, int m) {
        vector<bool> in(n + m, 0); 
        for(int x : cover) in[x] = 1;
        vector<vector<int>> adj(n);
        for(auto& e : ed) 
            if(in[e.u] && in[e.v]) adj[e.u].push_back(e.v - n);
        vector<int> match(m, -1); 
        int r = 0;
        for(int j = 0; j < n; j++) 
            if(in[j]){ 
                vector<bool> seen(m, 0); 
                if(bpm(j, adj, match, seen)) r++; 
            }
        return r;
    }

    void dfs(vector<int>& cover, int cov, vector<int>& cov_by, 
             int& best_eds, int edge_sz, int n, int m, 
             const vector<edge>& ed, const vector<vector<int>>& inc) {
        if (tot_dfs++ > 1e6 or (cover.size() + 1) / 2 >= best_eds) return;
        if (cov == edge_sz){
            best_eds = min(best_eds, (int)cover.size() - get_match(cover, ed, n, m));
            return;
        }
        vector<int> deg(n + m, 0);
        for(int j = 0; j < edge_sz; j++) 
            if(!cov_by[j]) { deg[ed[j].u]++; deg[ed[j].v]++; }
        int md = 0, v = -1;
        for(int j = 0; j < n + m; j++) 
            if(deg[j] > md) md = deg[j], v = j;
        if(!md) return;
        
        cover.push_back(v); int nc = cov;
        for(int e : inc[v]) if(cov_by[e]++ == 0) nc++;
        dfs(cover, nc, cov_by, best_eds, edge_sz, n, m, ed, inc);
        for(int e : inc[v]) cov_by[e]--; cover.pop_back();
        
        vector<int> add;
        for(int e : inc[v]) 
            if(!cov_by[e]) add.push_back(ed[e].u == v ? ed[e].v : ed[e].u);
        sort(add.begin(), add.end()); 
        add.erase(unique(add.begin(), add.end()), add.end());
        
        for(int u : add) { 
            cover.push_back(u); 
            for(int e : inc[u]) if(cov_by[e]++ == 0) cov++; 
        }
        dfs(cover, cov, cov_by, best_eds, edge_sz, n, m, ed, inc);
        for(int u : add) { 
            cover.pop_back(); 
            for(int e : inc[u]) cov_by[e]--; 
        }
    }

    int solve_component(int n, int m, const vector<edge>& ed) {
        int edge_sz = ed.size(), best_eds = 0;
        vector<vector<int>> inc(n + m);
        for(int j = 0; j < edge_sz; j++) { 
            inc[ed[j].u].push_back(j); 
            inc[ed[j].v].push_back(j); 
        }
        vector<vector<int>> m_adj(n);
        for(auto& e : ed) m_adj[e.u].push_back(e.v - n);
        vector<int> match(m, -1);
        for(int j = 0; j < n; j++) { 
            vector<bool> seen(m, 0); 
            if (bpm(j, m_adj, match, seen)) best_eds++; 
        }
        
        vector<int> cover, cov_by(edge_sz, 0); 
        dfs(cover, 0, cov_by, best_eds, edge_sz, n, m, ed, inc);
        return best_eds;
    }

public:
    int findMinimumOperations(vector<vector<int>> bookshelf, int k) {
        int n = bookshelf.size(); 
        if(!n) return 0;
        int m = bookshelf[0].size(), ans = 0; 
        tot_dfs = 0;
        
        for (int a = 1; a <= k; a++){
            vector<pair<int,int>> pts;
            for(int r = 0; r < n; r++) 
                for(int c = 0; c < m; c++) 
                    if(bookshelf[r][c] == a) pts.push_back({r, c});
            if (pts.empty()) continue;
            
            int sz = pts.size(); 
            vector<vector<int>> adj(sz);
            for(int i = 0; i < sz; i++) 
                for(int j = i+1; j < sz; j++)
                    if(pts[i].first == pts[j].first or pts[i].second == pts[j].second){ 
                        adj[i].push_back(j); 
                        adj[j].push_back(i); 
                    }
                    
            vector<bool> vis(sz, 0);
            for(int i = 0; i < sz; i++) {
                if(!vis[i]) {
                    vector<edge> ed; 
                    queue<int> q; 
                    q.push(i); 
                    vis[i] = 1;
                    while(!q.empty()){
                        int u = q.front(); q.pop();
                        ed.push_back({pts[u].first, pts[u].second + n});
                        for(int v : adj[u]) 
                            if(!vis[v]){ vis[v] = 1; q.push(v); }
                    }
                    ans += solve_component(n, m, ed);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid1 = {{1,1,2}, {2,2,2}, {1,2,2}};
    cout << "Sample 0: " << sol.findMinimumOperations(grid1, 2) << endl;
    vector<vector<int>> grid2 = {{1,2,3}, {4,5,6}};
    cout << "Sample 1: " << sol.findMinimumOperations(grid2, 6) << endl;
    vector<vector<int>> g(100, vector<int>(100, 1));
    cout << "Performance test complete : " << sol.findMinimumOperations(g, 1) << endl; 
    return 0;
}