/*
 Problem: 1834. Minimum Number of People to Teach
 Language: cpp
 Runtime: 231 ms (48.84%)
 Memory: 152.9 MB (33.72%)
 Tags: Array, Hash Table, Greedy
*/
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> knows(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) knows[i].insert(lang);
        }
        vector<pair<int,int>> conflicts;
        for (auto &fr : friendships) {
            int u = fr[0] - 1, v = fr[1] - 1;
            bool ok = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) conflicts.push_back({u,v});
        }
        if (conflicts.empty()) return 0;
        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            unordered_set<int> needTeach;
            for (auto &p : conflicts) {
                if (!knows[p.first].count(lang)) needTeach.insert(p.first);
                if (!knows[p.second].count(lang)) needTeach.insert(p.second);
            }
            ans = min(ans, (int)needTeach.size());
        }
        return ans;
    }
};
