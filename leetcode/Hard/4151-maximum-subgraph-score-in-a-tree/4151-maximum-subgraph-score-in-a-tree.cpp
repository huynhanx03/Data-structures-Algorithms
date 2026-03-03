/*
 Problem: 4151. Maximum Subgraph Score in a Tree
 Language: cpp
 Runtime: 273 ms (85.92%)
 Memory: 390.2 MB (39.94%)
 Tags: Array, Dynamic Programming, Tree, Depth-First Search
*/
class Solution {
private:
    vector<vector<int>> g;
    vector<int> val, dp, ans;

    void dfs1(int u, int p) {
        dp[u] = val[u];
        for (const auto& v : g[u]) {
            if (v == p) continue;
            dfs1(v, u);
            dp[u] += max(0, dp[v]);
        }
    }

    void dfs2(int u, int p, int vp) {
        ans[u] = dp[u] + max(0, vp);
        for (const auto& v : g[u]) {
            if (v == p) continue;
            int wv = ans[u] - max(0, dp[v]);
            dfs2(v, u, wv);
        }
    }

public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        g.assign(n, {});
        val.resize(n);
        dp.resize(n);
        ans.resize(n);
    
        for (const auto&e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; ++i) {
            val[i] = (good[i] == 1 ? 1 : -1);
        }

        dfs1(0, -1);
        dfs2(0, -1, 0);
        return ans;
    }
};