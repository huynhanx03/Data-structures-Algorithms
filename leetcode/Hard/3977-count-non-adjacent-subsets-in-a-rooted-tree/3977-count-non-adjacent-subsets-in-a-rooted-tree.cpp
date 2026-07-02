/*
 Problem: 3977. Count Non Adjacent Subsets in a Rooted Tree
 Language: cpp
 Runtime: 1914 ms (10.43%)
 Memory: 101.1 MB (38.63%)
 Tags: Array, Dynamic Programming, Tree, Depth-First Search
*/
class Solution {
public:
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = parent.size();

        vector<vector<int>> g(n);

        for (int i = 1; i < n; ++i) g[parent[i]].push_back(i);

        long long MOD = 1e9 + 7;
        auto add = [&](long long& a, long long b) {
            a = (a + b) % MOD;
        };

        // dp
        // 0: node
        // 1: true/false get node
        // 2: %mod
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(k)));

        auto dfs = [&](auto&& self, int u) -> void {
            dp[u][0][0] = 1;
            dp[u][1][nums[u] % k] = 1;

            for (const auto& v : g[u]) {
                self(self, v);

                vector<vector<long long>> ndp(2, vector<long long>(k));

                for (int a = 0; a < k; ++a) {
                    for (int b = 0; b < k; ++b) {
                        long long tmp = (dp[v][0][b] + dp[v][1][b]) % MOD;
                        add(ndp[0][(a + b) % k], dp[u][0][a] * tmp % MOD);
                    }
                }

                for (int a = 0; a < k; ++a) {
                    for (int b = 0; b < k; ++b) {
                        add(ndp[1][(a + b) % k], dp[u][1][a] * dp[v][0][b] % MOD);
                    }
                }

                dp[u] = move(ndp);
            }
        };

        dfs(dfs, 0);

        return (dp[0][0][0] + dp[0][1][0] - 1 + MOD) % MOD;
    }
};