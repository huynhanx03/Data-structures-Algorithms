/*
 Problem: 4181. Minimum Edge Toggles on a Tree
 Language: cpp
 Runtime: 282 ms (63.13%)
 Memory: 309.8 MB (73.74%)
 Tags: Tree, Depth-First Search, Graph Theory, Topological Sort, Sorting
*/
class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({edges[i][1], i});
            adj[edges[i][1]].push_back({edges[i][0], i});
        }

        vector <int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = (start[i] != target[i] ? 1 : 0);
        }

        vector <int> res;

        auto dfs = [&](auto&& self, int u, int p) -> void {
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int idx = edge.second;

                if (v == p) continue;
                self(self, v, u);
                if (diff[v] == 1) {
                    res.push_back(idx);
                    diff[u] ^= 1;
                }
            }
        };

        dfs(dfs, 0, -1);

        if (diff[0] == 1) {
            return {-1};
        }

        sort(res.begin(), res.end());
        return res;
    }
};