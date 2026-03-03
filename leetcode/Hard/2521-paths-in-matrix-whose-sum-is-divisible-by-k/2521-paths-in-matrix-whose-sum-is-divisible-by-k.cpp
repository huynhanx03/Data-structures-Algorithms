/*
 Problem: 2521. Paths in Matrix Whose Sum Is Divisible by K
 Language: cpp
 Runtime: 224 ms (65.03%)
 Memory: 132.1 MB (63.25%)
 Tags: Array, Dynamic Programming, Matrix
*/
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][r] = số cách đến (i,j) với tổng % k = r
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j] % k;

                if (i == 0 && j == 0) continue;

                for (int r = 0; r < k; r++) {
                    int prev = (r - val + k) % k;

                    if (i > 0)
                        dp[i][j][r] = (dp[i][j][r] + dp[i-1][j][prev]) % MOD;

                    if (j > 0)
                        dp[i][j][r] = (dp[i][j][r] + dp[i][j-1][prev]) % MOD;
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};