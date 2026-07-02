/*
 Problem: 3842. Number of Ways to Assign Edge Weights II
 Language: cpp
 Runtime: 330 ms (73.65%)
 Memory: 351 MB (90.21%)
 Tags: Array, Math, Dynamic Programming, Bit Manipulation, Tree, Depth-First Search
*/
class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        constexpr int MOD = 1'000'000'007;

        const int n = edges.size() + 1;
        int log = 1;

        while ((1 << log) <= n) {
            ++log;
        }

        vector<vector<int>> graph(n + 1);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> depth(n + 1);
        vector<vector<int>> parent(log, vector<int>(n + 1));

        auto dfs = [&](this auto&& dfs, int node, int prev) -> void {
            parent[0][node] = prev;

            for (int i = 1; i < log; ++i) {
                parent[i][node] = parent[i - 1][parent[i - 1][node]];
            }

            for (const int nextNode : graph[node]) {
                if (nextNode == prev) {
                    continue;
                }

                depth[nextNode] = depth[node] + 1;
                dfs(nextNode, node);
            }
        };

        dfs(1, 0);

        auto getLca = [&](int u, int v) {
            if (depth[u] < depth[v]) {
                swap(u, v);
            }

            int diff = depth[u] - depth[v];

            for (int i = 0; i < log; ++i) {
                if (diff & (1 << i)) {
                    u = parent[i][u];
                }
            }

            if (u == v) {
                return u;
            }

            for (int i = log - 1; i >= 0; --i) {
                if (parent[i][u] != parent[i][v]) {
                    u = parent[i][u];
                    v = parent[i][v];
                }
            }

            return parent[0][u];
        };

        auto modPow = [&](long long base, int exp) {
            long long result = 1;

            while (exp > 0) {
                if (exp & 1) {
                    result = result * base % MOD;
                }

                base = base * base % MOD;
                exp >>= 1;
            }

            return static_cast<int>(result);
        };

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            const int u = query[0];
            const int v = query[1];
            const int ancestor = getLca(u, v);
            const int pathLength = depth[u] + depth[v] - 2 * depth[ancestor];

            answer.push_back(pathLength == 0 ? 0 : modPow(2, pathLength - 1));
        }

        return answer;
    }
};