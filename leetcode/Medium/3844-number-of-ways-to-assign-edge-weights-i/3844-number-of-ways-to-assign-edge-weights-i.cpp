/*
 Problem: 3844. Number of Ways to Assign Edge Weights I
 Language: cpp
 Runtime: 267 ms (87.12%)
 Memory: 332.9 MB (54.15%)
 Tags: Math, Tree, Depth-First Search
*/
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;
        vector<vector<int>> graph(n + 1);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int maxDepth = 0;

        auto dfs = [&](this auto&& dfs, int node, int parent, int depth) -> void {
            maxDepth = max(maxDepth, depth);

            for (int nextNode : graph[node]) {
                if (nextNode != parent) {
                    dfs(nextNode, node, depth + 1);
                }
            }
        };

        dfs(1, 0, 0);

        auto pow = [&](long long x, int n) {
            long long result = 1;

            while (n > 0) {
                if (n & 1) {
                    result = result * x % MOD;
                }

                x = x * x % MOD;
                n >>= 1;
            }

            return result;
        };

        return pow(2, maxDepth - 1);
    }
};