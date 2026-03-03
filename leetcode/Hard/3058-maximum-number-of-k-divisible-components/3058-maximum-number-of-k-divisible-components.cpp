/*
 Problem: 3058. Maximum Number of K-Divisible Components
 Language: cpp
 Runtime: 110 ms (64.85%)
 Memory: 172.8 MB (94.54%)
 Tags: Tree, Depth-First Search
*/
class Solution {
public:
    vector<vector<int>> adj;
    long long K;
    int components;

    long long dfs(int u, int parent, const vector<int>& values) {
        long long sum = values[u];
        for (int v : adj[u]) {
            if (v == parent) continue;
            sum += dfs(v, u, values);
        }
        if (sum % K == 0) {
            components++;
            return 0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        K = k;
        components = 0;
        adj.assign(n, vector<int>());

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, values);
        return components;
    }
};
