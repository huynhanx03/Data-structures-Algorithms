/*
 Problem: 4072. Total Sum of Interaction Cost in Tree Groups
 Language: cpp
 Runtime: 1253 ms (17.55%)
 Memory: 448.5 MB (51.58%)
 Tags: Array, Tree, Depth-First Search
*/
class Solution {
private:
    vector<vector<int>> adj;
    vector <int> group_count;
    vector <int> group;
    long long ans = 0;
    
    map<int, int> dfs(int u, int p) {
        map<int, int> mp;

        mp[group[u]] = 1;

        for (const auto& v : adj[u]) {
            if (v == p) continue;

            map<int, int> child = dfs(v, u);

            for (const auto& [g, cnt] : child) {
                long long cnt_in = cnt;
                long long cnt_out = group_count[g] - cnt_in;
                ans += cnt_in * cnt_out;
            }

            if (child.size() > mp.size()) {
                swap(mp, child);
            }

            for (const auto& [g, cnt] : child) {
                mp[g] += cnt;
            }
        }

        return mp;
    }
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        adj.assign(n, vector<int>());
        this->group = group;
        
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        group_count.assign(25, 0);
        for (const auto& g : group) ++group_count[g];

        dfs(0, -1);

        return ans;
    }
};