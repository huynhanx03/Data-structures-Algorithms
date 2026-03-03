/*
 Problem: 64. Minimum Path Sum
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 16.2 MB (70.15%)
 Tags: Array, Dynamic Programming, Matrix
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 1e9));

        dp[0][0] = grid[0][0];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (i > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                }

                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
                }
            }

        return dp[n - 1][m - 1];
    }
};