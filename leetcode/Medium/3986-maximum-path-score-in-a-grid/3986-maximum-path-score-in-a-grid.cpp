/*
 Problem: 3986. Maximum Path Score in a Grid
 Language: cpp
 Runtime: 1078 ms (21.64%)
 Memory: 499.6 MB (31.49%)
 Tags: Array, Dynamic Programming, Matrix
*/
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

        auto getCost = [&](int v) { return (v == 0 ? 0 : 1); };
        
        int startCost = getCost(grid[0][0]);

        if (startCost <= k) {
            dp[0][0][startCost] = grid[0][0];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cost = getCost(grid[i][j]);

                for (int c = cost; c <= k; ++c) {
                    int bestPrev = -1;

                    if (i > 0 && dp[i - 1][j][c - cost] != -1) {
                        bestPrev = max(bestPrev, dp[i - 1][j][c - cost]);
                    }

                    if (j > 0 && dp[i][j - 1][c - cost] != -1) {
                        bestPrev = max(bestPrev, dp[i][j - 1][c - cost]);
                    }

                    if (bestPrev != -1) {
                        dp[i][j][c] = max(dp[i][j][c], bestPrev + grid[i][j]);
                    }
                }
            }
        }

        int ans = -1;

        for (int c = 0; c <= k; ++c) {
            ans = max(ans, dp[n - 1][m - 1][c]);
        }

        return ans;
    }
};