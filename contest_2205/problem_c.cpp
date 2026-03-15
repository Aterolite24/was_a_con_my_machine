#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    void solve(){
        int blogCount;
        cin >> blogCount;
        vector<vector<int>> processedBlogs(blogCount);
        for (int i = 0; i < blogCount; i++) {
            int length;
            cin >> length;
            vector<int> blog(length);
            for (int j = 0; j < length; j++) {
                cin >> blog[j];
            }
            reverse(blog.begin(), blog.end());
            unordered_set<int> seenInThisBlog;
            for (int user : blog) {
                if (!seenInThisBlog.count(user)) {
                    processedBlogs[i].push_back(user);
                    seenInThisBlog.insert(user);
                }
            }
        }
        vector<int> finalOrder;              // This will become Q
        unordered_set<int> alreadyChosen;    // Users already fixed in final answer
        for (int step = 0; step < blogCount; step++) {
            for (auto &blog : processedBlogs) {
                vector<int> filtered;
                for (int user : blog) {
                    if (!alreadyChosen.count(user)) {
                        filtered.push_back(user);
                    }
                }
                blog = filtered;
            }
            sort(processedBlogs.begin(), processedBlogs.end());
            for (int user : processedBlogs[0]) {
                finalOrder.push_back(user);
                alreadyChosen.insert(user);
            }
            processedBlogs.erase(processedBlogs.begin());
        }
        for (int i = 0; i < (int)finalOrder.size(); i++) {
            if (i) cout << " ";
            cout << finalOrder[i];
        }
        cout << "\n";
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